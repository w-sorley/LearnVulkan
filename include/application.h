#ifndef APPLICATION_H
#define APPLICATION_H

#include <vulkan/vulkan.h>

class VulkanApplication
{
private:
    void init();
    void mainLoop();
    void cleanup();
public:
    VulkanApplication(/* args */);
    ~VulkanApplication();
    void run();
};





#endif