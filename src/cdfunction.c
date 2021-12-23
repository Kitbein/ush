#include "../inc/ush.h"

int cdf(fl_list *fl, char **argv) { 
    char hname[PATH_MAX];
    char *mh;
    if (fl->cd_P || mx_strcmp(argv[1], "~") == 0)
    {
        mh = realpath(getenv("HOME"), hname);
        chdir(mh);
    }   
    else if (fl->cd_s) {
        mh = realpath(getenv(argv[1]), hname)
        int nv = readlink(argv[1], sizeof(hname)-1);
        if (nv == -1) {
            chdir(mh);
            
        }
    }
    else if (mx_strcmp(argv[1], "-") == 0) {
        mh = realpath(getenv("OLDPWD"), hname);
        chdir(mh);
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
