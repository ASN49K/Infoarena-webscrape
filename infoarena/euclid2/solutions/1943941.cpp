#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long T,a,b;


int main()
{
    fin>>T;
    for(long i=1;i<=T;i++){
        fin>>a>>b;

        while(a!=b){
            if(a>b)a-=b;
            else b-=a;
        }

        fout<<a<<"\n";
    }

}
