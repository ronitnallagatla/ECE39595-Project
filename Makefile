all:
	g++ -std=c++11 *.cpp

test: all
	./a.out

clean:
	rm -rf a.out
	clear

commit:
	git add --all
	git commit -m "$(m)"
	git push