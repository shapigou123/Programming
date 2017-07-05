CC = g++
exe = tree
obj = single_list.o demo.o Node.o

$(exe): $(obj)
	g++ -o $(exe) $(obj)
%.o : %.cpp
	g++ -o $@ $< -c
clean:
	rm *.o  $(exe)