#include "../inc/ush.h" 

int functions(c_list *comands, char **argv, fl_list *fl) {
    char *a;
    a = argv[1];
    if(comands->cd) {
        cdf(fl, argv);
        return 0;
    }

    if(comands->echo) {
        return 0;
    }

    if(comands->env) {
        return 0;
    }

    if(comands->which) {
        return 0;
    }

    if(comands->pwd) {
        pwdf(fl);
        return 0;
    }
    else {
        pid_t pid, wpid;
        int status = 0;
        pid = fork();
        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("lsh");
            }
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            perror("lsh");
        }
        else {
            do {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        return 1;
    }
    return 0;
}
