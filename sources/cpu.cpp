#include "cpu.hpp"

std::string CPU::getType() const {
    return "CPU";
}

void CPU::allocate() {
    std::cout << "CPU alocada.\n";
}

void CPU::deallocate() {
    std::cout << "CPU desalocada.\n";
}

void CPU::printStatistics() const {
    std::cout << "Estatísticas da CPU:\n";
}
