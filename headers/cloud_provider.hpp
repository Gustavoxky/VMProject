#ifndef CLOUD_PROVIDER_H
#define CLOUD_PROVIDER_H

#include "cloud_service.hpp"

class CloudProvider {
private:
    std::vector<CloudService> services;

public:
    void addService(const CloudService& service);
    CloudService& getService(int index);
    const std::vector<CloudService>& getServices() const;
};

#endif // CLOUD_PROVIDER_H
