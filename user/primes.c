#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"


/*
p = get a number from left neighbor
print p
loop:
    n = get a number from left neighbor
    if (p does not divide n)
        send n to right neighbor

*/

int main(){

    int p[36][2];
    char* ch[4];
    printf("prime %d", 2);
    int n=2;
    for(int i=3; i<35; i++){
        if(i%n!=0){//pass
            pipe(p[i]);

        }
    }

    if (fork()==0) {//proc2
        for(int i=3; i<35; i++){
            if(i%n!=0){//pass
                close(0);
                dup(p[i][0]);
                read(p[i][0], ch, 4);
                //printf("%s\n", ch);
                close(p[i][0]);
                close(p[i][1]);
            }
        }
        if (fork()==0) {//proc3



        }
    } else {//proc1
        for(int i=3; i<35; i++){
            if(i%n!=0){//pass
                close(p[i][0]);
                
                write(p[i][1], "i", 4);
                close(p[i][1]);
            }
        }
    }
    exit(0);


    
}









