#ifndef FARLANDS_LIB_EXIT_H
#define FARLANDS_LIB_EXIT_H

#include <stdnoreturn.h>

typedef enum
{
  FAR_EXIT_OK,
  FAR_EXIT_ERR_GFX,
} FAR_ExitCode;

noreturn void FAR_exit(FAR_ExitCode);

#endif // FARLANDS_LIB_EXIT_H