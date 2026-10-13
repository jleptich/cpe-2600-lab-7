CC = gcc
CFLAGS = -c -Wall
LDFLAGS = 
SOURCES = vector.c arithmetic.c linkedlist.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= veclab

all: $(SOURCES)$(EXECUTABLE)
-include $(OBJECTS:.o=.d)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< -o $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d