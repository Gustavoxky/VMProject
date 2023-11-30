#include <iostream>
#include <vector>
#include <ctime>  // Para usar std::time_t e std::time

// Inclua a definição da classe Allocation
#include "Allocation.hpp"  // Substitua pelo caminho real do seu arquivo de definição da classe Allocation

// Inclua a definição da interface ICloudResourceManager
#include "VMProject/icloud/ICloudResourceManager.hpp"  // Substitua pelo caminho real do seu arquivo de definição da interface ICloudResourceManager

class AzureResourceManager : public ICloudResourceManager {
private:
    std::vector<Allocation> allocationHistory;

public:
    // Implementação do método ProvisionResources da interface ICloudResourceManager
    Allocation ProvisionResources(ICloudInstance* instance, int percentage, const std::string& userName) override {
        int cloudRAM = static_cast<int>(instance->GetRAM() * percentage / 100.0);
        int cloudCPU = static_cast<int>(instance->GetCPU() * percentage / 100.0);
        int cloudGPU = static_cast<int>(instance->GetGPU() * percentage / 100.0);

        Allocation allocation;
        allocation.UserName = userName;
        allocation.LocalRAM = 16;  // Exemplo: Quantidade fixa de RAM local para simplificar
        allocation.LocalCPU = 4;   // Exemplo: Quantidade fixa de CPU local para simplificar
        allocation.LocalGPU = 2;   // Exemplo: Quantidade fixa de GPU local para simplificar
        allocation.CloudRAM = cloudRAM;
        allocation.CloudCPU = cloudCPU;
        allocation.CloudGPU = cloudGPU;
        allocation.CloudProvider = "Azure";
        allocation.InstanceType = "Standard";
        allocation.AllocationTime = std::time(nullptr);

        allocationHistory.push_back(allocation);
        std::cout << "Recursos Azure provisionados - RAM: " << cloudRAM << "GB, CPU: " << cloudCPU << ", GPU: " << cloudGPU << std::endl;

        return allocation;
    }

    // Implementação do método GetAllocationHistory da interface ICloudResourceManager
    std::vector<Allocation> GetAllocationHistory() override {
        return allocationHistory;
    }
};
