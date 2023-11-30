#include "VMProject/azure/AzureInstance.hpp"  // Substitua pelo caminho real do seu arquivo de definição da classe AzureInstance
#include "VMProject/icloud/ICloudInstance.hpp"

class AzureInstance : public ICloudInstance {
public:
    int GetCPU() const override {
        return 8;  // Exemplo: 8 unidades de CPU
    }

    int GetRAM() const override {
        return 16;  // Exemplo: 16 GB de RAM
    }

    int GetGPU() const override {
        return 4;  // Exemplo: 4 unidades de GPU
    }
};
