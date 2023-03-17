#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(){
    //pipe
    int p1[2];
    int p2[2];
    char *ch[2];
    pipe(p1);
    pipe(p2);
    //fork
    if (fork() == 0) { //child
        close(0);
        dup(p1[0]);
        read(p1[0], ch, 1);
        close(p1[0]);
        close(p1[1]);

        printf("%d: received ping\n", getpid());

        close(p2[0]);
        write(p2[1], "c", 1);
        close(p2[1]);
        
    
    } else { //parent
        
        close(p1[0]);
        write(p1[1], "p", 1);
        close(p1[1]);

        
        close(0);
        dup(p2[0]);
        read(p2[0], ch, 1);
        close(p2[0]);
        close(p2[1]);

        printf("%d: received pong\n", getpid());
    }
    exit(0);
    
}
