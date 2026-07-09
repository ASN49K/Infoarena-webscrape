#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long a, b, n, r;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a>>b;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }

    return 0;
}
