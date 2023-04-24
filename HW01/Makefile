CC = g++

OBJS = main.o money.o rational.o complex.o charpair.o myinteger.o primenumber.o temperature.o boxofproduce.o testfunctions.o ch9.o

%.o: %.cpp
	$(CC) -c $< -o $@

exe: $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -rf *.o exe
