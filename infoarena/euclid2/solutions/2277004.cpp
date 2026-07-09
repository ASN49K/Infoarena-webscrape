#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b,c;
int main(){
    fin>>t;
    for(;t--;){
       fin>>a>>b;
       while(b){
          c=a%b;
          a=b;
          b=c;
       }
       fout<<a<<"\n";
    }
    return 0;
}
