#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <string>
#include "resource.hpp"

class RAM : public Resource {
public:
    std::string getType() const override;
    void allocate() override;
    void deallocate() override;
    void printStatistics() const override;

};

#endif // RAM_H
