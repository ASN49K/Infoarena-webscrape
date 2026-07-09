#include <iostream>
#include <fstream>

using namespace std;
int v[1025],k=0,v1[1025],v2[1025],N,M,m[1025][1025];
ifstream fin("pag.in");
int main()
{   int i,j;
    fin>>N>>M;
    for(i=1;i<=N;i++)
        fin>>v1[i];
    for(i=1;i<=M;i++)
        fin>>v2[i];

    for(i=1;i<=N;i++)
        {   if(v1[i]==v2[1])
                {m[i][1]=m[i-1][1]+1;v[i]=++k;}
            else m[i][1]=m[i-1][1];
            for(j=2;j<=M;j++)
            {   if(v1[i]==v2[j])
                    {m[i][j]=m[i][j-1]+1;v[i]=++k;}
                else m[i][j]=m[i][j-1];

            }}

    cout<<m[N][M];
    cout<<"\n";
    for(i=1;i<=N;i++)
        if(v[i])cout<<v1[i]<<" ";
    return 0;
}
