#include<fstream>

#define s second
#define f first

using namespace std;

ifstream in ("euclid2.in");

ofstream out ("euclid2.out");

pair <short,short> v[100001];

int n;

int main(){

    in>>n;

    for(int i=0 ; i<n;i++)
        in>>v[i].f>>v[i].s;

    for(int i=0; i<n;i++)
        while(v[i].s!=0 && v[i].f!=0)
            if(v[i].f>v[i].s)
                v[i].f=v[i].f%v[i].s;
            else
                v[i].s=v[i].s%v[i].f;

    for(int i=0;i<n;i++)
        out<<max(v[i].f,v[i].s);

    out.close();

    return 0;
    }
