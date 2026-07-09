#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
int a,b,t,i;
fin>>t;
for(i=1;i<=t;i++){
    fin>>a;fout<<" ";
    fin>>b;
    fout<<endl;
    while(a!=b){
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    fout<<a;
}
    return 0;
}
