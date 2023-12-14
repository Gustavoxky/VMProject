#include "gpu.hpp"

std::string GPU::getType() const {
    return "GPU";
}

void GPU::allocate() {
    std::cout << "GPU alocada.\n";
}

void GPU::deallocate() {
    std::cout << "GPU desalocada.\n";
}

void GPU::printStatistics() const {
    std::cout << "Estatísticas da GPU:\n";
}
