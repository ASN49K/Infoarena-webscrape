#include <iostream>
#include <fstream>
using namespace std;
int a[10^5], b[10^5], T, i;
int main()
{
    fstream fin("euclid2.in", ios::in);
    fstream fout("euclid2.out", ios::out);
    fin>>T;
    for(i = 0; i < T; i++)
    {
        fin>>a[i]>>b[i];
        while(a[i] != b[i])
        {
            if(a[i] > b[i])
            {
                a[i] = a[i]-b[i];
            }
            else
            {
                b[i] = b[i]-a[i];
            }
        }
        fout<<a[i]<<endl;
    }

}
