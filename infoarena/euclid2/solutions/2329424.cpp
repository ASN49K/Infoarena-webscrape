#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin>>T;
    int a , b ,r;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        int cmmdc=b;
        fout<<cmmdc<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
