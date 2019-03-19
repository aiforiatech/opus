/* Copyright (c) 2018 Mozilla */
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _LPCNET_H_
#define _LPCNET_H_

#ifndef LPCNET_EXPORT
# if defined(WIN32)
#  if defined(LPCNET_BUILD) && defined(DLL_EXPORT)
#   define LPCNET_EXPORT __declspec(dllexport)
#  else
#   define LPCNET_EXPORT
#  endif
# elif defined(__GNUC__) && defined(LPCNET_BUILD)
#  define LPCNET_EXPORT __attribute__ ((visibility ("default")))
# else
#  define LPCNET_EXPORT
# endif
#endif


#define NB_FEATURES 38
#define NB_TOTAL_FEATURES 55

typedef struct LPCNetState LPCNetState;

typedef struct LPCNetDecState LPCNetDecState;

typedef struct LPCNetEncState LPCNetEncState;


int lpcnet_decoder_get_size();

int lpcnet_decoder_init(LPCNetDecState *st);

LPCNetDecState *lpcnet_decoder_create();

void lpcnet_decoder_destroy(LPCNetDecState *st);

int lpcnet_decode(LPCNetDecState *st, const unsigned char *buf, short *pcm);



int lpcnet_encoder_get_size();

int lpcnet_encoder_init(LPCNetEncState *st);

LPCNetEncState *lpcnet_encoder_create();

void lpcnet_encoder_destroy(LPCNetEncState *st);

int lpcnet_encode(LPCNetEncState *st, const short *pcm, unsigned char *buf);



int lpcnet_get_size();

int lpcnet_init(LPCNetState *lpcnet);

LPCNetState *lpcnet_create();

void lpcnet_destroy(LPCNetState *lpcnet);

void lpcnet_synthesize(LPCNetState *lpcnet, short *output, const float *features, int N);

#endif
