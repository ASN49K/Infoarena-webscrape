#include <iostream>
#define Nmax 1025
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[Nmax],b[Nmax];
int s[Nmax][Nmax];
vector <int> sol;
void read()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];

}

void solve()
{
    int i,j;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
            {
                s[i][j]=s[i-1][j-1]+1;
                sol.push_back(a[i]);
            }


            else
                if(s[i-1][j]>s[i][j-1])

                    s[i][j]=s[i-1][j];

                else
                 s[i][j]=s[i][j-1];




}
int main()
{
    read();
    solve();
    fout<<s[n][m]<<"\n";
    for(unsigned int i=0;i<sol.size();i++)
        fout<<sol[i]<<" ";
    return 0;
}
