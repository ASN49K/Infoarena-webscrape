#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t,c;
    fin>>t;
    while(t>0)
    {
        t--;
        fin>>a>>b;
        while(b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        fout<<a;
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
