cmake_minimum_required(VERSION 3.3)
project(FarLands VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FARLANDS_NAME farlands)
set(FARLANDS_LIB_NAME "${FARLANDS_NAME}-engine")
set(FARLANDS_BIN_NAME "${FARLANDS_NAME}")

set(FARLANDS_LIB_SRC
    src/farlands/lib/prelude.c
)
set(FARLANDS_BIN_SRC
    src/farlands/main.c
)

add_library(${FARLANDS_LIB_NAME} ${FARLANDS_LIB_SRC})
add_executable(${FARLANDS_BIN_NAME} ${FARLANDS_BIN_SRC})

target_include_directories(${FARLANDS_LIB_NAME} PUBLIC src)
target_link_libraries(${FARLANDS_BIN_NAME} PRIVATE ${FARLANDS_LIB_NAME})

################################################################################
# GLFW
################################################################################

find_package(glfw3 REQUIRED)
target_link_libraries(${FARLANDS_LIB_NAME} PUBLIC glfw)

################################################################################
# GLAD
################################################################################

add_subdirectory(3rd-party/glad)
target_link_libraries(${FARLANDS_LIB_NAME} PUBLIC glad)