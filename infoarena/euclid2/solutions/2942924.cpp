#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,x,y,i;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>x>>y;
        int r=x%y;
        while(r>0){
            x=y;
            y=r;
            r=x%y;
        }
        fout<<y<< '\n';
    }
    return 0;
}
