#include <fstream>
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");
using namespace std;

int main()
{
int a,b,t,i;
fin>>t;
for(i=1;i<=t;i++){
    fin>>a>>b;
    while(a!=b){
        if(a>b)
            a-=b;
        else
            b-=a;
    }
        fout<<a<<endl;
}

    return 0;
}
