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
    int a,b,rest;
    for(int i = 0; i < t; i++)
    {
    fin >> a >> b;

    rest = a % b;

    while(rest!=0)
    {

        a = b % rest;
        b = rest;
        rest = a;
    }

    outdata  << b << endl;
    }

}
