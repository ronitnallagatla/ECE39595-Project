CC = g++
CFLAGS = -g -std=c++11
EXEC = vm
COMMANDLINE = ../TestCasesPart2_v2/0StartExit.out

cleanmake : clean vm

.PHONY : run
run : clean $(EXEC)
	./$(EXEC) $(COMMANDLINE)

.PHONY : clean $(EXEC)
$(EXEC) :
	$(CC) $(CFLAGS) *.cpp -o $(EXEC)

clean :
	rm -f $(EXEC)
	rm -f *.o
	rm -f *.vout
	clear
