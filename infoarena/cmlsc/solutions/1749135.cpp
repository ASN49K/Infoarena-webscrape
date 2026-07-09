#include<fstream>
#include<iostream>
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
    int mat[m][n];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            mat[i][j]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if (v1[i] == v2[j])
            {
                if(i==0 || j==0)
                    mat[i][j]=1;
                else if(mat[i-1][j-1]>0)
                    mat[i][j]=mat[i-1][j-1]+1;
                else //if(mat[i-1][j-1]==0)
                    mat[i][j]=1;
            }
    int max=-1;int x;
    for(int i=0;i<m;i++)
        for (int j = 0; j < n; j++)
            if (max < mat[i][j])
            {max = mat[i][j];x=i;}

    g<<max<<endl;
    for(int i=x-max+1;i<=x;i++)
        g<<v1[i]<<" ";
    f.close();g.close();
}
