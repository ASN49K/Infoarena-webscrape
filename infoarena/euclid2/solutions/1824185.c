#include<stdio.h>

int main(){

FILE *file1, *file2;
int T, i, A, B;

file1 = fopen("euclid2.in", "r");
file2 = fopen("euclid2.out", "w");

fscanf(file1, "%d", &T);

while(T--){

    fscanf(file1, "%d", &A);
    fscanf(file1, "%d", &B);

    i = (A<B) ? A : B;

    while(i--){
        if(!(A%i) && !(B%i)){
            fprintf(file2, "%d\n", i);
            break;
        }
    }

}

return 0;
}
