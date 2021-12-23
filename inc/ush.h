#ifndef USH_H
#define USH_H

#include "../libmx/inc/libmx.h"

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <time.h>
#include <string.h>
#include <pwd.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef struct comands_list {
    bool cd;
    bool env;
    bool which;
    bool echo;
    bool pwd;
}      c_list;

typedef struct flags_list {
    bool env_i;
    bool env_P;
    bool env_u;
    bool cd_s;
    bool cd_P;
    bool cd_a;
    bool pwd_L;
    bool pwd_P;
    bool which_a;
    bool which_s;
    bool echo_n;
    bool echo_e;
    bool echo_E; 
}      fl_list;

int checkflags(fl_list *fl, c_list *cum, char *arg);
int cheking(c_list *cum, char *comands);
int functions(c_list *comands, char **argv, fl_list *fl);
void danilsoscka();
int pwdf(fl_list *fl);
int cdf(fl_list *fl, char **argv);

#endif
