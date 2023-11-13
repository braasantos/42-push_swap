#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h> 
# include <string.h>
# include <stdlib.h>
# include <limits.h>

// List struct
typedef struct s_list
{
  	void					*content;
	struct s_list			*next;
}               t_list;

#endif