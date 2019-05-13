CC=gcc
TARGET=prog
SRCS=main.c crypto.c
OBJFILES=main.o crypto.o
FLAGS=-Wall

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJFILES) $(SRCS)
	$(CC) $(FLAGS) $(OBJFILES) -o $(TARGET)

$(OBJFILES): $(SRCS)
	$(CC) -c $(SRCS)
clean: 
	rm -rf $(TARGET) $(OBJFILES)
