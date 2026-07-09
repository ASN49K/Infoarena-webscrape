/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#if 1
ifstream fin("euclid2.in");
ofstream fout("euclid2.in");
#define cout fout
#define cin fin
#endif 
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << "\n";
    }
    return 0;
}
