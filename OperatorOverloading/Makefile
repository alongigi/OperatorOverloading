myStudentSet: Main.o StudentSet.o Student.o 
	g++ Main.o StudentSet.o Student.o -o myStudentSet
Main.o: Main.cpp StudentSet.h 
	g++ -c Main.cpp
StudentSet.o: StudentSet.cpp Student.h
	g++ -c StudentSet.cpp
Student.o: Student.cpp  Student.h
	g++ -c Student.cpp

clean: rm -f *.o    
