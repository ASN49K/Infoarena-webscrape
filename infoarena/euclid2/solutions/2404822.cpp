#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
int a,b,t,i,r;
fin>>t;
for(i=1;i<=t;i++){
    fin>>a;fout<<" ";
    fin>>b;
    fout<<endl;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a;
}
    return 0;
}
