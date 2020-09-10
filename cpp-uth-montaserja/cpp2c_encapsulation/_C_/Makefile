TARGET=cpp2c_encapsulation


SOURCES=$(wildcard *.c)

OBJS=$(SOURCES:.c=.o)

INC_DIR=../include
CC=gcc
CFLAGS= -c -pedantic -g -I$(INC_DIR)
CXXFLAGS=$(CFLAGS)
LDFLAGS= -g

.PHONY: clean run gdb leak

$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)


gdb: $(TARGET)
	gdb -q ./$(TARGET)

leak: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)


