#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
public:
    virtual std::string getType() const = 0;
    virtual void allocate() = 0;
    virtual void deallocate() = 0;
    virtual ~Resource() {}
    virtual void printStatistics() const = 0;
};

#endif // RESOURCE_H
