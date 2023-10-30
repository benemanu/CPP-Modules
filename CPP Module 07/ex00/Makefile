CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

SRCS2 = ex00.cpp

BUILD_DIR = build

BUILD_DIR2 = build_test

OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

OBJS2 = $(patsubst %.cpp,$(BUILD_DIR2)/%.o,$(SRCS2))

TARGET = swapMinMax.out

TARGET2 = swapMinMaxTest.out

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(BUILD_DIR2) $(TARGET2)

$(BUILD_DIR2):
	mkdir -p $(BUILD_DIR2)

$(TARGET2): $(OBJS2)
	$(CXX) $(CXXFLAGS) $(OBJS2) -o $(TARGET2)

$(BUILD_DIR2)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_DIR2)

fclean: clean
	rm -rf $(TARGET)
	rm -rf $(TARGET2)

re: fclean all

.PHONY: all clean fclean re