OBJS = Stmt.o VM_idea_forgot_to_push.o DataMemory.o InstructionMemory.o RuntimeStack.o StringBuffer.o Token.o
CC = g++
INCLUDE = 
LIBS = 
CFLAGS = -g -std=c++11
EXECUTABLE = VM
COMMANDLINE = ../TestCasesPart2_v2/4Prints.pout

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) $(COMMANDLINE)

cleanmake : clean VM

.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< $(INCLUDE) $(LIBS)

clean :
	rm -f $(EXECUTABLE) ${OBJS}
	rm -f TestCases10_08_22/*.pout
	rm -f TestCases10_08_22/*.out
	rm -f TestCases10_08_22/*.b 
	clear



all:
	g++ -g *.cpp  -std=c++11 -o VM