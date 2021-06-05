#include "farlands/lib/exit.h"

#include <stdio.h>
#include <stdlib.h>

noreturn void
FAR_exit(FAR_ExitCode code)
{
  switch (code) {
    case FAR_EXIT_OK:
      break;
    case FAR_EXIT_ERR_GFX:
      fprintf(stderr, "Aborted: Graphics error\n");
      break;
  }

  exit(code);
}