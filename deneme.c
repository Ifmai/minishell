#include <stdio.h>
#include <unistd.h>
#include "./includes/ifmai.h"
int main(int ac, char **av, char **env)
{
    int file_desc = open("selam",O_WRONLY | O_APPEND);
      
    // here the newfd is the file descriptor of stdout (i.e. 1)
    dup2(file_desc, 1) ; 
          
    // All the printf statements will be written in the file
    // "tricky.txt"
    printf("I will be printed in the file tricky.txt\n");
      
	return 0;
}
