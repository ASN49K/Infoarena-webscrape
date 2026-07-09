#include<fstream>
#include<iostream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int a[10005];
int t,n;

void NIM(int n)
{
    if(n==1){
        g<<"DA\n";
        return;
    }
    int var,i;
    var=a[1] ^ a[2];
    for(i=3;i<=n;i++)
        var=var ^ a[i];
    if(var!=0)
        g<<"DA\n";
    else
        g<<"NU\n";
}

int main()
{
    int i,j;
    f>>t;
    for(i=0;i<t;i++){
        f>>n;
        for(j=1;j<=n;j++)
            f>>a[j];
        NIM(n);
    }

}

