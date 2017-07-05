CC = g++
exe = list
obj = List.o demo.o Coordinate.o

$(exe): $(obj)
	g++ -o $(exe) $(obj)
%.o : %.cpp
	g++ -o $@ $< -c
clean:
	rm *.o 