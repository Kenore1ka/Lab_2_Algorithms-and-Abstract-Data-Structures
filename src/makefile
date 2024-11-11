CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC_DIR = .
BUILD_DIR = ../build

all: build_dir postfix_calculator set_operations turtles_truth histogram avl_balance roman_conversion

build_dir:
	mkdir -p $(BUILD_DIR)

postfix_calculator: $(SRC_DIR)/postfix_calculator.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/postfix_calculator

set_operations: $(SRC_DIR)/set_operations.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/set_operations

turtles_truth: $(SRC_DIR)/turtles_truth.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/turtles_truth

histogram: $(SRC_DIR)/histogram.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/histogram

avl_balance: $(SRC_DIR)/avl_balance.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/avl_balance

roman_conversion: $(SRC_DIR)/roman_conversion.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/roman_conversion

clean:
	rm -f $(BUILD_DIR)/*
