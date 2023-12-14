#include "cloud_instance.hpp"
#include <iostream>

CloudInstance::CloudInstance(int id) : instanceID(id) {}

void CloudInstance::addResource(Resource* resource, int quantity) {
    resources.reserve(resources.size() + quantity);
    for (int i = 0; i < quantity; ++i) {
        resources.push_back(resource);
    }
}

void CloudInstance::allocateResources() {
    for (const auto& resource : resources) {
        resource->allocate();
    }
    std::cout << "Recursos alocados para a instância " << instanceID << ".\n";
}

void CloudInstance::deallocateResources() {
    for (const auto& resource : resources) {
        resource->deallocate();
    }
    std::cout << "Recursos desalocados para a instância " << instanceID << ".\n";
}

CloudInstance::~CloudInstance() {
    for (auto* resource : resources) {
        delete resource;
    }
}

void CloudInstance::printResourceStatistics() const {
    std::cout << "Estatísticas da instância " << instanceID << ":\n";
    for (const auto& resource : resources) {
        resource->printStatistics();
    }
}
