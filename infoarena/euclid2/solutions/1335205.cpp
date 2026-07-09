#include <iostream>
#include <fstream>
using namespace std;
int N,a,b;

int j,k,d=1;
int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
    fin>>N;
    for(int x=0;x<N;x++){
        fin>>a>>b;
        while(b!=0)
        {
d=b;
b=a%d;
a=d;

        }
        fout<<a<<"\n";


        }
    return 0;
}
