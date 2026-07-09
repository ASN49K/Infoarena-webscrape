#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b){
    if(b==0) return a;
    else {
        return cmmdc(b,a%b);
    }

}
  int t,i,a,b;
int main()
{
    fin>>t;
    for(i=0;i<t;i++){
        fin>>a>>b;

    fout<<cmmdc(a,b)<<"\n";
    }


}

