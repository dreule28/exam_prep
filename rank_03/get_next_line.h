#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

	#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 42
	#endif
	#include <stdlib.h>
	#include <stdio.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <string.h>
	char	*get_next_line(int fd);
#endif