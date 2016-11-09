signal: signal.c
	gcc signal.c -o signal 
run: signal
	./signal
clean: 
	rm *~
	rm signal