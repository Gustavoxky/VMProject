#ifndef ALLOCATION_HPP
#define ALLOCATION_HPP

#include <string>
#include <ctime>

class Allocation {
public:
    std::string UserName;
    int LocalRAM;
    int LocalCPU;
    int LocalGPU;
    std::string CloudProvider;
    std::string InstanceType;
    int CloudRAM;
    int CloudCPU;
    int CloudGPU;
    std::time_t AllocationTime;

    Allocation();
    std::string FormatTime() const;
    std::string ToString() const;
};

#endif // ALLOCATION_HPP
