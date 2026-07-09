#include <stdio.h>
#include <stdlib.h>
int euclid_div(int x, int y){
    if(!y)
        return x;
    else{
        return euclid_div(y,x%y);
    }
}
int main() {

    FILE* in= fopen("euclid2.in","r");
    if(!in)
        return -1;

    FILE* out= fopen("euclid2.out","w");
    if(!out)
        return -2;

    int n;
    fscanf(in,"%d",&n);
    int x,y;
    for(int i=0;i<n;i++){
        fscanf(in,"%d %d",&x,&y);
        if(x<y){
            int aux=x;
            x=y;
            y=aux;
        }
        fprintf(out,"%d\n", euclid_div(x,y));
    }
    return 0;
}
