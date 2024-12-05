#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <getopt.h>
#include "cmdcalc.h"

int main(int argc, char * argv[])
{
	if (is_everything_okay(argc, argv) == 0)
        {
                return 0;
        }

	char * charKey = NULL;
	int flagChecker = 0;
	if (getopt(argc, argv, "k:") != -1)
	{
		charKey = optarg;
		flagChecker = 2;
	}
	int decodingKey = atoi(charKey);

	const int elements = argc - 1 - flagChecker;
	const int operations = (elements) / 3;
	

	int * results;
        results = malloc(operations * sizeof(int));
	int index = 0;
	for (int i = 1; i < elements; i += 3)
	{
		results[index++] = get_result(argv[i], argv[i + 1], argv[i + 2]);
	}
	
	
	char * resultString;
	resultString = malloc((operations + 1) * sizeof(char));
	getString(operations, resultString, results, decodingKey);


	print_results(results, operations, resultString);
	

	free(results);
	free(resultString);
	return 0;
}
