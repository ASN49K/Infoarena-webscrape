#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
    if(b == 0) return a;
    return cmmdc(b, a%b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t, temp1, temp2;
    fin>>t;
    for(;t> 0; t--)
    {
            fin>>temp1>>temp2;
            fout<<cmmdc(temp1, temp2)<<endl;
    }
    return 0;
}
