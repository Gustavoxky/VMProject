#ifndef GPU_H
#define GPU_H

#include <iostream>
#include <string>
#include "resource.hpp"

class GPU : public Resource {
public:
    std::string getType() const override;
    void allocate() override;
    void deallocate() override;
    void printStatistics() const override;
};

#endif // GPU_H
