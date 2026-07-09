#include <stdio.h>

int cmmdc(int a, int b);

int main(){

FILE *file1, *file2;
int a, b, t;

file1 = fopen("euclid2.in", "r");
file2 = fopen("euclid2.out", "w");

fscanf(file1, "%d", &t);

while(t--){
    fscanf(file1, "%d", &a);
    fscanf(file1, "%d", &b);
    fprintf(file2, "%d\n", cmmdc(a, b));
}

return 0;
}

int cmmdc(int a, int b){

if(b==0){
    return a;
}
return cmmdc(b, a % b);
}
