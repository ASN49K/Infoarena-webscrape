#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int x,y,a,b,c=0,d=0,i,j;
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>x>>y;
    int m[1024][1024]={},v[1024]={},v1[1024]={},v2[1024]={};
    for(i=0;i<x;++i)
    {
        fin>>v[i];
    }
    for(j=0;j<y;++j)
    {
        fin>>v1[j];
    }
        if(v[0]==v1[0])
    {
        m[0][0]=1;
    }
    else
    {
        m[0][0]=0;
    }


     for(i=1;i<x;++i)
     {
        for(j=1;j<y;++j)
        {
            if(v[i]==v1[j])
            {
                m[i][j]=m[i-1][j-1]+1;
            }
            else
            {
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
     }
     fout<<m[x-1][y-1]<<endl;
     a=x-1;
     b=y-1;
     while(m[a][b])
     {
        if(m[a][b]==m[a-1][b])
        {
            a--;
        }
        else
        {
            v2[c]=v[a];
            c++;
            a--;
            b--;
        }
    }
    while(c)
    {
        fout<<v2[c-1]<<" ";
        c--;
        d++;
    }
}
