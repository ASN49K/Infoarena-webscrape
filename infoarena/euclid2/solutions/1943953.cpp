#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int long long a,b,r;
long T;

int main()
{
    fin>>T;
    for(long i=1;i<=T;i++){
        fin>>a>>b;

        if(a==0 || b==0) fout<<a+b<<"\n";
        else{
        r=a%b;

        while(r)a=b,b=r,r=a%b;

        fout<<b<<"\n";

        }
    }

}
