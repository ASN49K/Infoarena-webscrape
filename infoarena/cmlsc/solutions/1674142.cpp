#include <cstdio>
#include <iostream>

using namespace std;

int mx(int a, int b){
    return a>b?a:b;
}

int** lcst(int* a, int* b, int n, int m){
    int** table=new int*[n+1];
    table[0]=new int[m+1];
    for(int i=0;i<=m;i++){
        table[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        table[i]=new int[m];
        table[i][0]=0;
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                table[i][j]=table[i-1][j-1]+1;
            }
            else{
                table[i][j]=mx(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table;
}

pair<int*, int> lcs(int* v, int* w, int n, int m){
    int **s=lcst(v, w, n, m);
    int i=n,j=m;
    int* sol=new int[s[n][m]];
    int sz=s[n][m];

    while(i&&j)
        {
        if(v[i-1]==w[j-1])
        {
            sol[--sz]=v[i-1];
            i--;
            j--;
        }
        else
        {
            if(s[i-1][j]>s[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }

    return make_pair(sol, s[n][m]);
}

int main()
{
    FILE* f=fopen("cmlsc.in", "r");
    FILE* f1=fopen("cmlsc.out", "w");

    int n, m, v[1024], w[1024];
    fscanf(f, "%d %d", &n, &m);

    for(int i=0;i<n;i++){
        fscanf(f, "%d ", &v[i]);
    }

    for(int i=0;i<m;i++){
        fscanf(f, "%d ", &w[i]);
    }

    pair<int*, int> p=lcs(v, w, n, m);

    fprintf(f1, "%d\n", p.second);

    for(int i=0;i<p.second;i++){
        fprintf(f1, "%d ", p.first[i]);
    }
    return 0;
}
