#include <iostream>
#include <string>
#include <ctime>  // Para usar std::time_t e std::tm
#include "Allocation.hpp"

class Allocation {
public:
    std::string UserName;
    int LocalRAM;
    int LocalCPU;
    int LocalGPU;
    std::string CloudProvider;
    std::string InstanceType;
    int CloudRAM;
    int CloudCPU;
    int CloudGPU;
    std::time_t AllocationTime;  // Alterado para std::time_t

    // Construtor para inicialização padrão do tempo de alocação
    Allocation() : AllocationTime(std::time(nullptr)) {}

    // Função para converter std::time_t para uma string formatada
    std::string FormatTime() const {
        std::tm* timeinfo = std::localtime(&AllocationTime);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        return std::string(buffer);
    }

    // Função para obter uma representação de string da alocação
    std::string ToString() const {
        return "Usuário: " + UserName + ", Recursos Locais - RAM: " + std::to_string(LocalRAM) + "GB, CPU: " +
               std::to_string(LocalCPU) + ", GPU: " + std::to_string(LocalGPU) + ", Recursos na Nuvem - Tipo de Instância: " +
               InstanceType + ", RAM: " + std::to_string(CloudRAM) + "GB, CPU: " + std::to_string(CloudCPU) + ", GPU: " +
               std::to_string(CloudGPU) + ", Provedor de Nuvem: " + CloudProvider + ", Data de Alocação: " + FormatTime();
    }
};

int main() {
    // Exemplo de uso da classe Allocation
    Allocation allocation;
    allocation.UserName = "John Doe";
    allocation.LocalRAM = 16;
    allocation.LocalCPU = 4;
    allocation.LocalGPU = 2;
    allocation.CloudProvider = "Azure";
    allocation.InstanceType = "Standard_DS1_v2";
    allocation.CloudRAM = 8;
    allocation.CloudCPU = 2;
    allocation.CloudGPU = 1;

    std::cout << allocation.ToString() << std::endl;

    return 0;
}
