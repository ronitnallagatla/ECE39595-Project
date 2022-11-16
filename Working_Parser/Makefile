all: clean
	g++ -g *.cpp
	clear

test: all
	parsegood
	-parseerr

clean:
	rm -f a.out
	rm -f TestCases10_08_22/*.pout
	rm -f TestCases10_08_22/*.out
	rm -f TestCases10_08_22/*.b
	clear