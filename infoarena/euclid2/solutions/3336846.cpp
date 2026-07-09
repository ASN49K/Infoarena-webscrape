#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n,r,a,b;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>a>>b;
        while(b!=0){
             r=a%b;
             a=b;
             b=r;
        }
        fout<<a<<endl;
    }
    return 0;
}
