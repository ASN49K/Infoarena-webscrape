#include<stdio.h>

int main(){

FILE *file1, *file2;
int T, i, min, A, B;

file1 = fopen("euclid2.in", "r");
file2 = fopen("euclid2.out", "w");

fscanf(file1, "%d", &T);

while(T--){

    fscanf(file1, "%d", &A);
    fscanf(file1, "%d", &B);

    min = (A>=B) ? B : A;

    for(i=min; i>1; i--){
        if(!(A%i) && !(B%i)){
            fprintf(file2, "%d\n", i);
            break;
        }
    }

}

return 0;
}
