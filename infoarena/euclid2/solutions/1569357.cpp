#include<fstream>

#define s second
#define f first

using namespace std;

ifstream in ("euclid2.in");

ofstream out ("euclid2.out");

double v[100002],r[100002];

int n;

int main(){

    in>>n;

    for(int i=0;i<n;i++)
        in>>v[i]>>r[i];

    for(int i=0; i<n;i++)
        while(v[i]!=0 && r[i]!=0)
            if(v[i]>r[i])
                v[i]=v[i]%r[i];
            else
                r[i]=r[i]%v[i];

    for(int i=0;i<n;i++)
        out<<max(v[i],r[i]);

    out.close();

    return 0;
    }
