#include "Journal.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <set>
#include <algorithm>

Journal::Journal() : todoPath("todo.bujo"), dailyPath("daily.bujo") {}

Journal::Journal(const std::string& todoPath, const std::string& dailyPath) 
    : todoPath(todoPath), dailyPath(dailyPath) {}

void Journal::loadNotes() {
    notes = FileManager::readBujoFile(todoPath);
}

void Journal::saveNotes() {
    FileManager::writeBujoFile(todoPath, notes);
}

void Journal::addNote(const Note& note) {
    notes.push_back(note);
    saveNotes();
}

void Journal::updateNote(int index, const Note& note) {
    if (index >= 0 && index < (int)notes.size()) {
        notes[index] = note;
        saveNotes();
    }
}

void Journal::removeNote(int index) {
    if (index >= 0 && index < (int)notes.size()) {
        notes.erase(notes.begin() + index);
        saveNotes();
    }
}

void Journal::listAll() const {
    if (notes.empty()) {
        std::cout << "Nenhuma nota encontrada." << std::endl;
        return;
    }
    for (size_t i = 0; i < notes.size(); ++i) {
        std::cout << i << ": ";
        notes[i].display();
    }
}

void Journal::listByType(NoteType type) const {
    bool found = false;
    for (size_t i = 0; i < notes.size(); ++i) {
        if (notes[i].getType() == type) {
            std::cout << i << ": ";
            notes[i].display();
            found = true;
        }
    }
    if (!found) std::cout << "Nenhuma nota desse tipo encontrada." << std::endl;
}

void Journal::search(const std::string& query) const {
    bool found = false;
    for (size_t i = 0; i < notes.size(); ++i) {
        if (notes[i].getContent().find(query) != std::string::npos) {
            std::cout << i << ": ";
            notes[i].display();
            found = true;
        }
    }
    if (!found) std::cout << "Nenhum resultado para '" << query << "'" << std::endl;
}

void Journal::listCategories() const {
    std::set<std::string> categories;
    for (const auto& note : notes) {
        if (!note.getCategory().empty()) {
            categories.insert(note.getCategory());
        }
    }
    std::cout << "Categorias:" << std::endl;
    for (const auto& cat : categories) {
        std::cout << " - " << cat << std::endl;
    }
}

void Journal::listTags() const {
    std::set<std::string> tags;
    for (const auto& note : notes) {
        for (const auto& tag : note.getTags()) {
            tags.insert(tag);
        }
    }
    std::cout << "Tags:" << std::endl;
    for (const auto& tag : tags) {
        std::cout << " - " << tag << std::endl;
    }
}

std::string Journal::getCurrentDate() const {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y", &tstruct);
    return buf;
}

void Journal::startNewDay() {
    std::cout << "Iniciando novo dia..." << std::endl;
    
    // Migration logic
    std::vector<Note> migratedNotes;
    std::string today = getCurrentDate();

    // Collect notes that should be migrated
    for (auto& note : notes) {
        if (!note.isCompleted() && !note.isCancelled()) {
            NoteType t = note.getType();
            if (t == NoteType::IMPORTANT || t == NoteType::NORMAL) {
                // If it's today's meeting or scheduled task, migrate it if not completed
                migratedNotes.push_back(note);
            }
        }
    }

    // Mark current notes as migrated in the file (just like the shell script)
    markTasksAsMigrated();

    // Add date header
    notes.emplace_back("===" + today + "===");

    // Add daily tasks
    addDailyTasks();

    saveNotes();
}

void Journal::markTasksAsMigrated() {
    for (auto& note : notes) {
        if (!note.isCompleted() && !note.isCancelled() && !note.isMigrated()) {
            NoteType t = note.getType();
            if (t == NoteType::IMPORTANT || t == NoteType::NORMAL || t == NoteType::EMAIL) {
                note.setMigrated(true);
                // Update raw string by prepending >>
                std::string raw = note.toRawString();
                if (raw.find(">>") != 0) {
                    note.setContent(">>" + raw);
                }
            }
        }
    }
}

void Journal::addDailyTasks() {
    std::vector<Note> dailyNotes = FileManager::readBujoFile(dailyPath);
    for (const auto& dn : dailyNotes) {
        if (dn.getType() != NoteType::COMMENT) {
            notes.push_back(dn);
        }
    }
}

void Journal::migrateAllTasks() {
    // Implement full migration logic similar to bujo -M
    markTasksAsMigrated();
    saveNotes();
}
