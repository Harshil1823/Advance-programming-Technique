# this is the comment symbol in make file
# target : prequisities/dependcies
# $@ target
# $< first prerequisite
# $^ all prerequisite
flags = -std=c++17 -Wall 

csceLecture04.o : csceLecture04.cc
	g++ $(flags) -c $<

csceLecture04 : csceLecture04.o
	g++ $(flags) $< -o $@
	./csceLecture04

clean :
	rm csceLecture04.o csceLecture04
