#include <iostream>
#include <fstream>
using namespace std;
int n,a,b,r;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a;
        fin>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;

    }
    fin.close();
    fout.close();


    return 0;
}
