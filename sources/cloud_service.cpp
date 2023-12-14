#include "cloud_service.hpp"

void CloudService::addInstance(const CloudInstance& instance) {
    instances.push_back(instance);
}

CloudInstance& CloudService::getInstance(int index) {
    return instances.at(index);
}

const std::vector<CloudInstance>& CloudService::getInstances() const {
    return instances;
}
