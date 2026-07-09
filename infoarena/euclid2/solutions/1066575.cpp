#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
    if(a == 0) return b;
    return cmmdc(b%a, a);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t, temp1, temp2;
    fin>>t;
    for(int i=0; i< t; i++)
    {
            fin>>temp1>>temp2;
            fout<<cmmdc(temp1, temp2)<<endl;
    }
    system("pause");
    return 0;
}
