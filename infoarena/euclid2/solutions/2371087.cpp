#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    long long int n,j,c,a,b,cmmdc,i,f;
    fin>>n;
    for(j=1;j<=n;j++){
    fin>>a>>b;
    if(a>b) c=a;
    else c=b;
    for(i=1;i<=c;i++){
        if(a%i==0 && b%i==0) f=i;
    }
    fout<<f<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
