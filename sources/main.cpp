#include <iostream>
#include <vector>
#include <string>
#include "../headers/cloud_instance.hpp"
#include "../headers/cloud_service.hpp"
#include "../headers/cloud_provider.hpp"
#include "../headers/cloud_client.hpp"
#include "../headers/cpu.hpp"
#include "../headers/gpu.hpp"
#include "../headers/ram.hpp"

int main() {
    CloudInstance instance1(0);
    instance1.addResource(new GPU(), 2);
    instance1.addResource(new CPU(), 4);
    instance1.addResource(new RAM(), 8);

    CloudInstance instance2(1);
    instance2.addResource(new GPU(), 1);
    instance2.addResource(new CPU(), 2);
    instance2.addResource(new RAM(), 4);

    CloudService service1;
    service1.addInstance(instance1);

    CloudService service2;
    service2.addInstance(instance2);

    CloudProvider provider;
    provider.addService(service1);
    provider.addService(service2);

    CloudClient client(provider);

    int choice;
    do {
        std::cout << "Escolha uma opção:\n"
                  << "1. Alocar recursos\n"
                  << "2. Desalocar recursos\n"
                  << "3. Sair\n";
        std::cin >> choice;

        int serviceIndex, instanceIndex;
        switch (choice) {
            case 1:
                std::cout << "Escolha um serviço (0 ou 1):\n";
                std::cin >> serviceIndex;
                std::cout << "Escolha uma instância (0 ou 1):\n";
                std::cin >> instanceIndex;
                client.requestResources(serviceIndex, instanceIndex);
                break;
            case 2:
                std::cout << "Escolha um serviço (0 ou 1):\n";
                std::cin >> serviceIndex;
                std::cout << "Escolha uma instância (0 ou 1):\n";
                std::cin >> instanceIndex;
                client.releaseResources(serviceIndex, instanceIndex);
                break;
            case 3:
                std::cout << "Saindo do programa.\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (choice != 3);

    return 0;
}