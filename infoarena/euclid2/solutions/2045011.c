#include <stdio.h>

int gcd(int num1, int num2){
    if(num2 == 0)
        return num1;
    return gcd(num2, num1%num2);
}

int main()
{
    int number = 0;

    FILE * read_pointer, * write_pointer;
    read_pointer = fopen("euclid2.in", "r");
    write_pointer = fopen("euclid2.out", "w");

    if(read_pointer == NULL || write_pointer == NULL){
        return 0;
    }

    fscanf(read_pointer, "%d", &number);

    int num1 = 0, num2 = 0;
    for(int index=0; index<number; index++){
        fscanf(read_pointer, "%d %d", &num1, &num2);
        fprintf(write_pointer, "%d\n", gcd(num1, num2));
    }

    fclose(read_pointer);
    fclose(write_pointer);

    return 0;
}