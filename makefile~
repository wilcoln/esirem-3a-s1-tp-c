CC=gcc
CFLAGS=-Wall
LDFLAGS=
SRCS=main.c
OBJFILES=main.o
TARGET=main
all: $(TARGET)
	$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
clean:
	rm -f $(OBJFILES) $(TARGET)
depend:
	makedepend -l. $(SRCS)
exe: $(TARGET)
	./$(TARGET)

