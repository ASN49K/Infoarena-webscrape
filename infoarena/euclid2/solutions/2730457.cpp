#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long int cmmdc(long int num1, long int num2){
long int m = min(num1, num2);
long int M = max(num1, num2);
long int r = M%m;
while(true){
    r = M%m;
    M=m;
    m=r;
    if(r==0){
        return M;
    }
}
}
int main()
{
    int n;
    fin>>n;
    for(long int j=0; j<n; j++){
    long int a, b;
    fin>>a>>b;
        fout<<cmmdc(a, b)<<"\n";
    }
}
