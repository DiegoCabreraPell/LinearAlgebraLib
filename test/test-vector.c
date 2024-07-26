#include"test-vector.h"

#define NUM_TESTS 0


int test_init()
{
	
}


int test_vectors(void)
{
	int num_success = 0;

	TestCase tests[] = {
		test_init
	};

	for (int i = 0; i < NUM_TESTS; i++)
	{
		num_success += tests[i]();
	}

	return num_success;
}