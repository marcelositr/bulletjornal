#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Note.h"

class FileManager {
public:
    static std::vector<Note> readBujoFile(const std::string& path);
    static void writeBujoFile(const std::string& path, const std::vector<Note>& notes);
    static void appendToFile(const std::string& path, const std::string& line);
    static bool ensureDirectoryExists(const std::string& path);
};

#endif // FILEMANAGER_H
