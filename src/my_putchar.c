/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** putchar
*/

void write(int, char*, int);

void my_putchar(char c)
{
	write(1, &c, 1);
}
