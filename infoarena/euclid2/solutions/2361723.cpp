////
////  main.cpp
////  infoarena
////
////  Created by Darius-George Oanea on 01/03/2019.
////  Copyright © 2019 Darius-George Oanea. All rights reserved.
////
//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
////ifstream f("/Users/george/Library/Autosave Information/infoarena/infoarena/en.lproj/flip.in");
////ofstream g("/Users/george/Library/Autosave Information/infoarena/infoarena/flip.out");
//int cmmdc(int a,int b)
//{
//    if (!b) return a;
//    return cmmdc(b, a % b);
//}
//ifstream f("euclid2.in");
//ofstream g("euclid2.out");
//int main()
//{
////    int sum = 0;
////    int n,m;
////    f>>n>>m;
////    int a[n][m];
////    for(int i=0;i<n;++i)
////        for(int j=0;j<m;++j)
////        {
////            f>>a[i][j];
////        }
////
////    for(int i=0;i<n;++i)
////    {int sum1=0;
////        int sum2=0;
////        int sum3=0;
////        for(int j=0;j<m;++j)
////        {
////            sum1+= a[i][j] * -1;
////            sum2+= a[i][j];
////            if(sum1>sum2)
////            {
////                a[i][j]*=-1;
////            }
////
////        }
////    }
////    for(int j=0;j<n;++j)
////    {   int sum1=0;
////        int sum2=0;
////        for(int i=0;i<m;++i)
////        {
////            sum1+= a[i][j] * -1;
////            sum2+= a[i][j];
////            if(sum1>sum2)
////            {
////                a[i][j]*=-1;
////            }
////
////        }
////    }
////
////    for(int i=0;i<n;++i)
////        for(int j=0;j<m;++j)
////        {
////            sum+=a[i][j];
////        }
////
////    g<< sum;
//    int a,b;
//    int t;
//    f>>t;
//    int contor=1;
//    while(contor<=t)
//    {
//        f>>a>>b;
//        g<<cmmdc(a, b)<<endl;
//        contor++;
//
//    }
//}
//
//
//
#include <stdio.h>

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
    
    return 0;
}
