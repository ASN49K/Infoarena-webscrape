#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int long long a,b;
long T;

int main()
{
    fin>>T;
    for(long i=1;i<=T;i++){
        fin>>a>>b;

        if(a==0 || b==0) fout<<a+b<<"\n";
        else{

        while(a!=b){

            if(a>b)a-=b;
            else b-=a;

        }

        fout<<a<<"\n";

        }
    }

}
