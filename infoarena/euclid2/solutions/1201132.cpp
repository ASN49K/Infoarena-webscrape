#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,t;fin>>t;while(fin>>a>>b){while(a!=b)if(a>b)a=a-b;else b=b-a;fout<<a<<"\n";}fin.close();fout.close();
    return 0;
}
