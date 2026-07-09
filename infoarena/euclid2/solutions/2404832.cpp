#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
int a,b,t,i=1,r;
fin>>t;
while(i<=t){
    fin>>a>>b;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<endl;
    i++;
}
    return 0;
}
