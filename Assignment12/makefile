FILENAME=Assignment12.cpp
FLAGS=-std=c++11 -Wall -o
EXENAME=main
CLASSOBJECT=HashTable.o
CLASSHEADER=HashTable.h
CLASSCPP=HashTable.cpp
main: $(CLASSOBJECT)
	g++ $(FILENAME) $(FLAGS) $(EXENAME) $(CLASSOBJECT)
$(CLASSOBJECT): $(CLASSHEADER) $(CLASSCPP)
	g++ -c -std=c++11 -Wall $(CLASSCPP)

clean:
	$(RM) 
