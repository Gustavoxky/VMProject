#include "ram.hpp"

std::string RAM::getType() const {
    return "RAM";
}

void RAM::allocate() {
    std::cout << "RAM alocada.\n";
}

void RAM::deallocate() {
    std::cout << "RAM desalocada.\n";
}

void RAM::printStatistics() const {
    std::cout << "Estatísticas da RAM:\n";
}
