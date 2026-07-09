/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    int r;
    r = a%b;
    while(r)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main()
{
    int t, a, b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
