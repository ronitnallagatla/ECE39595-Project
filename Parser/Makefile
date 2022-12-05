CC = g++
CFLAGS = -g -std=c++11
EXEC = Parser
COMMANDLINE = ../TestCasesPart2_v2/27DotProd

cleanmake : clean Parser

.PHONY : run
run : clean $(EXEC)
	./$(EXEC) $(COMMANDLINE)

.PHONY : clean $(EXEC)
$(EXEC) :
	$(CC) $(CFLAGS) *.cpp -o $(EXEC)

clean :
	rm -f $(EXEC)
	rm -f *.o
	rm -f ../TestCasesPart2_v2/*.out
	rm -f ../TestCases10_08_22/*.out
	clear