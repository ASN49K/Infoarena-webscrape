#include <stdio.h>
#include <stdlib.h>

void LCS(int* stString,int* ndString,short stLength,short ndLength);
int lengthLCS(int* stString,int* ndString,short stLength,short ndLength);
int max(int a, int b);

int* Solution;
int SolutionLength;

int main()
{

    int* stString;
    int* ndString;
    int M,N;
    int i,j;

    //int MAX;

    FILE* in = fopen("cmlsc.in","r");
    FILE* out = fopen("cmlsc.out","w");

    fscanf(in,"%d",&M);
    fscanf(in,"%d",&N);

    stString = (int*)malloc(M*sizeof(int));
    ndString = (int*)malloc(N*sizeof(int));
    Solution = (int*)malloc(sizeof(int));
    SolutionLength = 0;

    for(i=0; i<M; i++)
        fscanf(in,"%d",stString + i);
    for(j=0; j<N; j++)
        fscanf(in,"%d",ndString + j);

    LCS(stString,ndString,M,N);

    fprintf(out,"%d",SolutionLength);
    for(i=SolutionLength;i > 0;i--)
        fprintf(out,"%d ",Solution[SolutionLength-1]);

    free(stString);
    free(ndString);
    free(Solution);

    fclose(in);
    fclose(out);
}

void LCS(int* stString,int* ndString,short stLength,short ndLength)
{
    if(stLength*ndLength==0) return;
    if(stString[stLength]==ndString[ndLength]){
        SolutionLength++;
        Solution = (int*)realloc(Solution,SolutionLength*sizeof(int));
        Solution[SolutionLength-1] = stString[stLength];
        LCS(stString,ndString,stLength-1,ndLength-1);
        return;
    }
    if(lengthLCS(stString,ndString,stLength-1,ndLength) > lengthLCS(stString,ndString,stLength,ndLength-1)) LCS(stString,ndString,stLength-1,ndLength);
    else LCS(stString,ndString,stLength,ndLength-1);
}

int lengthLCS(int* stString,int* ndString,short stLength,short ndLength)
{
    if(stLength*ndLength==0) return 0;
    if(stString[stLength]==ndString[ndLength]) return 1 + lengthLCS(stString,ndString,stLength-1,ndLength-1);
    return max(lengthLCS(stString,ndString,stLength-1,ndLength),lengthLCS(stString,ndString,stLength,ndLength-1));
}

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}
