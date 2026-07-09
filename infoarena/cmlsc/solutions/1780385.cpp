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
    for(i=1;i<=x;++i)
    {
        fin>>v[i];
    }
    for(j=1;j<=y;++j)
    {
        fin>>v1[j];
    }
        if(v[1]==v1[1])
    {
        m[1][1]=1;
    }
    else
    {
        m[1][1]=0;
    }
     for(i=2;i<=x;++i)
    {
        if(v[i]==v1[1])
        {
            m[i][1]=m[i-1][1]+1;
        }
        else
        {
            m[i][1]=m[i-1][1];
        }
    }
     for(j=2;j<=y;++j)
    {
        if(v[1]==v1[j])
        {
            m[1][j]=m[1][j-1]+1;
        }
        else
        {
            m[1][j]=m[1][j-1];
        }
    }


     for(i=2;i<=x;++i)
     {
        for(j=2;j<=y;++j)
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
     fout<<m[x][y]<<endl;
     a=x;
     b=y;
     while(m[a][b])
     {
        if(v[a]==v1[b])
        {
            v2[c]=v[a];
            c++;
            a--;
            b--;
        }
        else if (m[a-1][b]< m[a][b-1])
        {
           b--;
        }
        else
        {
            a--;
        }
    }
    while(c)
    {
        fout<<v2[c-1]<<" ";
        c--;
    }
}
