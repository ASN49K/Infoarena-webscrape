#include<fstream>
using namespace std;
ifstream fi("nim.in");
ofstream fo("nim.out");

int T,i,n,s,x;

int main(){
    fi>>T;
    for(;T;T--)
       {
        fi>>n; s=0;
        for(i=1;i<=n;i++){
                          fi>>x;
                          s^=x;
                         }
        if(s>0) fo<<"DA\n";
        else fo<<"NU\n";
       }
    
    fi.close();
    fo.close();
    return 0;
}
