#include "Utils.h"
#include <iostream>

namespace Utils {
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }

    void printHeader(const std::string& title) {
        std::cout << BOLD << BLUE << "========================================" << RESET << std::endl;
        std::cout << BOLD << WHITE << "  " << title << RESET << std::endl;
        std::cout << BOLD << BLUE << "========================================" << RESET << std::endl;
    }

    std::string getStatusColor(bool completed, bool cancelled, bool migrated) {
        if (completed || cancelled || migrated) return BRIGHT_BLACK;
        return WHITE;
    }
}
