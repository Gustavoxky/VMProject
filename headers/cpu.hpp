#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "resource.hpp"

class CPU : public Resource {
public:
    std::string getType() const override;
    void allocate() override;
    void deallocate() override;
    void printStatistics() const override;

};

#endif // CPU_H
