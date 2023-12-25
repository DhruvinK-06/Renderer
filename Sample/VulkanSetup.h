#pragma once
#include <iostream>
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <vulkan/vulkan.h>
#include <vector>
#include <memory>
#include <optional>




#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>



class VulkanSetup
{
private:  // member variables
    VkInstance          m_VkIns;
    GLFWwindow*         m_Window;
    VkPhysicalDevice    m_PhysicalDevice;
    VkDevice            m_Device;
    static uint32_t     ms_EnableValidation;
    VkQueue             m_GraphicsQueue; 
    VkSurfaceKHR        m_Surface;
    VkQueue             m_PresentQueue;

private:    
    struct QueueFamilyIndices {
        std::optional<uint32_t> GraphicsQueue;
        std::optional<uint32_t> PresentQueue;

        bool IsComplete() { return PresentQueue.has_value() && GraphicsQueue.has_value(); }
    };
public:
    void Init();
    void InitWindow();
    void CreateWindowSurface();
    void Initialize();
    bool CheckValidationSupport();
    void PickPhysicalDevice();
    void MainLoop();
    bool IsDeviceSuitable(VkPhysicalDevice device);
    void CreateLogicalDevice();
    QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

    ~VulkanSetup()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();

        vkDestroySurfaceKHR(m_VkIns, m_Surface, nullptr);
        vkDestroyInstance(m_VkIns, nullptr);
        vkDestroyDevice(m_Device, nullptr);
    }
};