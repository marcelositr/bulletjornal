#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <vector>
#include <iostream>

/**
 * @enum NoteType
 * @brief Represents the different types of notes/tasks in the Bullet Journal.
 */
enum class NoteType {
    NORMAL,      // *
    IMPORTANT,   // !
    LOW_PRIORITY,// *l
    IDEA,        // ?
    MEETING,     // M
    EMAIL,       // @
    DELEGATED,   // <<
    SCHEDULED,   // >>>
    HEADER,      // ===
    COMMENT,     // #
    TEXT         // Plain text
};

/**
 * @class Note
 * @brief Represents a single note or task in the Bullet Journal.
 */
class Note {
public:
    Note();
    Note(const std::string& rawLine);

    // Getters
    std::string getTitle() const { return title; }
    std::string getContent() const { return content; }
    std::string getCategory() const { return category; }
    std::vector<std::string> getTags() const { return tags; }
    NoteType getType() const { return type; }
    std::string getDate() const { return date; }
    bool isCompleted() const { return completed; }
    bool isCancelled() const { return cancelled; }
    bool isMigrated() const { return migrated; }

    // Setters
    void setTitle(const std::string& t) { title = t; }
    void setContent(const std::string& c) { content = c; }
    void setCategory(const std::string& cat) { category = cat; }
    void setTags(const std::vector<std::string>& t) { tags = t; }
    void setType(NoteType t) { type = t; }
    void setDate(const std::string& d) { date = d; }
    void setCompleted(bool c) { completed = c; }
    void setCancelled(bool c) { cancelled = c; }
    void setMigrated(bool m) { migrated = m; }

    // Logic
    std::string toRawString() const;
    void parseRawLine(const std::string& rawLine);
    void addTag(const std::string& tag);

    // Display
    void display() const;

private:
    std::string title;
    std::string content;
    std::string category;
    std::vector<std::string> tags;
    NoteType type;
    std::string date;
    bool completed;
    bool cancelled;
    bool migrated;

    // Helpers
    NoteType determineType(const std::string& rawLine);
};

#endif // NOTE_H
