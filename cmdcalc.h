#ifndef H_CALCFOO
#define H_CALCFOO
int get_result(char * firstNum, char * operand, char * secoundNum);

void print_results(int * results, const int size, char * resultString);

bool is_everything_okay(int argc, char ** argv);

void getString(int operations, char * resultString, int * results, int decodingKey);
#endif
