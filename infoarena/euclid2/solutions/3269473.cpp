#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int c;
    fin>>c;
    for(int i=0; i<c; i++){
        int n, m;
        fin>>n>>m;
        while(n!=m){
            if(n>m){
                n-=m;
            }else{
                m-=n;
            }
        }
        fout<<n;
    }
    return 0;
}
