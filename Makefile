CC = g++
CC_FLAGS = -std=c++11
CC_SOURCES = $(shell dir /s /b | find ".cpp")
all:
	$(CC) $(CC_FLAGS) $(CC_SOURCES) -o target
run:
	$(CC) $(CC_FLAGS) $(CC_SOURCES) -o target
	target