#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

std::vector<Note> FileManager::readBujoFile(const std::string& path) {
    std::vector<Note> notes;
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open file " << path << std::endl;
        return notes;
    }

    std::string line;
    while (std::getline(file, line)) {
        notes.emplace_back(line);
    }
    file.close();
    return notes;
}

void FileManager::writeBujoFile(const std::string& path, const std::vector<Note>& notes) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << path << " for writing." << std::endl;
        return;
    }

    for (const auto& note : notes) {
        file << note.toRawString() << std::endl;
    }
    file.close();
}

void FileManager::appendToFile(const std::string& path, const std::string& line) {
    std::ofstream file(path, std::ios_base::app);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << path << " for appending." << std::endl;
        return;
    }
    file << line << std::endl;
    file.close();
}

bool FileManager::ensureDirectoryExists(const std::string& path) {
    struct stat st = {0};
    if (stat(path.c_str(), &st) == -1) {
        // Simple mkdir (might need to handle nested dirs better in a real app)
        if (mkdir(path.c_str(), 0700) == 0) {
            return true;
        }
        return false;
    }
    return true;
}
