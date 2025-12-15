#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdio>

// Callback to handle window resize / Retina scaling
static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Init GLFW
    if (!glfwInit()) {
        std::fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // macOS needs forward-compatible core profile for 3.2+
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL 4.1 on Apple Silicon", nullptr, nullptr);
    if (!window) {
        std::fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::fprintf(stderr, "Failed to initialize GLAD\n");
        return -1;
    }

    // Get initial framebuffer size and set viewport
    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear with teal color
        glClearColor(0.1f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers + poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
