#include "cub3d.h"

 int main (int argc, char **argv)
 {
	 int i;
	if (argc < 2 || argc > 3)
	{
		arg_error(argv, 'a');
		exit(0);
	}
	i = check_args(argv, argc);

	printf ("Exiting the simulation.....\n");
	while (1);
	return (0);	 
 }
