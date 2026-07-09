#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int T, a, b;
    fin>>T;
    while(T!=0)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        fout<<a<<endl;
        T--;
    }
    return 0;
}
