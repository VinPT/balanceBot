CC=g++
CFLAGS=-c -Wall -ggdb -lbluetooth
LDFLAGS=
SOURCES= main.cpp Balance.cpp Controls.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=balanceBot

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o $(EXECUTABLE)
