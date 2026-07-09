#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
void cmmdc()
{
    int a,b;
    while(a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        else
        {
            b-=a;
        }
    }
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,i;
    in>>n;
    cmmdc();
    return 0;
}
