#include <iostream>
#include <fstream>
using namespace std;
int t,sxor,x,n;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main(){
    fin>>t;
    for(int q=1;q<=t;q++){
        fin>>n;
        sxor=0;
        for(int i=1;i<=n;i++){
            fin>>x;
            sxor^=x;
        }
        if(sxor)
            fout<<"DA"<<"\n";
        else
            fout<<"NU"<<"\n";

    }



    return 0;
}
