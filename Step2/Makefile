OBJS = VM_idea_forgot_to_push.o DataMemory.o InstructionMemory.o RuntimeStack.o StringBuffer.o Token.o
CC = g++
INCLUDE = 
LIBS = 
CFLAGS = -g -std=c++11
EXECUTABLE = VM
COMMANDLINE = ../TestCases10_08_22/12Jump.pout

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) $(COMMANDLINE)

cleanmake : clean hw12

.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS)

$(OBJS): %.o : %.cpp
	$(CC) $(CFLAGS) -c $< $(INCLUDE) $(LIBS)

clean :
	rm $(EXECUTABLE) ${OBJS}
	rm TestCases10_08_22/*.pout
	rm TestCases10_08_22/*.out
	rm TestCases10_08_22/*.b 



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