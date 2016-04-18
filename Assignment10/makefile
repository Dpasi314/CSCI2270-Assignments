FILENAME=Assignment10.cpp
FLAGS=-std=c++11 -Wall -o
EXENAME=main
CLASSOBJECT=Graph.o
CLASSHEADER=Graph.h
CLASSCPP=Graph.cpp
main: $(CLASSOBJECT)
	g++ $(FILENAME) $(FLAGS) $(EXENAME) $(CLASSOBJECT)
$(CLASSOBJECT): $(CLASSHEADER) $(CLASSCPP)
	g++ -c -std=c++11 -Wall $(CLASSCPP)
clean:
	$(RM) 

