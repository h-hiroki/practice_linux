#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    for(;;)        // ループはユーザモードのしょり
        getppid(); // getppidでシステムコール。カーネル側の処理がふくまれる。
}