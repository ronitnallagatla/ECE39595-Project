OBJS = Parser.o Stmt.o StringBuffer.o InstructionBuffer.o SymbolTable.o
CC = g++
CFLAGS = -g -Wall -std=c++11 
EXEC = parser
COMMANDLINE = 
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose --log-file=memcheck.txt --leak-check=full --show-leak-kinds=all --track-origins=yes

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.PHONY: all
all: $(EXEC)
	./$(EXEC) $(COMMANDLINE)


%o.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
	


# all:
# 	g++ -std=c++11 *.cpp

# test: all
# 	./a.out

# clean:
# 	rm -rf a.out
# 	clear

commit:
	git add --all
	git commit -m "$(m)"
	git push -f