#include "../inc/ush.h" 

int pwdf(fl_list *fl, char **argv) {
    setenv("cod_er", "0", 1);
    char pname[PATH_MAX];
    bool flag = fl->pwd_P;
    flag = true;
    if (argv[1] != NULL) {
        if (argv[1][0] != '-') {
            setenv("cod_er", "1", 1);
            mx_printstr("pwd: too many arguments\n");
        }
    }
    else if (fl->pwd_L) {
        mx_printstr(getenv("PWD"));
        mx_printchar('\n');
    }
    else if (fl->pwd_P) {
       char *res = realpath(getenv("PWD"), pname);
        mx_printstr(res);
        mx_printchar('\n');
    }
    else {
        mx_printstr(getenv("PWD"));
        mx_printchar('\n');
    }
    return 0;
}
