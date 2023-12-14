#include <iostream>
#include <vector>
#include <string>

class Resource {
public:
    virtual std::string getType() const = 0;
    virtual void allocate() = 0;
    virtual void deallocate() = 0;
    virtual ~Resource() {}
};

class GPU : public Resource {
public:
    std::string getType() const override {
        return "GPU";
    }

    void allocate() override {
        std::cout << "GPU alocada.\n";
    }

    void deallocate() override {
        std::cout << "GPU desalocada.\n";
    }
};

class CPU : public Resource {
public:
    std::string getType() const override {
        return "CPU";
    }

    void allocate() override {
        std::cout << "CPU alocada.\n";
    }

    void deallocate() override {
        std::cout << "CPU desalocada.\n";
    }
};

class RAM : public Resource {
public:
    std::string getType() const override {
        return "RAM";
    }

    void allocate() override {
        std::cout << "RAM alocada.\n";
    }

    void deallocate() override {
        std::cout << "RAM desalocada.\n";
    }
};

class CloudInstance {
private:
    int instanceID;
    std::vector<Resource*> resources;

public:
    CloudInstance(int id) : instanceID(id) {}

    void addResource(Resource* resource, int quantity) {
        for (int i = 0; i < quantity; ++i) {
            resources.push_back(resource);
        }
    }

    void allocateResources() {
        for (Resource* resource : resources) {
            resource->allocate();
        }
        std::cout << "Recursos alocados para a instância " << instanceID << ".\n";
    }

    void deallocateResources() {
        for (Resource* resource : resources) {
            resource->deallocate();
        }
        std::cout << "Recursos desalocados para a instância " << instanceID << ".\n";
    }

    ~CloudInstance() {
        for (Resource* resource : resources) {
            delete resource;
        }
    }
};

class CloudService {
private:
    std::vector<CloudInstance> instances;

public:
    void addInstance(const CloudInstance& instance) {
        instances.push_back(instance);
    }

    CloudInstance& getInstance(int index) {
        return instances[index];
    }

    void printStatus(const std::string& message) const {
    std::cout << message << " para o serviço da nuvem. Status atual das instâncias:\n";
    for (std::size_t i = 0; i < instances.size(); ++i) {
        std::cout << "- Instância " << i << "\n";
    }
    std::cout << "\n";
}

};

class CloudProvider {
private:
    std::vector<CloudService> services;

public:
    void addService(const CloudService& service) {
        services.push_back(service);
    }

    CloudService& getService(int index) {
        return services[index];
    }
};

class CloudClient {
private:
    CloudProvider& provider;

public:
    CloudClient(CloudProvider& provider) : provider(provider) {}

    void requestResources(int serviceIndex, int instanceIndex) {
        std::cout << "Alocando recursos da nuvem:\n";
        CloudService& service = provider.getService(serviceIndex);
        CloudInstance& instance = service.getInstance(instanceIndex);
        instance.allocateResources();
    }

    void releaseResources(int serviceIndex, int instanceIndex) {
        std::cout << "Desalocando recursos da nuvem:\n";
        CloudService& service = provider.getService(serviceIndex);
        CloudInstance& instance = service.getInstance(instanceIndex);
        instance.deallocateResources();
    }
};

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
