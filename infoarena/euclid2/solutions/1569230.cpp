#include<fstream>
#include<utility>

#define ll long long
#define s second
#define f first

using namespace std;

ifstream in ("euclid2.in");

ofstream out ("euclid2.out");

pair <ll,ll> v[100002];

int n,r[100002];

int main(){

    in>>n;

    for(int i=0 ; i<n;i++)
        in>>v[i].f>>v[i].s;

    for(int i=0; i<n;i++)
        while(v[i].s!=0 && v[i].f!=0)
        if(v[i].f>v[i].s)
            v[i].f%=v[i].s;
        else
            v[i].s%=v[i].f;

    for(int i=0;i<n;i++)
        out<<max(v[i].f,v[i].s);

    out.close();


    return 0;
    }
