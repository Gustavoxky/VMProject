#ifndef CLOUD_CLIENT_H
#define CLOUD_CLIENT_H

#include "cloud_provider.hpp"

class CloudClient {
private:
    CloudProvider& provider;

public:
    CloudClient(CloudProvider& provider);
    void requestResources(int serviceIndex, int instanceIndex);
    void releaseResources(int serviceIndex, int instanceIndex);
};

#endif // CLOUD_CLIENT_H
