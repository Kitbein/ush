#include "../inc/ush.h" 

int pwdf(fl_list *fl) {
    char pname[PATH_MAX];
    char *P_Name;
    P_Name = getwd(pname);
    char *L_Name;
    L_Name = getenv("PWD");
    L_Name = realpath(L_Name, NULL);
    if (P_Name == NULL) {
        return 0;
    }
    else if (fl->pwd_L) {
        mx_printstr(L_Name);
        mx_printchar('\n');
    }
    else if (fl->pwd_P) {
        mx_printstr(pname); 
        mx_printchar('\n');
    }
    else {
        mx_printstr(L_Name);
        mx_printchar('\n');
    }
    return 0;
}
