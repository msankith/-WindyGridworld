CC = g++ -std=c++11
COMPILE = $(CC)

simulator : environment.o agent.o main.cpp
	$(COMPILE) main.cpp environment.o agent.o -o simulator

agent.o : agent.cpp agent.h
	$(COMPILE) -c agent.cpp -o agent.o

environment.o : environment.cpp environment.h
	$(COMPILE) -c environment.cpp -o environment.o

clean : 
	rm -f *.o simulator
