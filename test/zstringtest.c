/******************************************************************************
* zstringtest.c
* Copyright (c) 2019, Fehmi Noyan ISI fnoyanisi@yahoo.com
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY Fehmi Noyan ISI ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Fehmi Noyan ISI BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unity.h>
#include <zstring.h>

static char *s1;
static char *s2;

void setUp(void){
    char buf1[]="     Free software is a matter of liberty.     ";
    char buf2[]="zString is cool!";
    size_t len1 = strlen(buf1);
    size_t len2 = strlen(buf2);

    s1 = malloc(len1);
    s2 = malloc(len2);

    strncpy(s1, buf1, len1);
    strncpy(s2, buf2, len2);

    s1[len1] = '\0';
    s2[len2] = '\0';
}

void tearDown(void){
    free(s1);
    free(s2);
}

void test_zstrtrm_l(void){
    TEST_ASSERT_EQUAL_STRING("Free software is a matter of liberty.     ",
                            zstrtrm_l(s1));
}

void test_zstrtrm_l_no_change(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!",
                            zstrtrm_l(s2));
}

void test_zstrchr_0(void){
    TEST_ASSERT_EQUAL_INT(-1, zstrchr(s1, 'x'));
}

void test_zstrchr_1(void){
    TEST_ASSERT_EQUAL_INT(1, zstrchr(s2, 'S'));
}

void test_zrmvchr(void){
    TEST_ASSERT_EQUAL_STRING("Stringiscl!", zrmvchr(s2,"o z"));
}

void test_zrmvchr_none(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!", zrmvchr(s2,"xqw"));
}

void test_zrepchr(void){
    TEST_ASSERT_EQUAL_STRING("zString_is_cool!", zrepchr(s2,' ','_'));
}

void test_zrepstr(void){
    char str[]="this text has some text to be text ";
    TEST_ASSERT_EQUAL_STRING("this XXXXXXas some XXXXXXo be XXXXX", 
                            zrepstr(str,"text","XXXXXX"));
}

void test_zrepstr_none(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!", 
                            zrepstr(s2,"text","XXXXXX"));
}

void test_zstrtrm_r(void){
    TEST_ASSERT_EQUAL_STRING("     Free software is a matter of liberty.", 
                            zstrtrm_r(s1));
}

void test_zstrtrm_r_none(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!", 
                            zstrtrm_r(s2));
}

void test_zstrtrm(void){
    TEST_ASSERT_EQUAL_STRING("Free software is a matter of liberty.", 
                            zstrtrm(s1));
}

void test_zstrtrm_none(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!", 
                            zstrtrm(s2));
}

void test_zstrtok(void){
    char str[] = "A,B,,,C";
    const char *exp[]={"A","B",",",",","C"};

    TEST_ASSERT_EQUAL_STRING("A", zstrtok(str,","));
    TEST_ASSERT_EQUAL_STRING("B", zstrtok(NULL,","));
    TEST_ASSERT_EQUAL_STRING(",", zstrtok(NULL,","));
    TEST_ASSERT_EQUAL_STRING(",", zstrtok(NULL,","));
    TEST_ASSERT_EQUAL_STRING("C", zstrtok(NULL,","));
}

void test_zstrsub(void){
    TEST_ASSERT_EQUAL_STRING("is cool!", zstrsub(s2,8,8));
}

/* main program */
int main(){
    UNITY_BEGIN();
        RUN_TEST(test_zstrtrm_l);
        RUN_TEST(test_zstrtrm_l_no_change);
        RUN_TEST(test_zstrchr_0);
        RUN_TEST(test_zstrchr_1);
        RUN_TEST(test_zrmvchr);
        RUN_TEST(test_zrmvchr_none);
        RUN_TEST(test_zrepchr);
        RUN_TEST(test_zrepstr);
        RUN_TEST(test_zrepstr_none);
        RUN_TEST(test_zstrtrm_r);
        RUN_TEST(test_zstrtrm_r_none);
        RUN_TEST(test_zstrtrm);
        RUN_TEST(test_zstrtrm_none);
        RUN_TEST(test_zstrtok);
        RUN_TEST(test_zstrsub);
    return UNITY_END();
}

