#ifndef FARLANDS_GFX_GL_CTX_H
#define FARLANDS_GFX_GL_CTX_H

#include "farlands/lib/prelude.h"

void
FAR_GlCtx_init(void);
void
FAR_GlCtx_deinit(void);

void
FAR_GlCtx_beginFrame(void);
void
FAR_GlCtx_endFrame(void);

bool
FAR_GlCtx_isRunning(void);

#endif // FARLANDS_GFX_GL_CTX_H