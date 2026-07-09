#include <iostream>
#include <fstream>
#include <bitset>
#define limit 2000000000

using namespace std;

ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");


bitset <50000> f;
int p[5005], pp;
int n, a, b, ok, sol;

int main (){
    f[0]=f[1]=1;
    for(int i=4; i<=limit/i; i+=2)
        f[i]=1;

    for(int i=3; i<=limit/i; i+=2){
        if(f[i] == 0)
            for(int j=i*i; j<=limit/j; j+=i)
                f[j]=1;
    }
    p[++pp]=2;
    for(int i=3; i<=limit/i; i+=2)
        if(f[i] == 0)
            p[++pp]=i;

    fin>>n;
    for(int i=1; i<=n; i++){
        fin>>a>>b;
        if(a > b)
            swap(a, b);

        ok=0; sol=1;
        for(int j=1; j<=pp; j++)
            while(a%p[j] == 0 && b%p[j] == 0){
                a/=p[j];
                b/=p[j];
                sol*=p[j];
            }
        if(a != 1)
            if(b%a == 0)
                sol*=a;

        fout<<sol<<"\n";
    }
    return 0;
}
