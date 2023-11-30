#ifndef AZURE_INSTANCE_HPP
#define AZURE_INSTANCE_HPP

class AzureInstance : public ICloudInstance {
public:
    int GetCPU() const override;
    int GetRAM() const override;
    int GetGPU() const override;
};

#endif // AZURE_INSTANCE_HPP
