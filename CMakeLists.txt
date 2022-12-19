cmake_minimum_required(VERSION 3.0.0)
project(Vulkan_Start VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)


set(VULKAN_H /Users/w_sorley/SDK/VulkanSDK/1.3.236.0/macOS/include)
set(GLFW_H /usr/local/include)
include_directories(${PROJECT_SOURCE_DIR}/include ${GLFW_H})

set(GLFW_LINK /usr/local/lib/libglfw.3.3.dylib)
set(VULKAN_1_LINK /Users/w_sorley/SDK/VulkanSDK/1.3.236.0/macOS/lib/libvulkan.1.dylib)
set(VULKAN_LINK /Users/w_sorley/SDK/VulkanSDK/1.3.236.0/macOS/lib/libvulkan.1.3.236.dylib)
link_libraries(${GLFW_LINK} ${VULKAN_1_LINK} ${VULKAN_LINK})

set(ENV{VK_ICD_FILENAMES} /Users/w_sorley/SDK/VulkanSDK/1.3.236.0/macOS/share/vulkan/icd.d/MoltenVK_icd.json)
set(ENV{VK_LAYER_PATH} /Users/w_sorley/SDK/VulkanSDK/1.3.236.0/macOS/vulkan/explicit_layer.d)

set(SOURCES main.cpp)
add_executable(output ${SOURCES})
