#include "../inc/ush.h"

int cdf(fl_list *fl, char **argv) { 
    char hname[PATH_MAX];
    char *mv;
    if (argv[1] == NULL || mx_strcmp(argv[1], "~") == 0) {
        chdir(getenv("HOME"));
        setenv("OLDPWD", "PWD", 1);
        setenv("PWD", getenv("HOME"), 1);
    }
    else if (fl->cd_P)
    {
        mv = realpath(getenv("HOME"), hname);
        chdir(mv);
    }   
    else if (fl->cd_s) {
        
    }
    else if (mx_strcmp(argv[1], "-") == 0) {
        mv = realpath(getenv("OLDPWD"), hname);
        chdir(mv);
    }
    else {
        DIR *mh;
        mh = opendir(argv[1]);
        if (mh) {
            chdir(argv[1]);
        }
        else {
            mx_printerr("cd: no such file or directory: ");
            mx_printerr(argv[1]);  
            mx_printerr("\n");
        }
    }
    return 0;
}
