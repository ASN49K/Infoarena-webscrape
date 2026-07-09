#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int T,a,b,rez;

    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        __asm__
        (
            "movl %1 , %%eax;"
            "movl %2 , %%ebx;"
            "loop:"
            "test %%ebx , %%ebx;"
            "jz done;"
            "xorl %%edx,%%edx;"
            "divl %%ebx;"
            "movl %%ebx , %%eax;"
            "movl %%edx , %%ebx;"
            "jmp loop;"
            "done:"
            "movl %%eax , %0;"
            :"=r"(rez)
            :"r"(a),"r"(b)
        );
        printf("%d\n",rez);
    }
}
