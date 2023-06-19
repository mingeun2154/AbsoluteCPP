CC = g++
CFLAGS = -std=c++11 -g
OBJS = main.o employee.o salariedemployee.o administrator.o ch14Classes.o ch15Classes.o
EXE = hw02

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o exe
