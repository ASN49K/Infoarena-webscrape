#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_SIZE 1024

int solutions[MAX_SIZE+1][MAX_SIZE+1];
int array1[MAX_SIZE+1], array2[MAX_SIZE+1];

int main()
{
    FILE *fin=fopen("cmlsc.in", "r");
    int size1, size2;
    fscanf(fin, "%d%d", &size1, &size2);

    int i;
    for (i=1; i<=size1; i++) fscanf(fin, "%d", &array1[i]);
    for (i=1; i<=size2; i++) fscanf(fin, "%d", &array2[i]);
    fclose(fin);

    //for  (i=0; i<=MAXN; i++) solutions[i][0]=solutions[0][i]=1;

    int j;
    for (i=1; i<=size1; i++){
        for (j=1; j<=size2; j++){
            if (array1[i]==array2[j]){
                solutions[i][j]=solutions[i-1][j-1]+1;
            }else{
                solutions[i][j]=max(solutions[i-1][j], solutions[i][j-1]);
            }
        }
    }

    int length=solutions[size1][size2];
    i=size1;
    j=size2;

    int subArray[MAX_SIZE+1];
    while (length>0){
        if (solutions[i-1][j]==length){
            i--;
        }else if (solutions[i][j-1]==length){
            j--;
        }else{
            length--;
            subArray[length]=array1[i];
            i--;
            j--;
        }
    }

    FILE *fout=fopen("cmlsc.out", "w");
    fprintf(fout, "%d\n", solutions[size1][size2]);
    for (i=0; i<solutions[size1][size2]; i++){
        fprintf(fout, "%d ", subArray[i]);
    }
    fclose(fout);
    return 0;
}
