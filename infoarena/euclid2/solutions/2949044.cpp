/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;
int a,b,tmp;
int main()
{
    fin >>T;
    while (T!=0)
    {
        fin>>a>>b;
        while (b>0)
        {
            tmp=b;
            b=b%a;
            a=tmp;
        }
        fout <<a <<"\n";
        T--;
    }
    
    return 0;
}
