#include "cub3d.h"

 int main (int argc, char **argv)
 {
	 int i;
	if (argc < 2 || argc > 3)
	{
		arg_error('a');
		exit(0);
	}
	if (check_args(argv, argc) == 1)
		parse(argv);
	else if (check_args(argv, argc) == 2)
		take_screenshot(argv);
	printf ("Exiting the simulation.....\n");
	while (1);
	return (0);	 
 }
