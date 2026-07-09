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
    long a,b,c,d,rest;
    for(int i = 0; i < t; i++)
    {
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

}
