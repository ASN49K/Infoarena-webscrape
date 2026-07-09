#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("cmmdc.in");
    ofstream outdata;
    outdata.open("cmmdc.out");


    //----------------


    long a,b,c,d,rest;
    fin >> a >> b;
    c= min(a,b);
    d= max(a,b);
    rest=d%c;

    while(rest!=0)
    {

        a = c % rest;
        c = rest;
        rest = a;
    }

    outdata  << c << endl;


}
