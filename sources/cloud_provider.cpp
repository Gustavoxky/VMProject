#include "cloud_provider.hpp"

void CloudProvider::addService(const CloudService& service) {
    services.push_back(service);
}

CloudService& CloudProvider::getService(int index) {
    return services.at(index);
}

const std::vector<CloudService>& CloudProvider::getServices() const {
    return services;
}
