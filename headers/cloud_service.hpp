#ifndef CLOUD_SERVICE_H
#define CLOUD_SERVICE_H

#include "cloud_instance.hpp"

class CloudService {
private:
    std::vector<CloudInstance> instances;

public:
    void addInstance(const CloudInstance& instance);
    CloudInstance& getInstance(int index);
    const std::vector<CloudInstance>& getInstances() const;
};

#endif // CLOUD_SERVICE_H
