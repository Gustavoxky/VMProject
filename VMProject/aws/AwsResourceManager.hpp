#ifndef AWS_RESOURCE_MANAGER_HPP
#define AWS_RESOURCE_MANAGER_HPP

#include <vector>
#include "VMProject/icloud/ICloudResourceManager.hpp"
#include "Allocation.hpp"

class AwsResourceManager : public ICloudResourceManager {
private:
    std::vector<Allocation> allocationHistory;

public:
    Allocation ProvisionResources(ICloudInstance* instance, int percentage, const std::string& userName) override;
    std::vector<Allocation> GetAllocationHistory() override;
};

#endif // AWS_RESOURCE_MANAGER_HPP
