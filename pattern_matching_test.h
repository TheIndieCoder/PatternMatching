#include <stdio.h>
#include <assert.h>

typedef void (*pat_match_function)(char*, char*, int[]);
typedef void (*test_func)(pat_match_function);

void run_and_verify(char* txt, char* pat, int* expected_loc, pat_match_function func_to_run)
{

	int loc[LOC_SIZE];

	func_to_run(txt, pat, loc);
	int i=0;
	while(loc[i] != -1)
	{
		assert(loc[i]==expected_loc[i]);
		i++;
	}
}

void basic_test(pat_match_function func_to_test)
{
	char* txt = "AABCAABDAABEAABFAAABG";
	char* pat = "AAB";
	int expected[] = {0, 4, 8, 12, 17};
	
	run_and_verify(txt, pat, expected, func_to_test);
}

void basic_performance_test(pat_match_function func_to_test)
{
	char* txt = "";
	char* pat = "";
	int expected[] = {};

	run_and_verify(txt, pat, expected, func_to_test);
}

void test_run(test_func func_to_run, pat_match_function func_to_test, char* test_title)
{
	printf("Testing %s ... ", test_title);
	func_to_run(func_to_test);
	printf("Done\n");
}

void test(pat_match_function func_to_test, char* test_title)
{
	printf("Testing %s Module\n", test_title);
	test_run(basic_test, func_to_test, "Basic");
	test_run(basic_performance_test, func_to_test, "Basic Performance");
	printf("%s Testing Done.\n", test_title);
}
