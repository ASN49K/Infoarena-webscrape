#include <stdio.h>
#include <stdlib.h>

int v1[1024],v2[1024],mat[1024][1024],sir[1024];

int main()
{
    FILE *fin,*fout;
    fin = fopen("cmlsc.in" ,"r");
    fout = fopen("cmlsc.out" ,"w");

    int n,m,i;
    fscanf(fin, "%d%d" ,&n,&m);
    for(i=0;i<n;i++)
        fscanf(fin, "%d" ,&v1[i]);
    for(i=0;i<m;i++)
        fscanf(fin, "%d" ,&v2[i]);

    int j,k=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(v1[i]==v2[j]){
                if(i==0 || j==0)
                    mat[i][j]=1;
                else
                    mat[i][j]=mat[i-1][j-1]+1;
                if(mat[i][j]>k) k=mat[i][j];
            }
            else{
                if(i==0 && j!=0)
                    mat[i][j]=mat[i][j-1];
                else if(i!=0 && j==0)
                    mat[i][j]=mat[i-1][j];
                else if(i!=0 && j!=0){
                    if(mat[i-1][j]>mat[i][j-1]) mat[i][j]=mat[i-1][j];
                    else mat[i][j]=mat[i][j-1];
                }
            }
        }
    }

    i=n-1;
    j=m-1;
    int l=0;
    while(l<k){
        if(v1[i]==v2[j]){
            sir[l]=v1[i];
            i--; j--; l++;
        }
        //else if(i<=0 && j<=0) flag=1;
        else if(i==0) j--;
        else if(j==0) i--;
        else if(mat[i-1][j]>mat[i][j-1]) i--;
        else j--;
    }

    fprintf(fout, "%d\n" ,k);
    k--;
    while(k>=0){
        fprintf(fout, "%d " ,sir[k]);
        k--;
    }
    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);
    return 0;
}
