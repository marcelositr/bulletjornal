CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE = bulletjornal

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_EXECUTABLES = $(patsubst $(TEST_DIR)/%.cpp, %, $(TEST_SOURCES))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(EXECUTABLE) $(TEST_EXECUTABLES)
	# Running unit tests...
	./testNote
	./testJournal
	# Running smoke test...
	./$(EXECUTABLE) -h

testNote: tests/testNote.cpp obj/Note.o
	$(CXX) $(CXXFLAGS) $^ -o $@

testJournal: tests/testJournal.cpp obj/Journal.o obj/Note.o obj/FileManager.o obj/Utils.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE) $(TEST_EXECUTABLES) testNote testJournal

.PHONY: all clean test
