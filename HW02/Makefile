CC = g++
CFLAGS = -std=c++11 -Wall
OBJS = main.o employee.o salariedemployee.o
EXE = hw02

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o exe
