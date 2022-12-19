#include "application.h"

VulkanApplication::VulkanApplication(/* args */)
{
}

VulkanApplication::~VulkanApplication()
{
}

void VulkanApplication::run() {
    initWindow();
    init();
    mainLoop();
    cleanup();
}


void VulkanApplication::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);  // glfw默认会创建OpenGL context,需要手动禁止
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // 禁止手动拖拽调整窗口大小
    window = glfwCreateWindow(WIDTH, HEIGHT, "vulkan window", nullptr, nullptr);
}
void VulkanApplication::init() {
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

}

void VulkanApplication::mainLoop() {
        while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}
void VulkanApplication::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}