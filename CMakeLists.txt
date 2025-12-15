cmake_minimum_required(VERSION 3.20)
project(OpenGLMacOS LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Homebrew paths (Apple Silicon)
set(HOMEBREW_PREFIX "/opt/homebrew")

# Source files
set(SOURCES
    src/main.cpp
    src/glad.c        # from GLAD zip
)

# Executable
add_executable(opengl_app ${SOURCES})

# Include directories
target_include_directories(opengl_app PRIVATE
    ${CMAKE_SOURCE_DIR}/include              # glad/ and KHR/
    ${HOMEBREW_PREFIX}/include               # GLFW headers
)

# Link directories
target_link_directories(opengl_app PRIVATE
    ${HOMEBREW_PREFIX}/lib
)

# Link libraries
target_link_libraries(opengl_app PRIVATE
    glfw                                     # Homebrew's libglfw
    "-framework OpenGL"                      # macOS OpenGL framework
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)

# On arm64, ensure native build (optional for universal binary)
set(CMAKE_OSX_ARCHITECTURES "arm64")
