#include "../inc/ush.h" 

int pwdf(fl_list *fl) {
    char pname[PATH_MAX];
    char P_Name;
    P_Name = *getwd (pname);
    char *rp = realpath(getenv("PWD"), pname);

    if (P_Name == 0) {
        return 0;
    }
    else if (fl->pwd_L) {
        mx_printerr(pname);
        mx_printchar('\n');
    }
    else if (fl->pwd_P) {
        mx_printerr(rp); 
        mx_printchar('\n');
    }
    else {
        mx_printerr(pname);
        mx_printchar('\n');
    }
    return 0;
}
