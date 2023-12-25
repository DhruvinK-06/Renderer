#include "VulkanSetup.h"

int main()
{
    std::shared_ptr<VulkanSetup> setup = std::make_shared<VulkanSetup>();

    setup->Init();
    setup->MainLoop();
 
    return 0;
}