#include "Note.h"
#include <iostream>
#include <regex>
#include <algorithm>

Note::Note() : type(NoteType::TEXT), completed(false), cancelled(false), migrated(false) {}

Note::Note(const std::string& rawLine) {
    parseRawLine(rawLine);
}

void Note::parseRawLine(const std::string& rawLine) {
    this->content = rawLine;
    this->type = determineType(rawLine);
    this->completed = false;
    this->cancelled = false;
    this->migrated = false;

    // Check for status flags
    if (rawLine.find("X ") == 0 || rawLine.find("x ") == 0 || rawLine.find(" X ") != std::string::npos || rawLine.find(" x ") != std::string::npos) {
        completed = true;
    }
    if (rawLine.find("CX") == 0 || rawLine.find(" CX") != std::string::npos) {
        cancelled = true;
    }
    if (rawLine.find(">>") == 0) {
        migrated = true;
    }

    // Extract tags (words starting with #)
    std::regex tagRegex("#(\\w+)");
    auto tags_begin = std::sregex_iterator(rawLine.begin(), rawLine.end(), tagRegex);
    auto tags_end = std::sregex_iterator();
    for (std::sregex_iterator i = tags_begin; i != tags_end; ++i) {
        tags.push_back((*i).str());
    }

    // Extract categories (words starting with @ or [Category]) - Custom extension
    if (rawLine.find("@") == 0) {
        std::regex catRegex("@(\\w+)");
        std::smatch match;
        if (std::regex_search(rawLine, match, catRegex)) {
            category = match[1];
        }
    }
}

NoteType Note::determineType(const std::string& rawLine) {
    if (rawLine.find("=== ") == 0 || (rawLine.find("===") == 0 && rawLine.length() > 3)) return NoteType::HEADER;
    if (rawLine.find("! ") == 0 || rawLine.find(">>! ") == 0) return NoteType::IMPORTANT;
    if (rawLine.find("*l ") == 0 || rawLine.find(">>*l ") == 0) return NoteType::LOW_PRIORITY;
    if (rawLine.find("* ") == 0 || rawLine.find(">>* ") == 0) return NoteType::NORMAL;
    if (rawLine.find("? ") == 0) return NoteType::IDEA;
    if (rawLine.find("M ") == 0) return NoteType::MEETING;
    if (rawLine.find("@") == 0 || rawLine.find(">>@") == 0) return NoteType::EMAIL;
    if (rawLine.find("<<") == 0) return NoteType::DELEGATED;
    if (rawLine.find(">>>") == 0) return NoteType::SCHEDULED;
    if (rawLine.find("#") == 0) return NoteType::COMMENT;
    return NoteType::TEXT;
}

std::string Note::toRawString() const {
    // If we have a structured note, we'd rebuild it here.
    // For now, we return the original content or modified content.
    return content;
}

void Note::addTag(const std::string& tag) {
    if (tag[0] != '#') {
        tags.push_back("#" + tag);
    } else {
        tags.push_back(tag);
    }
}

void Note::display() const {
    std::string prefix = "";
    if (completed) prefix += "[DONE] ";
    if (cancelled) prefix += "[CANC] ";
    if (migrated) prefix += "[MIGR] ";

    std::cout << prefix << content << std::endl;
}
