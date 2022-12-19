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
    createInstance();

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
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}

void VulkanApplication::createInstance() {
    VkApplicationInfo appinfo{};
    appinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appinfo.pApplicationName = "Hello Triangle";
    appinfo.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    appinfo.pEngineName = "No Engine";
    appinfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appinfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appinfo;
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    std::vector<const char*> requiredExtensions;
    for(uint32_t i = 0; i < glfwExtensionCount; i++) {
        requiredExtensions.emplace_back(glfwExtensions[i]);
    }
    requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME); // macos上最新版的MoltenVK sdk强制使用
    createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;   // 开启对应的extension
    createInfo.enabledExtensionCount = (uint32_t) requiredExtensions.size();
    createInfo.ppEnabledExtensionNames = requiredExtensions.data();

    // 获取vulkan支持的extension的详细信息
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    std::cout << "available extensions:\n";
    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if(result != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance, code = ");
    }
}