#include <stdio.h>
#include <unistd.h>
#include "./includes/ifmai.h"
int main(int ac, char **av, char **env)
{
	char *as[] = {"ls", "-l", "-a"};
	execve("/bin/ls",as,env);
	write(1,"pü",2);
}