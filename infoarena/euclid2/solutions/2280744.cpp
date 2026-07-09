#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long i=0,T,a,b,x,y,r;
int main()
{
    fin>>T;
    while(i<=T){
        fin>>a>>b;
        x=a; y=b;
        while(y!=0){
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
        i++;
    }
    fin.close(); fout.close();
    return 0;
}
