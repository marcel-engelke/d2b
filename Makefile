all: def fast

def:
	gcc -lm -o def d2b.c

fast:
	gcc -lm -D FAST -o fast d2b.c

clean:
	rm -f def fast

rebuild: clean def fast
