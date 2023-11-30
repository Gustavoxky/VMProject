#include "VMProject/aws/AwsResourceManager.hpp"  // Substitua pelo caminho real do seu arquivo de definição da classe AwsResourceManager
#include "VMProject/icloud/ICloudInstance.hpp"  // Substitua pelo caminho real do seu arquivo de definição da interface ICloudInstance
#include <iostream>

Allocation AwsResourceManager::ProvisionResources(ICloudInstance* instance, int percentage, const std::string& userName) {
    int cloudRAM = static_cast<int>(instance->GetRAM() * percentage / 100.0);
    int cloudCPU = static_cast<int>(instance->GetCPU() * percentage / 100.0);
    int cloudGPU = static_cast<int>(instance->GetGPU() * percentage / 100.0);

    Allocation allocation{
        .UserName = userName,
        .LocalRAM = 32, // Exemplo: Quantidade fixa de RAM local para simplificar
        .LocalCPU = 8,  // Exemplo: Quantidade fixa de CPU local para simplificar
        .LocalGPU = 4,  // Exemplo: Quantidade fixa de GPU local para simplificar
        .CloudRAM = cloudRAM,
        .CloudCPU = cloudCPU,
        .CloudGPU = cloudGPU,
        .CloudProvider = "AWS",
        .InstanceType = "C5",
        .AllocationTime = std::time(nullptr)
    };

    allocationHistory.push_back(allocation);
    std::cout << "Recursos AWS provisionados - RAM: " << cloudRAM << "GB, CPU: " << cloudCPU << ", GPU: " << cloudGPU << std::endl;
    return allocation;
}

std::vector<Allocation> AwsResourceManager::GetAllocationHistory() {
    return allocationHistory;
}
