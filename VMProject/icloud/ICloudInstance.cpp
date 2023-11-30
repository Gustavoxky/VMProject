class ICloudInstance {
public:
    virtual ~ICloudInstance() {}
    virtual int GetCPU() const = 0;
    virtual int GetRAM() const = 0;
    virtual int GetGPU() const = 0;
};
