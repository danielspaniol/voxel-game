#include "farlands/gfx/gl_ctx.h"

int
main()
{
  FAR_GlCtx_init();

  while (FAR_GlCtx_isRunning()) {
    FAR_GlCtx_beginFrame();
    FAR_GlCtx_endFrame();
  }

  FAR_GlCtx_deinit();
}