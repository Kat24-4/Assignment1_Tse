CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Itests
BUILD_DIR = build

# --- source discovery ---
SRC_FILES = $(wildcard src/*.cpp)
SRC_NO_MAIN = $(filter-out src/main.cpp, $(SRC_FILES))

APP_OBJS = $(patsubst src/%.cpp, $(BUILD_DIR)/app_%.o, $(SRC_FILES))
TEST_OBJS = $(patsubst src/%.cpp, $(BUILD_DIR)/test_%.o, $(SRC_NO_MAIN))

# --- default target ---
all: app

# --- main program ---
app: $(APP_OBJS)
	$(CXX) $(CXXFLAGS) -o app $(APP_OBJS)

$(BUILD_DIR)/app_%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- tests ---
test_runner: $(TEST_OBJS) $(BUILD_DIR)/test_problems.o
	$(CXX) $(CXXFLAGS) -o test_runner $(TEST_OBJS) $(BUILD_DIR)/test_problems.o

$(BUILD_DIR)/test_%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/test_problems.o: tests/test_problems.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: test_runner
	./test_runner

# --- housekeeping ---
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) app test_runner

.PHONY: all test clean