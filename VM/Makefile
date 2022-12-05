CC = g++
CFLAGS = -g -std=c++11
EXEC = VM
COMMANDLINE = ../TestCasesPart2_v2/0StartExit.out

cleanmake : clean VM

.PHONY : run
run : clean $(EXEC)
	./$(EXEC) $(COMMANDLINE)

.PHONY : clean $(EXEC)
$(EXEC) :
	$(CC) $(CFLAGS) *.cpp -o $(EXEC)

clean :
	rm -f $(EXECUTABLE)
	rm -f VM
	rm -f *.o
	rm -f *.vout
	clear
