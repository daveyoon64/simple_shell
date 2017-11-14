#include "sfsh.h"
/**
 * main - entry point for the Super Friendship Shell
 * @argc: argument counter
 * @argv: pointer to array of strings
 * Return: Always return 0
 */
int main(int argc, char *argv[])
{
	sfsh_loop(argc, argv);
	return (0);
}
