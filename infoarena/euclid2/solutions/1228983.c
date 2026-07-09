#include <stdio.h>

//function prototypes
void solve();
int euclid_rec(int,int);
int euclid_it(int,int);

int T;

FILE *fin, *fout;

int main() {

    solve();

    return (0);
};

void solve() {

     int x,//hold first number
         y;//hold second number

     fin  = fopen("euclid2.in", "r");
     fout = fopen("euclid2.out", "w");

     fscanf(fin, "%d", &T);

     for(; T; --T) {

         fscanf(fin, "%d %d", &x, &y); 

         fprintf(fout, "%d\n", euclid_rec(x, y));
     }

     fclose( fin );
     fclose( fout );
};

//solved recursively
int euclid_rec(int x, int y) {

    if( !y ) return x;

    else 

        return euclid_it( y, x % y );  
};

int euclid_it(int x, int y) {

    int r;

    while( y ) {

       r = x % y;

       x = y;

       y = r;  
    }  

    return x;
};
