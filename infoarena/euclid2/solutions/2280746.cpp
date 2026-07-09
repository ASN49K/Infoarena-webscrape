#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long i,T,a,b,x,y,r;
int main()
{
    fin>>T;
    i=1;
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
