# this is the comment symbol in make file
# target : prequisities/dependcies
# $@ target
# $< first prerequisite
# $^ all prerequisite

# the -I is the include path flag, we will add the current 
# directory (.) to the include path so that the compiler 
# will find our user defined header files there
flags = -std=c++17 -Wall -I .

myfunctions.o :: myfunctions.cc myfunctions.h
	g++ $(flags) -c $<

csceLecture05.o : csceLecture05.cc myfunctions.h
	g++ $(flags) -c $<

csceLecture05 : csceLecture05.o myfunctions.o
	g++ $(flags) $^ -o $@
	./csceLecture05

clean :
	rm csceLecture05.o myfunctions.o csceLecture05

