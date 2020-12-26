#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child()
{
    char *args[] = { "/bin/echo", "hello", NULL };
    printf("I am child. my pid is %d. \n", getpid());
    fflush(stdout);
    execve("/bin/echo", args, NULL);
    err(EXIT_FAILURE, "exec() failed");
}

static void parent(pid_t pid_c)
{
    printf("I am parent. my pid is %d and the pid of my child is %d. \n", getpid(), pid_c);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    pid_t ret;
    ret = fork(); // fork()は親プロセスの場合子プロセスのPIDを返す。子プロセスの場合は自身のPIDを返す
    if (ret == -1) err(EXIT_FAILURE, "fork() failed");
    if (ret == 0) {
        child();
    } else {
        parent(ret);
    }
    err(EXIT_FAILURE, "shouldn't reach here");
}