# include <iostream>
# include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b)
{
    if(b==0) return a;
    else return euclid(b,a%b);
}
int main()
{
    int i,a,b,n;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }
    fin.close();
}
