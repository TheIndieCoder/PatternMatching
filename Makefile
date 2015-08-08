default:pattern_matching.c pattern_matching_test.h
	gcc -std=c99 pattern_matching.c

clean:
	-rm -f a.out
