#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("rucsac.in");
ofstream fout("rucsac.out");
int n,g;
int v[2][10005];
struct objs
{
    int p,w;
}obj[5003];

int main()
{
    fin>>n>>g;
    for(int i=1;i<=n;i++)
        fin>>obj[i].w>>obj[i].p;
    for(int i=1;i<=n;i++)
    {

        for(int j=0;j<=g;j++)
        {
            v[i%2][j]=v[(i-1)%2][j];

            if(j>=obj[i].w)
                v[i%2][j]=max(v[i%2][j],v[(i-1)%2][j-obj[i].w]+obj[i].p);

        }
    }
    fout<<v[n%2][g];
    return 0;
}
