CC=gcc
TARGET=prog
SRCS=main.c events.c
OBJFILES=main.o events.o
FLAGS=-Wall

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(TARGET)

$(OBJFILES): $(SRCS)
	$(CC) -c $(SRCS)
clean: 
	rm -rf $(TARGET) $(OBJFILES) *.csv

depend: 
		make depend -l. $(SRCS)
exe: $(TARGET)
	./$(TARGET)