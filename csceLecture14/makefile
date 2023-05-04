# target  : prerequisites/dependencies
# tab command
#
#	$@ target
# $< first prerequisite
# $^ all prerequisites

# the -I is the include path flag, we will add the current
# directory (.) to the include path so that the compiler
# will find our user defined header files there
flags = -std=c++17 -Wall -I .

temperature.o : temperature.cc temperature.h
	g++ $(flags) -c $<

testtemp.o : testtemp.cc temperature.h
	g++ $(flags) -c $<

testtemp : testtemp.o temperature.o
	g++ $(flags) $^ -o $@
	./testtemp

clean :
	rm *.o testtemp 

