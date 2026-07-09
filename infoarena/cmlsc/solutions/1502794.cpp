#include <iostream>
#include <stdio.h>

using namespace std;

int a[1025];
int b[1025];
int mat[1025][1025];
int v[1025];

int main()
{
    FILE *fin=fopen("cmlsc.in", "r");
    FILE *fout=fopen("cmlsc.out", "w");

    int n1, n2, l=0;

    fscanf(fin, "%d%d", &n1, &n2);
    for(int i=1; i<=n1; ++i)
        fscanf(fin, "%d", &a[i]);
    for(int i=1; i<=n2; ++i)
        fscanf(fin, "%d", &b[i]);

    for(int i=1; i<=n1; ++i){
        for(int j=1; j<=n2; ++j){
            if(a[i]==b[j]){
                mat[i][j]=mat[i-1][j-1]+1;
                if(mat[i][j]>l)
                    v[++l]=a[i];
            }
            else if(mat[i-1][j]>mat[i][j-1])
                mat[i][j]=mat[i-1][j];
            else mat[i][j]=mat[i][j-1];
        }
    }

    fprintf(fout, "%d\n", l);
    for(int i=1; i<=l; i++)
        fprintf(fout, "%d ", v[i]);

    return 0;
}
