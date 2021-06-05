#include "farlands/gfx/gl_ctx.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "farlands/lib/exit.h"

////////////////////////////////////////////////////////////////////////////////
// DATA
////////////////////////////////////////////////////////////////////////////////

static const u32 FAR_GLCTX_WIDTH = 1280;
static const u32 FAR_GLCTX_HEIGHT = 720;
static const char* FAR_GLCTX_TITLE = "Farlands";

static GLFWwindow* g_FAR_GlCtx_win = NULL;

////////////////////////////////////////////////////////////////////////////////
// GLOBAL LIFECYCLE
////////////////////////////////////////////////////////////////////////////////

static void
FAR_GlCtx_initGlfwSys(void);
static void
FAR_GlCtx_initGlfwWin(void);
static void
FAR_GlCtx_initGladSys(void);
static void
FAR_GlCtx_setupGlViewport(void);

void
FAR_GlCtx_init(void)
{
  FAR_GlCtx_initGlfwSys();
  FAR_GlCtx_initGlfwWin();
  FAR_GlCtx_initGladSys();
  FAR_GlCtx_setupGlViewport();
}

void
FAR_GlCtx_deinit(void)
{
  glfwTerminate();
}

static void
FAR_GlCtx_onGlfwErr(i32 code, const char* msg)
{}

static void
FAR_GlCtx_initGlfwSys(void)
{
  glfwSetErrorCallback(FAR_GlCtx_onGlfwErr);
  if (!glfwInit()) {
    FAR_exit(FAR_EXIT_ERR_GFX);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

static void
FAR_GlCtx_initGlfwWin(void)
{
  g_FAR_GlCtx_win = glfwCreateWindow(
    FAR_GLCTX_WIDTH, FAR_GLCTX_HEIGHT, FAR_GLCTX_TITLE, NULL, NULL);
  if (!g_FAR_GlCtx_win) {
    glfwTerminate();
    FAR_exit(FAR_EXIT_ERR_GFX);
  }
  glfwMakeContextCurrent(g_FAR_GlCtx_win);
}

static void
FAR_GlCtx_initGladSys(void)
{
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    FAR_exit(FAR_EXIT_ERR_GFX);
  }
}

static void
FAR_GlCtx_onWindowSizeChange(GLFWwindow* win, i32 w, i32 h)
{
  glViewport(0, 0, w, h);
}

static void
FAR_GlCtx_setupGlViewport(void)
{
  glViewport(0, 0, FAR_GLCTX_WIDTH, FAR_GLCTX_HEIGHT);
  glfwSetFramebufferSizeCallback(g_FAR_GlCtx_win, FAR_GlCtx_onWindowSizeChange);
}

////////////////////////////////////////////////////////////////////////////////
// FRAME LIFECYCLE
////////////////////////////////////////////////////////////////////////////////

void
FAR_GlCtx_beginFrame(void)
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void
FAR_GlCtx_endFrame(void)
{
  glfwSwapBuffers(g_FAR_GlCtx_win);
  glfwPollEvents();
}

bool
FAR_GlCtx_isRunning(void)
{
  return !glfwWindowShouldClose(g_FAR_GlCtx_win);
}