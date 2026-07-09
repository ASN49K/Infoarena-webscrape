#include <iostream>
#include<fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int A[1026],B[1026],n,m,V[1026],r;
void citire(int A[1026],int n)
{
    for(int i=1;i<=n;++i)
        in>>A[i];
}
void afisare(int V[1026],int r)
{out<<r<<'\n';
    for(int i=1;i<=r;++i)
        out<<V[i]<<' ';
    out<<'\n';
}
void finish()
{int j=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(A[i]==B[j])
            V[++r]=A[i];
}


int main()
{in>>n;
in>>m;
citire(A,n);
citire(B,m);
finish();
afisare(V,r);
    return 0;
}
