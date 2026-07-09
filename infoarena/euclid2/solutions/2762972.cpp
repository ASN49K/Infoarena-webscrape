#include <iostream>
#include <cstdio>

using namespace std;

FILE* f;
FILE* g;

int main()
{
    f = fopen("euclid2.in", "r");
    g = fopen("euclid2.out", "w");
    int n,x,y,aux;
    fscanf(f, "%d", &n);
    for(; n>0; n--){
        fscanf(f, "%d %d", &x, &y);
        if(x<y){
            aux=x;
            x=y;
            y=aux;
        }
        while(y!=0){
            aux=x;
            x=y;
            y=aux%y;
        }
        fprintf(g, "%d \n", x);
    }
    return 0;
}
