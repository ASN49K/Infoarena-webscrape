#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,b[1025],a[1025],v[1025][1025],i,j,k,poz,min1;
stack<int>s;

int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
    i=n;
    j=m;
    while(i&&j){
        if(a[i]==b[j]){
            s.push(a[i]);
            i--;
            j--;
        }
        else{
            if(v[i-1][j]>v[i][j-1])
                i--;
            else
                j--;
        }
    }
    out<<s.size()<<endl;
    while(!s.empty()){
        out<<s.top()<<" ";
        s.pop();
    }
    return 0;
}