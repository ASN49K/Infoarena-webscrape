#include <stdio.h>
#include <stdlib.h>

int* solutionPointer, solutionLength;

void LCS(int* stString, int* ndString, int stLength, int ndLength);

int main()
{
    register int i,j;
    int* stString, stLength;
    int* ndString, ndLength;

    FILE* file;
    file = fopen("cmlsc.in","r");
    fscanf(file,"%d",&stLength);
    fscanf(file,"%d",&ndLength);

    stString = (int*)malloc(stLength*sizeof(int));
    ndString = (int*)malloc(ndLength*sizeof(int));

    for(i=0; i<stLength; i++) fscanf(file, "%d", stString + i);
    for(i=0; i<ndLength; i++) fscanf(file, "%d", ndString + i);
    fclose(file);

    LCS(stString, ndString, stLength, ndLength);


    return 0;
}

void LCS(int* stString, int* ndString, int stLength, int ndLength)
{
    FILE* file;
    file = fopen("cmlsc.out","w+");
    register int i,j,k;
    int** LCSLength;
    int** LCSDirection;

    LCSLength = (int**)malloc((stLength+1)*sizeof(int*));
    for(i=0; i<=stLength; i++) LCSLength[i] = (int*)malloc((ndLength+1)*sizeof(int));

    LCSDirection = (int**)malloc((stLength+1)*sizeof(int*));
    for(i=0; i<=stLength; i++) LCSDirection[i] = (int*)malloc((ndLength+1)*sizeof(int));

    for(i=0; i<=stLength; i++) LCSLength[i][0] = 0;
    for(i=0; i<=ndLength; i++) LCSLength[0][i] = 0;

    for(i=1; i<=stLength; i++)
        for(j=1; j<=ndLength; j++)
        {
            if(stString[i-1] == ndString[j-1])
            {
                LCSLength[i][j] = LCSLength[i-1][j-1] + 1;
                LCSDirection[i][j] = 0;
            }
            else
            {
                if(LCSLength[i-1][j] > LCSLength[i][j-1])
                {
                    LCSLength[i][j] = LCSLength[i-1][j];
                    LCSDirection[i][j]  = 12;
                }
                if(LCSLength[i-1][j] < LCSLength[i][j-1])
                {
                    LCSLength[i][j] = LCSLength[i][j-1];
                    LCSDirection[i][j]  = 9;
                }
                if(LCSLength[i-1][j] == LCSLength[i][j-1])
                {
                    LCSLength[i][j] = LCSLength[i-1][j];
                    LCSDirection[i][j]  = 21;
                }
            }
        }

        solutionLength = LCSLength[stLength][ndLength];
        solutionPointer = (int*)malloc(solutionLength*sizeof(int));
        i = stLength;
        j = ndLength;
        k = 0;
        while(k < solutionLength)
        {
                if(LCSDirection[i][j] == 0)
                {
                    solutionPointer[k] = stString[i-1];
                    i--;
                    j--;
                    k++;
                }
                 if(LCSDirection[i][j] == 12) i--;
                 if(LCSDirection[i][j] == 9 || LCSDirection[i][j] == 21)  j--;
        }
        fprintf(file,"%d\n",solutionLength);
        for(k=solutionLength-1; k>=0; k--)
            fprintf(file,"%d ",solutionPointer[k]);

        fclose(file);

}
