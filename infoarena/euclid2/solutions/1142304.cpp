#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}

int main()
 {
    long a,b,n;
    fin>>n;
    for(int i=1;i<=n;i++)
       {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
       }
    return 0;
    fin.close();
 }
