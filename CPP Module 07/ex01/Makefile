CXX = c++
CXXFLAGS = -Wall -Werror -Wextra

SRCS = main.cpp

BUILD_DIR = build

OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TARGET = iter.out

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re