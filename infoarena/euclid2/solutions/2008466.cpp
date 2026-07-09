#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");
int n;
fin>>n;
for(int i=0;i<n;i++){
    int a ,b;
    fin>>a>>b;
    fout<<cmmdc(a,b)<<'\n';
}



    return 0;
}
