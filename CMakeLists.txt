cmake_minimum_required(VERSION 3.15)

project(RayTracer VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)
include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(RayTracer ${SOURCES}
)
add_library(glad external/glad/src/gl.c)

target_include_directories(glad PUBLIC external/glad/include)
# find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(RayTracer
    PRIVATE
        glfw
        OpenGL::GL
        glad
)
