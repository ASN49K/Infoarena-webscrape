#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int a[1028],b[1028],sol[1028][1028],n,m;
stack<int>s;

int maxim(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

int main()
{
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                sol[i][j]=sol[i-1][j-1]+1;
            else
                sol[i][j]=maxim(sol[i-1][j],sol[i][j-1]);
    ofstream fout("cmlsc.out");
    fout<<sol[n][m]<<"\n";
    int i=n,j=m;
    while(sol[i][j])
    {
        if(a[i]==b[j])
        {
            s.push(a[i]);
            i--;
            j--;
        }
        else
            if(sol[i][j]==sol[i-1][j])
                i--;
            else
                j--;
    }
    while(!s.empty())
    {
        fout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
