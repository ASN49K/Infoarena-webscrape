#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("euclid2.in");
    ofstream outdata;
    outdata.open("euclid2.out");


    //----------------
    int t ;
    fin >> t;
    for(int i = 0; i < t; i++)
    {
    long a,b,c,d,rest;
    fin >> a >> b;
    rest= min(a,b);
    b = max(a,b);
    a = rest;
    rest=b%rest;

    while(rest!=0)
    {
        b = a;
        a = rest;
         rest= b % rest;

    }

    outdata  << a << endl;
    }

}
/*a 42  12    6
  b  12 42  12
rest    12  6  0



*/
