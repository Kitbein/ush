#include "../inc/ush.h"

int cdf(fl_list *fl, char **argv) {
    if (fl->cd_P)
    {
    }   
    else {
        DIR *mh;
        mh = opendir(argv[1]);
        if (mh) {
            chdir("..");
        }
        else {
            mx_printerr("cd: no such file or directory: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
        }
    }
    return 0;
}
