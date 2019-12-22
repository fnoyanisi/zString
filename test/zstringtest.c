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
#include <unity.h>
#include <zstring.h>

static char s[]="     Free software is a matter of liberty.     ";
static char t[]="zString is cool!";

void setUp(void){
}

void tearDown(void){
}

void test_ltrim(void){
    TEST_ASSERT_EQUAL_STRING("Free software is a matter of liberty.     ",
                            zstring_ltrim(s));
}

void test_ltrim_no_change(void){
    TEST_ASSERT_EQUAL_STRING("zString is cool!",
                            zstring_ltrim(t));
}

void test_zstring_search_chr_0(){
    TEST_ASSERT_EQUAL_INT(0, zstring_search_chr(s, 'x'));
}

void test_zstring_search_chr_1(){
    TEST_ASSERT_EQUAL_INT(1, zstring_search_chr(s, 'r'));
}

/* main program */
int main(){
    UNITY_BEGIN();
        RUN_TEST(test_ltrim);
        RUN_TEST(test_ltrim_no_change);
        RUN_TEST(test_zstring_search_chr_0);
        RUN_TEST(test_zstring_search_chr_1);
    return UNITY_END();
}

