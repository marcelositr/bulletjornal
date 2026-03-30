#include "../src/Note.h"
#include <iostream>
#include <cassert>

void testNoteParsing() {
    Note n1("* Tarefa normal #tag1");
    assert(n1.getType() == NoteType::NORMAL);
    assert(!n1.isCompleted());
    assert(n1.getTags().size() == 1);
    assert(n1.getTags()[0] == "#tag1");

    Note n2("! Tarefa importante #urgent");
    assert(n2.getType() == NoteType::IMPORTANT);

    Note n3("X * Tarefa concluída");
    assert(n3.isCompleted());

    Note n4("M 30/03/2026 Café");
    assert(n4.getType() == NoteType::MEETING);

    std::cout << "testNoteParsing passed!" << std::endl;
}

int main() {
    testNoteParsing();
    return 0;
}
