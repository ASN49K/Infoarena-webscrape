#include <stdio.h>

int cmmdc(int a, int b);

int main(){

FILE *file1, *file2;
int T, A, B;

file1 = fopen("euclid2.in", "r");
file2 = fopen("euclid2.out", "w");

fscanf(file1, "%d", &T);

while(T--){

    fscanf(file1, "%d", &A);
    fscanf(file1, "%d", &B);

    fprintf(file2, "%d\n", cmmdc(A, B));

}

return 0;
}

int cmmdc(int a, int b){

int i = (a<b) ? a : b;

while(i--){

    if(!(a%i)&&!(b%i)){
        break;
    }
}
if(i==1)
return 1;
return i;

}
