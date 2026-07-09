#include <stdio.h>
#define FIN "nim.in"
#define FOUT "nim.out"
#define MAXG 11000

int t, //in t will hold the number of configurations
    n, //in n will hold number of heaps
    G[ MAXG ];//store all the heaps

//function prototype
void readAndSolve();

//main function
int main() {

    readAndSolve();
 
    return(0);
};

void readAndSolve() {
 
     //declare an integer for iteration
     int i, j, S;
 
     //prepare for I/O File
     freopen(FIN, "r", stdin);
     freopen(FOUT, "w", stdout);

     scanf("%d", &t);
     
     //for each configuration execute
     for(i = 1; i <= t; i++) {

         S = 0;

         scanf("%d", &n);

         for(j = 1; j <= n; j++)

             scanf("%d", &G[ j ]),
             S ^= G[ j ];

         if( 0 == S) printf("NU");
                 else 
                     printf("DA");

         printf("\n");
     }

     fclose( stdin );
     fclose( stdout );
};