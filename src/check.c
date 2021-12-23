#include "../inc/ush.h"

int cheking(c_list *cum, char *comands) {
    cum->cd = false;
    cum->pwd = false;
    cum->echo = false;
    cum->which = false;
    cum->env = false;
    if (!comands) {
        return 0;
    }
    else if (mx_strcmp(comands, "cd") == 0) {
        cum->cd = true;
    }
    else if (mx_strcmp(comands, "pwd") == 0) {
        cum->pwd = true;
    }
    else if (mx_strcmp(comands, "echo") == 0) {
        cum->echo = true;
    }
    else if (mx_strcmp(comands, "which") == 0) {
        cum->which = true;
    }
    else if (mx_strcmp(comands, "env") == 0) {
        cum->env = true;
    }
    return 0;
}


int checkflags(fl_list *fl, c_list *cum, char *arg) {
    fl->env_i = false;
    fl->env_P = false;
    fl->env_u = false;
    fl->cd_s = false;
    fl->cd_P = false;
    fl->cd_a = false;
    fl->which_a = false;
    fl->which_s = false;
    fl->echo_n = false;
    fl->echo_e = false;
    fl->echo_E = false;
    fl->pwd_L = false;
    fl->pwd_P = false;
     
    if (cum->cd == true) {
        if (arg[0] == '-') {
            for (int i = 1; arg[i]; i++) {
                if (arg[i] == 's') {
                    fl->cd_s = true;
                }
                else if (arg[i] == 'P') {
                    fl->cd_P = true;
                }
                else if (arg[i] == 'a') {
                    fl->cd_a = true;
                }
                else  {
                    mx_printerr("cd: bad option: -");
                    write(STDERR_FILENO, &arg[i], 1);
                    mx_printerr("\n");
                    return -1;
                }
            }
        }
    }
    else if (cum->pwd) {
        for (int i = 1; i <= mx_strlen(arg) - 1; i++) {
            if (arg[i] == 'L') {
                fl->pwd_L = true;
            }
            else if (arg[i] == 'P') {
                fl->pwd_P = true;
            }
            else  {
                mx_printerr("pwd: bad option: -");
                write(STDERR_FILENO, &arg[i], 1);
                mx_printerr("\n");
                return -1;
            }
        }
    }
    else if (cum->env) {
        for (int i = 1; i <= mx_strlen(arg) - 1; i++) {
            if (arg[i] == 'i') {
                fl->env_i = true;
            }
            else if (arg[i] == 'P') {
                fl->env_P = true;
            }
            else if (arg[i] == 'u') {
                fl->env_u = true;
            }
            else  {
                mx_printerr("env: bad option: -");
                write(STDERR_FILENO, &arg[i], 1);
                mx_printerr("\n");
            }
        }
    }
    else if (cum->which) {
        for (int i = 1; i <= mx_strlen(arg) - 1; i++) {
            if (arg[i] == 'a') {
                fl->which_a = true;
            }
            else if (arg[i] == 's') {
                fl->which_s = true;
            }
            else  {
                mx_printerr("which: bad option: -");
                write(STDERR_FILENO, &arg[i], 1);
                mx_printerr("\n");
                return -1;
            }
        }
    }
    else if (cum->echo) {
        for (int i = 1; i <= mx_strlen(arg) - 1; i++) {
            if (arg[i] == 'n') {
                fl->echo_n = true;
            }
            else if (arg[i] == 'e') {
                fl->echo_e = true;
            }
            else if (arg[i] == 'E') {
                fl->echo_E = true;
            }
            else  {
                mx_printerr("echo: bad option: -");
                write(STDERR_FILENO, &arg[i], 1);
                mx_printerr("\n");
                return -1;
            }
        }
    }
    return 0;
}
