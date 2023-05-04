flags = -std=c++17 -Wall -I .

employee.o : employee.cc employee.h
	g++ $(flags) -c $<

hourlyemployee.o : hourlyemployee.cc hourlyemployee.h employee.h
	g++ $(flags) -c $<

salariedemployee.o : salariedemployee.cc salariedemployee.h employee.h
	g++ $(flags) -c $<

empdriver.o : empdriver.cc employee.h
	g++ $(flags) -c $<

empdriver : empdriver.o employee.o hourlyemployee.o salariedemployee.o
	g++ $(flags) $^ -o $@
	./$@

clean:
	rm *.o
