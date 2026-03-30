#include "../src/Journal.h"
#include <iostream>
#include <cassert>
#include <cstdio>

void testJournal() {
    std::string testTodo = "test_todo.bujo";
    std::string testDaily = "test_daily.bujo";

    // Clean up previous test files
    remove(testTodo.c_str());
    remove(testDaily.c_str());

    Journal j(testTodo, testDaily);
    j.addNote(Note("* Task 1"));
    j.addNote(Note("! Task 2"));

    assert(j.getNotes().size() == 2);
    
    j.loadNotes();
    assert(j.getNotes().size() == 2);

    std::cout << "testJournal passed!" << std::endl;

    remove(testTodo.c_str());
    remove(testDaily.c_str());
}

int main() {
    testJournal();
    return 0;
}
