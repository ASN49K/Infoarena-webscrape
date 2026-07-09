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

    int n1, n2, l=0, x, y;

    fscanf(fin, "%d%d", &n1, &n2);
    for(int i=1; i<=n1; ++i)
        fscanf(fin, "%d", &a[i]);
    for(int i=1; i<=n2; ++i)
        fscanf(fin, "%d", &b[i]);

    for(int i=1; i<=n2; ++i){
        for(int j=1; j<=n1; ++j){
            if(a[j]==b[i])
                mat[i][j]=mat[i-1][j-1]+1;
            else if(mat[i-1][j]>mat[i][j-1])
                mat[i][j]=mat[i-1][j];
            else mat[i][j]=mat[i][j-1];
        }
    }

//    for(int i=1; i<=n2; i++){
//        for(int j=1; j<=n1; j++)
//            cout << mat[i][j] << ' ';
//        cout << "\n";
//    }

    x=n1;
    y=n2;
    while(x>=1 && y>=1){
        // cout << a[x] << " " << b[y] << "\n";
        if(a[x]==b[y]){
            v[++l]=a[x];
            --x;
            --y;
        }
        else if(mat[y-1][x]>mat[y][x-1])
            --y;
        else --x;
    }

    fprintf(fout, "%d\n", l);
    for(int i=l; i>=1; i--)
        fprintf(fout, "%d ", v[i]);

    return 0;
}
