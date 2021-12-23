#include "../inc/ush.h" 

char* read_line() {
    int sym;
    char *buf = (char*)malloc(sizeof(char) * 1024);
    int ind = 0;
    while (true) {
        sym = getchar();
        if (sym == '\n') {
            buf[ind] = '\0';
            return buf;
        }
        else {
            buf[ind] = sym;
        }
        ind++;
    }
    return buf;
}
extern char ** environ;

void danilsoscka() {
    int num;
    c_list *com = NULL;
    fl_list *flag = NULL;
    com = (c_list *)(malloc(sizeof(c_list)));
    flag = (fl_list *)(malloc(sizeof(fl_list)));
    char *str = NULL;
    char **argv = NULL;
    char p = true;
    while (p) {
        mx_printstr("u$h> ");
        while (true) {
            str = read_line();
            argv = mx_strsplit(str, ' ');
            if (argv[0] == NULL) {
                break;
            }
            cheking(com, argv[0]);
            num = checkflags(flag, com, argv[1]);
             if (num == -2) {
                mx_printstr("fhhh");
                break;
            }
            if (num == -1) {
                break;
            }
            else if (argv[0] != NULL && mx_strcmp(argv[0], "exit") == 0) {
                p = false;
                break;
            }
            functions(com, argv, flag);
            break;
        }
    }
}

int main(int argc, char **argv ) {
    int b = 0;
    b = argc;
    char *a;
    a = argv[1]; 
    danilsoscka();
    return 0;
}
