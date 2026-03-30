#ifndef JOURNAL_H
#define JOURNAL_H

#include <vector>
#include <string>
#include "Note.h"

class Journal {
public:
    Journal();
    Journal(const std::string& todoPath, const std::string& dailyPath);

    // CRUD
    void loadNotes();
    void saveNotes();
    void addNote(const Note& note);
    void updateNote(int index, const Note& note);
    void removeNote(int index);

    // Queries
    void listAll() const;
    void listByType(NoteType type) const;
    void search(const std::string& query) const;
    void listCategories() const;
    void listTags() const;

    // Actions
    void startNewDay();
    void migrateAllTasks();
    void addDailyTasks();

    // Getters
    const std::vector<Note>& getNotes() const { return notes; }

private:
    std::vector<Note> notes;
    std::string todoPath;
    std::string dailyPath;

    std::string getCurrentDate() const;
    void markTasksAsMigrated();
};

#endif // JOURNAL_H
