//
//  main.cpp
//  infoarena
//
//  Created by Darius-George Oanea on 01/03/2019.
//  Copyright © 2019 Darius-George Oanea. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

//ifstream f("/Users/george/Library/Autosave Information/infoarena/infoarena/en.lproj/flip.in");
//ofstream g("/Users/george/Library/Autosave Information/infoarena/infoarena/flip.out");
int cmmdc(int a,int b)
{
    while(a!=b)
    {if(a>b)
        a=a-b;
    else
        b=b-a;}
    return a;
}
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
//    int sum = 0;
//    int n,m;
//    f>>n>>m;
//    int a[n][m];
//    for(int i=0;i<n;++i)
//        for(int j=0;j<m;++j)
//        {
//            f>>a[i][j];
//        }
//
//    for(int i=0;i<n;++i)
//    {int sum1=0;
//        int sum2=0;
//        int sum3=0;
//        for(int j=0;j<m;++j)
//        {
//            sum1+= a[i][j] * -1;
//            sum2+= a[i][j];
//            if(sum1>sum2)
//            {
//                a[i][j]*=-1;
//            }
//
//        }
//    }
//    for(int j=0;j<n;++j)
//    {   int sum1=0;
//        int sum2=0;
//        for(int i=0;i<m;++i)
//        {
//            sum1+= a[i][j] * -1;
//            sum2+= a[i][j];
//            if(sum1>sum2)
//            {
//                a[i][j]*=-1;
//            }
//
//        }
//    }
//
//    for(int i=0;i<n;++i)
//        for(int j=0;j<m;++j)
//        {
//            sum+=a[i][j];
//        }
//
//    g<< sum;
    int a,b;
    int t;
    f>>t;
    int contor=1;
    while(contor<=t)
    {
        f>>a>>b;
        g<<cmmdc(a, b)<<endl;
        contor++;
        
    }
}



