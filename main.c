/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: abaza
 *
 * Created on 25 June 2017, 18:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
char LastCharUnicode;
char UnicodeArabic[100];
char* Arabic_Unicode(char* str);

char *Arabic_Unicode(char *Arabix) {
    int Arabic = 0, Unicode = 0, Index = 0;
    memset(&UnicodeArabic, '\0', sizeof (UnicodeArabic));

    const struct {
        char ArabicChar;
        char UnicodeArabic;
        char EngChar;
    } ArabicAlphabet[] = {
        {'ا', '\247', 'h'}, /*ا*/
        {'أ', '\243', 'H'}, /*ا*/
        {'ب', '\250', 'f'}, /*ب*/
        {'ت', '\252', 'j'}, /*ت*/
        {'ث', '\253', 'e'}, /*ث*/
        {'ج', '\254', '['}, /*ج*/
        {'ح', '\255', 'p'}, /*ح*/
        {'خ', '\256', 'o'}, /*خ*/
        {'د', '\257', ']'}, /*د*/
        {'ذ', '\260', '`'}, /*ذ*/
        {'ر', '\261', 'v'}, /*ر*/
        {'ز', '\262', '.'}, /*ز*/
        {'س', '\263', 's'}, /*س*/
        {'ش', '\264', 'a'}, /*ش*/
        {'ص', '\265', 'w'}, /*ص*/
        {'ض', '\266', 'q'}, /*ض*/
        {'ط', '\267', '\''}, /*ط*/
        {'ظ', '\270', '/'}, /*ظ*/
        {'ع', '\271', 'u'}, /*ع*/
        {'غ', '\272', 'y'}, /*غ*/
        {'ف', '\201', 't'}, /*ف*/
        {'ق', '\202', 'r'}, /*ق*/
        {'ك', '\203', ';'}, /*ك*/
        {'ل', '\204', 'g'}, /*ل*/
        {'م', '\205', 'l'}, /*م*/
        {'ن', '\206', 'k'}, /*ن*/
        {'ه', '\207', 'i'}, /*ه*/
        {'ة', '\251', 'm'}, /*ة*/
        {'و', '\210', ','}, /*و*/
        {'ي', '\212', 'd'}, /*ى*/
        {'ء', '\241', 'x'}, /*ء*/
        {'ئ', '\246', 'z'}, /*ئـ*/
        {'آ', '\242', 'B'}, /*آ*/
        {'ى', '\211', 'N'}, /*ى*/
        {'ـ', '\200', 'J'}, /*ـ*/
        {'؟', '\237', '?'}, /*؟*/
    };
    //'+', '-', '@', '#', '$', '%', '(', ')', '=' \302\240
    char Numbers[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };

    for (Arabic = 0; Arabic <= strlen(Arabix) - 1; Arabic++) {

        if (Arabix[Arabic] == -62 && Arabix[Arabic + 1] == -96) {
            UnicodeArabic[Index++] = ' ';
            Arabic++;
            continue;
        }
        if (Arabix[Arabic] == -40 || Arabix[Arabic] == -39) {
            continue;
        }
        if (Arabix[Arabic] == 32) {
            UnicodeArabic[Index++] = ' ';
            continue;
        }
        if (Arabix[Arabic] >= '0' && Arabix[Arabic] <= '9') {
            for (Unicode = 0; Unicode <= sizeof (Numbers) - 1; Unicode++) {
                if (Numbers[Unicode] == Arabix[Arabic]) {
                    UnicodeArabic[Index++] = (int) Numbers[Unicode];
                    break;
                }
            }
        } else {
            for (Unicode = 0; Unicode <= sizeof (ArabicAlphabet) - 1; Unicode++) {
                if (ArabicAlphabet[Unicode].UnicodeArabic == Arabix[Arabic]) {
                    UnicodeArabic[Index++] = (char) ArabicAlphabet[Unicode].EngChar;
                    break;
                }
            }
        }
    }
    UnicodeArabic[Index] = '\0';
    return &UnicodeArabic;
}

int main(int argc, char** argv) {

    printf("\n%s\n", Arabic_Unicode("ا\302\240سيف\302\240أباظة "));
    printf("\n%s\n", Arabic_Unicode("الارقام 1234567890"));

    return (EXIT_SUCCESS);
}

