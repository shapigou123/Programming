CC = g++
exe = stack
obj = demo1.o Coordinate.o

$(exe): $(obj)
	g++ -o $(exe) $(obj)
%.o : %.cpp
	g++ -o $@ $< -c
clean:
	rm *.o 