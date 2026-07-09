#include <fstream>

using namespace std;

long long cmmdc(long long a,long long b)
{
    while(a!=b){
        if(a>b)
            a-=b;
        else
            b-=a;
    }

    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long long t,i,a,b;

    fin>>t;

    for(i=1;i<=t;i++){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }

    return 0;
}
