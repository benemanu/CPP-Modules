CXX = c++
CXXFLAGS = -Wall -Werror -Wextra

SRCS = main.cpp serialization.cpp

BUILD_DIR = build

OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TARGET = serialization

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
