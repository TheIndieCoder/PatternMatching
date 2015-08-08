#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LOC_SIZE 100

#include "pattern_matching_test.h"

void naive(char* txt, char* pat, int loc[])
{
	int M = strlen(txt);
	int N = strlen(pat);
	bool bPatFound = true;	
	
	int count = 0;

	for(int i=0; i<(M-N); ++i)
	{
		bPatFound = true;
		for(int j=0; j<N; ++j)
		{
			if(txt[i+j] != pat[j])
				bPatFound = false;
		}
		if(bPatFound)
		{
			loc[count] = i;
			count++;
		}
	}
	loc[count] = -1;
}

int main()
{
	test(naive);
	return 0;
}
