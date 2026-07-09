#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
vector<int>v;

int a[1050],b[1050],n,m;
int t[1050][1050];
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)fin>>a[i];
    for(int i=1;i<=m;i++)fin>>b[i];
}

void mat()
{
    for(int i=1;i<=m;i++)
    {

        for(int j=1;j<=n;j++)
        {


                if(a[j]==b[i])
                {

                    t[i][j]=t[i-1][j-1]+1;
                    //cout<<a[j]<<" ";
                    v.push_back(a[j]);

                }
                else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
        }

    }
}


int main()
{

    citire();
    mat();
    fout<<t[m][n]<<'\n';
    for(auto &i:v)
        fout<<i<<" ";

    return 0;
}
