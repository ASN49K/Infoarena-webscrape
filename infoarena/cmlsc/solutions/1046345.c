#include <stdio.h>
#include <stdlib.h>

FILE *f,*g;
int N,M,C[1030][1030],X[1030],Y[1030],B[1030][1030],i,j;

void printSequence(int B[1030][1030],int len1,int len2)
{
    if(len1 == 0 || len2 == 0)
        return;
    else if(B[len1][len2] == 1)
         {
            printSequence(B,len1-1,len2-1);
            fprintf(g,"%d ",X[len1]);
         }
         else if(B[len1][len2] == 2)
                printSequence(B,len1,len2-1);
    else printSequence(B,len1-1,len2);
}

void anotherPrint(int counter,int i,int j)
{
    while(counter!=0)
    {
        if(C[i+1][j+1] == (C[i][j]+1))
            {
                i++;
                j++;
                counter--;
                fprintf(g,"%d ",X[i]);
            }
        else if(C[i][j]==C[i+1][j])
             {
                i++;
             }
        else if(C[i][j] == C[i][j+1])
            {
                j++;
            }
    }
}

int main()
{

    f = fopen("cmlsc.in","r");
    g = fopen("cmlsc.out","w");

    fscanf(f,"%d %d",&N, &M);
    for(i=1;i<=N;i++)
        fscanf(f,"%d",&X[i]);
    for(i=1;i<=M;i++)
        fscanf(f,"%d",&Y[i]);
    for(i=1;i<=N;i++)
      for(j=1;j<=M;j++)
      {
        if(X[i] == Y[j])
            {
             C[i][j] = C[i-1][j-1] + 1;
             B[i][j] = 1;  	 
 
            }
        else if(C[i-1][j] > C[i][j-1])
             {
                C[i][j] = C[i-1][j];
		B[i][j] = 3;
             }
             else {
                C[i][j] = C[i][j-1];
            	B[i][j] = 2; 
	    }
      }

    fprintf(g,"%d\n",C[N][M]);

    //anotherPrint(C[N][M],1,1);
    printSequence(B,N,M);
    return 0;
}
