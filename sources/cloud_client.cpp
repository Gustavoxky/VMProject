#include "cloud_client.hpp"
#include <iostream>

CloudClient::CloudClient(CloudProvider& provider) : provider(provider) {}

void CloudClient::requestResources(int serviceIndex, int instanceIndex) {
    std::cout << "Alocando recursos da nuvem:\n";
    if (serviceIndex >= 0 && serviceIndex < provider.getServices().size()) {
        CloudService& service = provider.getService(serviceIndex);
        if (instanceIndex >= 0 && instanceIndex < service.getInstances().size()) {
            CloudInstance& instance = service.getInstance(instanceIndex);
            instance.allocateResources();
        } else {
            std::cout << "Erro: Índice de instância inválido.\n";
        }
    } else {
        std::cout << "Erro: Índice de serviço inválido.\n";
    }
}

void CloudClient::releaseResources(int serviceIndex, int instanceIndex) {
    std::cout << "Desalocando recursos da nuvem:\n";
    if (serviceIndex >= 0 && serviceIndex < provider.getServices().size()) {
        CloudService& service = provider.getService(serviceIndex);
        if (instanceIndex >= 0 && instanceIndex < service.getInstances().size()) {
            CloudInstance& instance = service.getInstance(instanceIndex);
            instance.deallocateResources();
        } else {
            std::cout << "Erro: Índice de instância inválido.\n";
        }
    } else {
        std::cout << "Erro: Índice de serviço inválido.\n";
    }
}
