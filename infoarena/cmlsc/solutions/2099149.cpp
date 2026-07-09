#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[10005],b[10005],n,m,k,j;
vector <int> c;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++){
        in>>a[i];
    }
    for(int i=1;i<=m;i++){
        in>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]) {c.push_back(a[i]);}
        }
    }
    vector<int>::iterator it;
    out<<c.size()<<'\n';
    for(it=c.begin();it!=c.end();it++){
        out<<*it<<' ';
    }
    return 0;
}
