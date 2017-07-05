CC = g++
exe = tree
obj = tree.o demo.o

$(exe): $(obj)
	g++ -o $(exe) $(obj)
%.o : %.cpp
	g++ -o $@ $< -c
clean:
	rm *.o  $(exe)