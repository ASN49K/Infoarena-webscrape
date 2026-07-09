/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,a,b,tmp;

int main()
{
    fin>>T;
        while(T!=0)
        {
            fin>>a>>b;
                while(b!=0)
            {
                tmp=b;
                b=a%b;
                a=tmp;
            }
            --T;
            fout<<a<<"\n";
        }

    return 0;
}
