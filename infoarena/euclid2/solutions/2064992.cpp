#include <stdio.h>
int val;
FILE *f, *g;
int gcd( int a, int b ) {
    int result ;
    __asm__ __volatile__ ( "movl %1, %%eax;"
                          "movl %2, %%ebx;"
                          "CONTD: cmpl $0, %%ebx;"
                          "je DONE;"
                          "xorl %%edx, %%edx;"
                          "idivl %%ebx;"
                          "movl %%ebx, %%eax;"
                          "movl %%edx, %%ebx;"
                          "jmp CONTD;"
                          "DONE: movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)
    );
    return result;
}
int main()
{
    f = fopen("euclid2.in", "r+");
    g = fopen("euclid2.out", "w+");
    int a, b, n;
    //cin >> n;
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++){
        //cin >> a >> b;
        fscanf(f, "%d%d", &a, &b);
       // cout << gcd(a, b) << "\n";
        fprintf(g, "%d\n", gcd(a, b));
    }
    return 0 ;
}
