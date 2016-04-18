FILENAME=Assignment7.cpp
FLAGS=-std=c++11 -Wall -o
EXENAME=main
CLASSOBJECT=MovieTree.o
CLASSHEADER=MovieTree.h
CLASSCPP=MovieTree.cpp
main: $(CLASSOBJECT)
	g++ $(FILENAME) $(FLAGS) $(EXENAME) $(CLASSOBJECT)
$(CLASSOBJECT): $(CLASSHEADER) $(CLASSCPP)
	g++ -c -std=c++11 -Wall $(CLASSCPP)

clean:
	$(RM) 
