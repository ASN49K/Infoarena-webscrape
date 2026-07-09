#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a;
vector <int> sol;
int ma[1040][1040], poz, n, m, I[1040], J[1040];
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>J[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>I[i];
    }
//   cout<<J[2];

//cout<<I[1]<<J[1];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(I[i]==J[j])
                ma[i][j]=ma[i-1][j-1]+1;
            else
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);



        }
    poz=ma[m][n];
    fout<<poz<<'\n';
    while(poz)
    {
        if(ma[m-1][n-1]+1==poz && I[m]==J[n])
        {
            poz--;
            m--;
            n--;
            sol.push_back(I[m+1]);
           // cout<<I[m]<<' '<<J[n]<<endl;
        }
        else if(ma[m-1][n]== poz)
        {
            m--;
        }
        else if(ma[m][n-1]== poz)
        {
            n--;
        }
    }
    for(int i=sol.size()-1; i>=0; i--)
        fout<<sol[i]<<" ";
    return 0;
}
