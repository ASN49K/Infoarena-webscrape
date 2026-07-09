#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b, n;
int GCD(int a, int b)
{
    if(!b)
        return a;
    return GCD(b, a%b);
}
int main()
{
    fin>>n;
    while(n>0){
            fin>>a;
            fin>>b;
        fout<<GCD(a,b)<<endl;
        n--;
    }

    return 0;
}
