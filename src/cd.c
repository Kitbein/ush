#include "../inc/ush.h"

void ser(char *env[], char *dir, char *command){
    for (int k = 1; env[k]; k++) {   
        char *len = *mx_strsplit(env[k], '=');
        if (mx_strcmp(len, command) == 0) {
            for(int i = 0; env[k][i]; i++) {
                if(env[k][i] == '=') {
                    i++;
                    env[k][i] = *dir;                    
                }
            }
        }
    }
}
void reflect(int m, int size, char *road){
    for (int i = 0; i < m; i++){ 
        char temp = *road; 
        for (int j = 0; j < size - 1; j++){
            road[j] = road[j+1]; 
        }    
        road[size - 1] = temp; 
    }
}
void cd(char *argv[], char *envp[]) {
    char *newdir;
    char *dir;
    char *th = NULL;
    char buf[BUFFER_LEN];
    char old_cwd[BUFFER_LEN];
    char cwd[BUFFER_LEN];
    newdir = getcwd(buf, sizeof(buf));
    dir = strcat(newdir, "/");
    ser(envp, dir, "PWD");
    setenv("cod_er", "0", 1);
    if (mx_strcmp(argv[1], "/tmp") == 0) {
        chdir("/tmp");
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", "/tmp", 1);
    }
    else {
        if(strcmp(argv[1], "-P") == 0){
            if(strcmp(argv[2], "~/") == 0 || strcmp(argv[2], "~") == 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                char *str_log = getlogin();
                th = mx_strjoin("/Users/", str_log);
                chdir(th);
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
            if(strncmp(argv[2], "~", 1) == 0 && strcmp(argv[2], "~") != 0 && strncmp(argv[2], "~+/", 3) != 0 && strncmp(argv[2], "~-/", 3) != 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                int ch_cnt = mx_strlen("~");
                int size = strlen(argv[2]);
                reflect(ch_cnt, size, argv[2]);
                //
                argv[1] = strtok(argv[2], "~");
                th = strcat(dir, argv[2]);
                chdir(th);
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
            if(strncmp(argv[2], "~+/", 3) == 0 || strncmp(argv[2], "~-/", 3) == 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                int ch_cnt = mx_strlen("~?/");
                int size = strlen(argv[2]);
                reflect(ch_cnt, size, argv[2]);
                //
                th = strtok(argv[2], "~");
                th = strcat(dir, th);
                chdir(th); 
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
            if(strcmp(argv[2], "/") == 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                th = mx_strjoin(th, argv[2]);
                chdir(th);
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
            if(argv[2]){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                th = mx_strjoin(dir, argv[2]);
                chdir(th);
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
        }
        if (mx_strcmp(argv[1], "-") == 0) {
            char *old = getenv("OLDPWD");
            chdir(getenv("OLDPWD"));
            getcwd(dir, MAXDIR);
            char *bufff = mx_strdup(dir);
            setenv("OLDPWD", getenv("PWD"), 1);
            setenv("PWD", bufff, 1);
            dir = old;
            int index = mx_strlen(getenv("HOME"));
            char *buffer1 = getenv("PWD");
            mx_printstr("~");
            mx_printstr(&buffer1[index]);
            mx_printstr("\n");
        }
        /******
        FLAGS
        *******/
        if(strcmp(argv[1], "-P") != 0 || strcmp(argv[1], "-s") != 0 || strcmp(argv[1], "-") != 0){
            if(strcmp(argv[1], "~/") == 0 || strcmp(argv[1], "~") == 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                char *str_log = getlogin();
                th = mx_strjoin(th, "/Users/");
                th = mx_strjoin(th, str_log);
                chdir(th);
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
        /* 
        work with signs
        */
            if(strncmp(argv[1], "~", 1) == 0 && strcmp(argv[1], "~") != 0 && strncmp(argv[1], "~+/", 3) != 0 && strncmp(argv[1], "~-/", 3) != 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                int ch_cnt = mx_strlen("~");
                int size = strlen(argv[1]);
                reflect(ch_cnt, size, argv[1]);
                argv[1] = *mx_strsplit(argv[1], '~');
                if(strcmp(dir, "//") == 0){
                    th = NULL;
                    th = mx_strjoin(th, "/");
                    th = mx_strjoin(th, argv[1]);
                    chdir(dir);
                    th = dir;
                    setenv("PWD", th, 1);
                    dir = th;
                }
                else{
                    th = mx_strjoin(th, dir);
                    th = mx_strjoin(th, argv[1]);
                    chdir(th);
                    getcwd(cwd, sizeof(cwd));
                    setenv("PWD", cwd, 1);
                    dir = cwd;
                }
                ser(envp, dir, "PWD");
            }
            if(strncmp(argv[1], "~+/", 3) == 0 || strncmp(argv[1], "~-/", 3) == 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                int ch_cnt = mx_strlen("~?/");
                int size = strlen(argv[1]);
                reflect(ch_cnt, size, argv[1]);
                argv[1] = *mx_strsplit(argv[1], '~');
                if(strcmp(dir, "//") == 0){
                    th = NULL;
                    th = mx_strjoin(th, "/");
                    th = mx_strjoin(th, argv[1]);
                    chdir(dir);
                    th = dir;
                    setenv("PWD", th, 1);
                    dir = th;
                }
                else{
                    th = strcat(dir, argv[1]);
                    chdir(th); 
                    getcwd(cwd, sizeof(cwd));
                    setenv("PWD", cwd, 1);
                    dir = cwd;
                }
                ser(envp, dir, "PWD");
            }
            if(strcmp(argv[1], "/") == 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                th = mx_strjoin(th, argv[1]);
                chdir(th);
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
            if(argv[1] && strcmp(argv[1], "/") != 0){
                getcwd(old_cwd, sizeof(old_cwd));
                setenv("OLDPWD", old_cwd, 1);
                th = mx_strjoin(dir, argv[1]);
                chdir(th);
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;
                ser(envp, dir, "PWD");
            }
        }
    }
    
}
