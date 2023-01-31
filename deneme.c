#include <stdio.h>

typedef struct deneme
{
	char a;
	char *a;

}	denemes;

int main(int ac, char **av, char **env)
{
	denemes as;
	printf("%d",sizeof(as));
}