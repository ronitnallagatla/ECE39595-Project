CC = g++
CFLAGS = -g -std=c++11
EXEC = Parser
COMMANDLINE = ../TestCasesPart2_v2/13SimpleGoSub_GoSubLabel_Return

cleanmake : clean Parser

.PHONY : run
run : clean $(EXEC)
	./$(EXEC) $(COMMANDLINE)

.PHONY : clean $(EXEC)
$(EXEC) :
	$(CC) $(CFLAGS) *.cpp -o $(EXEC)

all:
	g++ -g *.cpp  -std=c++11 -o Parser

clean :
	rm -f $(EXEC)
	rm -f *.o
	rm -f TestCases10_08_22/*.pout
	rm -f TestCases10_08_22/*.out
	rm -f TestCases10_08_22/*.b
	rm -f *.vout
	clear


# all: clean
# 	g++ -g *.cpp
# 	clear

# test: all
# 	parsegood
# 	-parseerr

# clean:
# 	rm -f a.out
# 	rm -f TestCases10_08_22/*.pout
# 	rm -f TestCases10_08_22/*.out
# 	rm -f TestCases10_08_22/*.b
# 	clear