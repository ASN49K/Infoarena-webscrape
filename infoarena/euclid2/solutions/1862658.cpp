#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a,b,x,T,i;
    fin>>T;
    for(i=0;i<T;i++){
        fin>>a>>b;
        while(a%b!=0){
            a=a%b;
            x=a;
            a=b;
            b=x;
        }
        fout<<b<<"\n";
    }
    return 0;
}
