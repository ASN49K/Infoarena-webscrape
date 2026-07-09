#include <fstream>
#include <vector>

using namespace std;
ifstream in("hashuri.in");
ofstream out("hashuri.out");
const int MOD=66013;
int n;
vector<int>a[MOD];
vector<int>::iterator findval(int x)
{
    int hesh=x%MOD;
    vector<int>::iterator it;
    for(it=a[hesh].begin();it!=a[hesh].end();it++)
        if(*it==x)
            return it;
    return a[hesh].end();
}
void insertval(int x)
{
    int hesh=x%MOD;
    if(findval(x)==a[hesh].end())
        a[hesh].push_back(x);
}
void eraseval(int x)
{
    int hesh=x%MOD;
    vector<int>::iterator it=findval(x);
    if(it!=a[hesh].end())
        a[hesh].erase(it);
}

int main()
{
    int x,op;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>op>>x;
        if(op==1)
            insertval(x);
        else if(op==2)
            eraseval(x);
        else
            out<<(bool)(findval(x)!=a[x%MOD].end())<<'\n';
    }
    return 0;
}
