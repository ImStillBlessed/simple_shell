#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <fcntl.h>
#include <sys/stat.h>
<<<<<<< HEAD
/*#include <sys/wait.h>*/
=======
#include <sys/wait.h>
>>>>>>> 246ffd8522a9ed97fde6a29af931b415833eacab
#include <sys/types.h>
#include <unistd.h>

char **split(char *str, int count);
int count(char *str);
int check(char **args, int argc);

#endif/* SHELL_H */
