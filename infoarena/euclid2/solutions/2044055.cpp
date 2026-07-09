#include <fstream>

using namespace std;

int divi2(int a, int b)
{
    if(!b) return a;
    return divi2(b , a % b);
}


int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin>>T;
    int a,b;
    for(int i = 0;i < T;i++)
    {
        fin>>a>>b;
        fout<<divi2(a,b)<<'\n';
    }
    return 0;
}
