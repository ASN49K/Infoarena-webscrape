#include<fstream>
using namespace std;
long big_div(long a,long b)
{
    long r;
    do
    {
        r = a%b;
        a=b;
        b=r;
    }while(b);
    return a;
}
int main()
{
    long a,b,T;
    ifstream fin("euclid2.in");
    fin>>T;
    ofstream fout("euclid2.out");
    while(fin>>a>>b)
        fout<<big_div(a,b)<<endl;
    fin.close();
    fout.close();
    return 0;
}
