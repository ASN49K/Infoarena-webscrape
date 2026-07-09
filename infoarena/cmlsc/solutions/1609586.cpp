#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
int la,lb;
vector<int> a,b;
int sol[1028][1028];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    cin>>la>>lb;
    int i,j,x;
    a.push_back(0); b.push_back(0);
    for(i=1;i<=la;i++) { cin>>x; a.push_back(x); }
    for(i=1;i<=lb;i++) { cin>>x; b.push_back(x); }
    for(i=1;i<=la;i++)
        for(j=1;j<=lb;j++)
            if(a[i]==b[j]) sol[i][j]=sol[i-1][j-1]+1;
            else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);

    int p1=la,p2=lb;

    while(sol[p1][p2])
    {

        while( sol[p1-1][p2-1]==sol[p1][p2] ){ p1--; p2--; }
        while( sol[p1-1][p2]==sol[p1][p2] )  p1--;
        while( sol[p1][p2-1]==sol[p1][p2] ) p2--;
        s.push(p1);
        p1--;
    }

    cout<<sol[la][lb]<<'\n';
    while(!s.empty())
    {
        cout<<a[s.top()]<<' ';
        s.pop();
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
