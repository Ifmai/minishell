#include <stdio.h>
#include <unistd.h>

int main()
{
	char s[10000];

	// printing current working directory
	printf("%s\n", getcwd(s, 100));

	// using the command


	// printing current working directory
	printf("%s\n", getcwd(s, 10000));

	// after chdir is executed
	return 0;
}



