#include<fstream>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int m,n;
    fstream f,g;
    f.open("cmlsc.in",ios::in);
    g.open("cmlsc.out",ios::out);
    f>>m>>n;
    int *v1,*v2;
    v1=new int[m];
    v2=new int[n];
    for(int i=0;i<m;i++)
        f>>v1[i];
    for(int i=0;i<n;i++)
        f>>v2[i];
    int mat[m+1][n+1];

    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            mat[i][j]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(v1[i-1]==v2[j-1]) {
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
                mat[i][j]=(mat[i-1][j]>mat[i][j-1])?mat[i-1][j]:mat[i][j-1];


        }
    int max=-1;int xi=0,xj=0;
    for(int i=0;i<=m;i++) {

            for (int j = 0; j <= n; j++) {
                if (max < mat[i][j]) {
                    max = mat[i][j];
                    xi = i;xj=j;
                }
            }
    }


    stack<int> stiva;
    g<<max<<endl;//<<xi<<" "<<xj;
    while(xi!=0 && xj!=0)
    {
        if(v1[xi-1]==v2[xj-1])
        {stiva.push(v1[xi-1]);xi--;xj--;}
        else
        {
            if(mat[xi-1][xj]>=mat[xi][xj-1])
                xi--;
            else
                xj--;
        }
    }
    while(!stiva.empty())
    {
        g<<stiva.top();
        stiva.pop();
        if(!stiva.empty())
            g<<" ";
    }
    f.close();g.close();
}
