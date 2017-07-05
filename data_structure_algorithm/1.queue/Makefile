CC = g++
exe = queue
obj = demo.o MyQueue.o Customer.o

$(exe): $(obj)
	g++ -o $(exe) $(obj)
%.o : %.cpp
	g++ -o $@ $< -c
clean:
	rm *.o 