#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int T,a,b;
    fin>>T;
    while(fin>>a>>b&&T!=0)
    {
        while(a!=b)
        {
            if(a<b)
                b=b-a;
            else
                a=a-b;
        }
        fout<<a<<endl;
        T--;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
