#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
int a,b,t,i=1,r;
fin>>t;
while(i<=t){
    fin>>a;fout<<" ";
    fin>>b;
    fout<<endl;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a;
    i++;
}
    return 0;
}
