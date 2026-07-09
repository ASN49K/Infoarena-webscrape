#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("euclid2.in");
    ofstream outdata;
    outdata.open("euclid2.out");


    //----------------
    unsigned int t ;
    unsigned int a,b,rest;
    fin >> t;
    for(int i = 0; i < t; i++)
    {

    fin >> a >> b;
    //rest= min(a,b);
    //b = max(a,b);
    if(a<b)
    {
        rest = a;

    }
    else
    {
        rest = b;
        b = a;
    }
    do
    {
       a = rest;
        rest= b % rest;
        b = a;
    }
    while(rest!=0);


    outdata  << b << endl;
    }

}
/*a 42    12 6
 b  12 42 12 6
rest   12 6  0



*/
