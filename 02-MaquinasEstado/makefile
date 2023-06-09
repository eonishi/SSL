CC = clang
CFLAGS = -Wall -Wextra -std=c2x -I ./include

TARGET = main
TEST = test/test.txt
SRCS := main.c src/*.c
OBJS :=$(patsubst %.c, %.o, $(wildcard src/*.c)) main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: 
	./$(TARGET) < $(TEST)

exec: 
	./$(TARGET)

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)

cleanall:
	rm -f $(OBJS) $(TARGET) *.o *.out *.exe
