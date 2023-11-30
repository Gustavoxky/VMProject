#include "VMProject/aws/AwsInstance.cpp"  // Substitua pelo caminho real do seu arquivo de definição da classe AwsInstance
#include "VMProject/icloud/ICloudInstance.hpp"  // Substitua pelo caminho real do seu arquivo de definição da interface ICloudInstance

class AwsInstance : public ICloudInstance {
public:
    int GetCPU() const override;
    int GetRAM() const override;
    int GetGPU() const override;
};

#endif // AWS_INSTANCE_HPP
