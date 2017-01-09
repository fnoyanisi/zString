/******************************************************************************
* zstring.h
* Copyright (c) 2012-2016, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
*
*  Description :
*  Main include file for zString string library. You can explicitly include
*  the header file for any particular function or include this file only once.
*  For ease of use, it is recommended to include this file instead of
*  including each header for a particular function.
******************************************************************************/
#ifndef ZSTRING_H
#define ZSTRING_H

#define ZSTRING_VER "1.8.1"

#ifndef ZSTRING_SEARCH_CHR_H
#include "zstring_search_chr.h"
#endif

#ifndef ZSTRING_REMOVE_CHR_H
#include "zstring_remove_chr.h"
#endif

#ifndef ZSTRING_STRTOK_H
#include "zstring_strtok.h"
#endif

#ifndef ZSTRING_STRTOK_DQUOTES_H
#include "zstring_strtok_dquotes.h"
#endif

#ifndef ZSTRING_REPLACE_CHR_H
#include "zstring_replace_chr.h"
#endif

#ifndef ZSTRING_REPLACE_STR_H
#include "zstring_replace_str.h"
#endif

#ifndef ZSTRING_TRIM_H
#include "zstring_trim.h"
#endif

#ifndef ZSTRING_LTRIM_H
#include "zstring_ltrim.h"
#endif

#ifndef ZSTRING_RTRIM_H
#include "zstring_rtrim.h"
#endif

#endif
