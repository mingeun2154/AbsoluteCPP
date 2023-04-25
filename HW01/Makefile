CC = g++
CFLAGS = -std=c++11
OBJS = main.o money.o rational.o complex.o charpair.o myinteger.o primenumber.o temperature.o boxofproduce.o testfunctions.o ch9.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

exe: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o exe
