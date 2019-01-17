CC=gcc
TARGET=prog
LDFLAGS= -lm
SRCS=main.c events.c
OBJFILES=main.o events.o
FLAGS=-Wall

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(TARGET) $(LDFLAGS)

$(OBJFILES): $(SRCS)
	$(CC) -c $(SRCS)
clean: 
	rm -rf $(TARGET) $(OBJFILES) *.csv

depend: 
		make depend -l. $(SRCS)
exe: $(TARGET)
	./$(TARGET)
