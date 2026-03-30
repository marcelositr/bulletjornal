#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    // Terminal Colors
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string WHITE = "\033[37m";
    const std::string BOLD = "\033[1m";
    const std::string BRIGHT_BLACK = "\033[90m";

    void clearScreen();
    void printHeader(const std::string& title);
    std::string getStatusColor(bool completed, bool cancelled, bool migrated);
}

#endif // UTILS_H
