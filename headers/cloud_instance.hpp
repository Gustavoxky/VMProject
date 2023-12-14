#ifndef CLOUD_INSTANCE_H
#define CLOUD_INSTANCE_H

#include <vector>
#include "resource.hpp"

class CloudInstance {
private:
    int instanceID;
    std::vector<Resource*> resources;

public:
    CloudInstance(int id);
    void addResource(Resource* resource, int quantity);
    void allocateResources();
    void deallocateResources();
    ~CloudInstance();
    void printResourceStatistics() const;

};

#endif // CLOUD_INSTANCE_H
