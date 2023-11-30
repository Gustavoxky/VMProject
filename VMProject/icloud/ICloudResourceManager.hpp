#ifndef ICLOUD_RESOURCE_MANAGER_HPP
#define ICLOUD_RESOURCE_MANAGER_HPP

#include <vector>
#include "Allocation.hpp"

class ICloudInstance;  // Declarando a classe ICloudInstance para evitar problemas de dependência circular

class ICloudResourceManager {
public:
    virtual ~ICloudResourceManager() {}
    virtual Allocation ProvisionResources(ICloudInstance* instance, int percentage, const std::string& userName) = 0;
    virtual std::vector<Allocation> GetAllocationHistory() = 0;
};

#endif // ICLOUD_RESOURCE_MANAGER_HPP
