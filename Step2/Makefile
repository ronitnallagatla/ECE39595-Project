CC = g++
CFLAGS = -g -std=c++11
EXECUTABLE = VM
COMMANDLINE = ../TestCasesPart2_v2/0StartExit.pout

cleanmake : clean VM

.PHONY : run
run : clean $(EXECUTABLE)
	./$(EXECUTABLE) $(COMMANDLINE)

.PHONY : clean $(EXECUTABLE)
$(EXECUTABLE) :
	$(CC) $(CFLAGS) *.cpp -o $(EXECUTABLE)

clean :
	rm -f $(EXECUTABLE)
	rm -f *.o
	rm -f TestCases10_08_22/*.pout
	rm -f TestCases10_08_22/*.out
	rm -f TestCases10_08_22/*.b
	rm -f *.vout
	clear

all:
	g++ -g *.cpp  -std=c++11 -o VM