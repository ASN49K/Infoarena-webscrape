#include <stdio.h>

int cmmdc(int a, int b);

int main(){

FILE *file1, *file2;
int a, b, t;

file1 = fopen("euclid2.in", "r");
file2 = fopen("euclid2.out", "w");

if(fscanf(file1, "%d", &t))

while(t--){
if((fscanf(file1, "%d", &a))&&(fscanf(file1, "%d", &b)))
    fprintf(file2, "%d\n", cmmdc(a, b));
}

return 0;
}

int cmmdc(int a, int b){

int i = (a<b) ? a : b;

while(i>0){

    if(!(a%i)&&!(b%i)){
        break;
    }
    i--;
}
if(i==1)
return 0;
return i;

}
