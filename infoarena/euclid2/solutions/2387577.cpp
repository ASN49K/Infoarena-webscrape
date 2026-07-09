#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long euclid(long long a,long long b)
{   long long c;
    while (b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
    
}
int main()
{   long long a,b,t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b);
        fout<<'\n';
        
    }
    return 0;
}
