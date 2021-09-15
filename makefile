cpp-proj.exe : main.o roster.o student.o
	g++ main.o roster.o student.o -o cpp-proj.exe

main.o : main.cpp roster.h
	g++ -Wall -c main.cpp

roster.o : roster.cpp roster.h student.h
	g++ -Wall -c roster.cpp

student.o : student.cpp student.h degree.h
	g++ -Wall -c student.cpp

clean :
	-rm *.o