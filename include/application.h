#ifndef APPLICATION_H
#define APPLICATION_H
#include <iostream>
#include <vector>

#include <vulkan/vulkan.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include<GLFW/glfw3.h>

class VulkanApplication
{
private:
    GLFWwindow* window;
    VkInstance instance;
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    void initWindow();
    void init();
    void mainLoop();
    void cleanup();
    void createInstance();
public:
    VulkanApplication(/* args */);
    ~VulkanApplication();
    void run();
};





#endif