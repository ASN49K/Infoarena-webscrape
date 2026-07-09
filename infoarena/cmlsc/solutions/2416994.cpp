#include "stdio.h"

int main()
{
    FILE*  in = fopen("cmlsc.in",  "r");
    FILE* out = fopen("cmlsc.out", "w");

    int l1, l2;
    if( fscanf(in, "%d %d", &l1, &l2) == EOF ) return -1;
    
    int* s1 = new int[l1+1];
    int* s2 = new int[l2+1];
    int* sol = 0;
    if( l1 < l2 )
        sol = new int[l1];
    else
        sol = new int[l2];

    int** matrix = new int* [l1+1];
    for(int i=0; i<=l1; i++)
        matrix[i] = new int[l2+1];

    for(int i=1; i<=l1; i++)
        if( fscanf(in, "%d", &s1[i]) == EOF ) return -1;
    for(int i=1; i<=l2; i++)
        if( fscanf(in, "%d", &s2[i]) == EOF ) return -1;
    for(int i=0; i<=l1; i++)
        for(int j=0; j<=l2; j++)
    {
        if( i==0 || j==0 ) 
            matrix[i][j] = 0;
        else if(s1[i] == s2[j]) 
            matrix[i][j] = matrix[i-1][j-1] + 1;
        else if(matrix[i-1][j] > matrix[i][j-1])
            matrix[i][j] = matrix[i-1][j];
        else
            matrix[i][j] = matrix[i][j-1];  
    }
    fprintf(out, "%d\n", matrix[l1][l2]);    

    int i=l1;
    int j=l2;
    int n=0;
    while(i>=1 && j>=1 && n<matrix[l1][l2])
    {
        if(s1[i] == s2[j])
        {
            sol[n++] = s1[i];
            i--;
            j--;
        }
        else if(matrix[i][j] == matrix[i][j-1])
            j--;
        else
            i--;
    }
    for(int i=n-1; i>=0; i--)
        fprintf(out, "%d ", sol[i]);

    fclose(in);
    fclose(out);
    delete[] s1;
    delete[] s2;
    for(int i=0;i<=l1; i++)
        delete[] matrix[i];
    delete[] matrix;
}
