#include <fstream>

using namespace std;

int main()
{
    long long t;
    int a,i,b,r;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(i=1;i<=t;i++){
        fin>>a>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
