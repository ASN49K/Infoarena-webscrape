#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int i,n,a,b;

int euclid(int a,int b){
    if(a>b)
        return (a-b,b);
    else
        if(b>a)
            return (a,b-a);
        else
            return a;
}

int main()
{
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }
    return 0;
}
