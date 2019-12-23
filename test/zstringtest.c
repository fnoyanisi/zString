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
}

void tearDown(void){
    free(s1);
    free(s2);
}

void test_ltrim(void){
    TEST_ASSERT_EQUAL_STRING("Free software is a matter of liberty.     ",
                            zstring_ltrim(s1));
}

void test_ltrim_no_change(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!",
                            zstring_ltrim(s2));
}

void test_zstring_search_chr_0(void){
    TEST_ASSERT_EQUAL_INT(0, zstring_search_chr(s1, 'x'));
}

void test_zstring_search_chr_1(void){
    TEST_ASSERT_EQUAL_INT(1, zstring_search_chr(s1, 'r'));
}

void test_zstring_remove_chr(void){
    TEST_ASSERT_EQUAL_STRING("Stringiscl!", zstring_remove_chr(s2,"o z"));
}

void test_zstring_remove_chr_none(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!", zstring_remove_chr(s2,"xqw"));
}

void test_zstring_replace_chr(void){
    TEST_ASSERT_EQUAL_STRING("zString_is_cool!", zstring_replace_chr(s2,' ','_'));
}

void test_zstring_replace_str(void){
    char str[]="this text has some text to be text ";
    TEST_ASSERT_EQUAL_STRING("this XXXXXXas some XXXXXXo be XXXXX", 
                            zstring_replace_str(str,"text","XXXXXX"));
}

void test_zstring_replace_str_none(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!", 
                            zstring_replace_str(s2,"text","XXXXXX"));
}

/* main program */
int main(){
    UNITY_BEGIN();
        RUN_TEST(test_ltrim);
        RUN_TEST(test_ltrim_no_change);
        RUN_TEST(test_zstring_search_chr_0);
        RUN_TEST(test_zstring_search_chr_1);
        RUN_TEST(test_zstring_remove_chr);
        RUN_TEST(test_zstring_remove_chr_none);
        RUN_TEST(test_zstring_replace_chr);
        RUN_TEST(test_zstring_replace_str);
        RUN_TEST(test_zstring_replace_str_none);
    return UNITY_END();
}

