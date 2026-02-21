
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
	// if (argc < 2)
	// 	return (0);

	int i = 1;


	ft_printf("%s", NULL);

		ft_printf("hello\n");
 ft_printf("%%\n");
 ft_printf("%c %s %d %i %u %x %X\n",'A', "test", -42, -42, 42, 42, 42);
ft_printf("%p\n", NULL);
ft_printf("%s\n", NULL);

	while (i < argc)
	{
		//ft_printf("arg[%d] = '%s'\n", i, argv[i]);
		//ft_printf("%s %d\n", argv[i],i );

		//ft_printf(" %s %s\n",  argv[i], argv[i]);
		// ft_printf(" %c %ds\n",i, argv[i]);
		//ft_printf("%s", NULL);

		ft_printf("hello\n");
ft_printf("%%\n");
ft_printf("%c %s %d %i %u %x %X\n",
	'A', "test", -42, -42, 42, 42, 42);
ft_printf("%p\n", NULL);
ft_printf("%s\n", NULL);

		++i;
	}
	return (0);
}
