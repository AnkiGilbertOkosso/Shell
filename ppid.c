#include <stdio.h>
#include <unistd.h>

/*
 * main - ppid
 *
 * Return: always successful
 */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}

