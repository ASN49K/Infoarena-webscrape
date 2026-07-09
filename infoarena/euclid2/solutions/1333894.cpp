#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int main()
{   int i;
    fin>>n;
     for(i=1; i<=n; i++){
         int a,b,r;
            fin>>a>>b;
            while (b){
            r=b;
            b=a%b;
            a=r;
        }
    fout<<a<<'\n';
        }
    return 0;
}
