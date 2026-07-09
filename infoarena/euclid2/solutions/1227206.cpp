#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long x,y,n,i;
long long cmmdc(int a, int b)
{
    int r;
    while(b)   {      r=a%b;  a=b;   b=r;   }
    return a;
}
int main(){
 f>>n;
 for(i=1;i<=n;i++){
 f>>x>>y;
 g<<cmmdc(x,y)<<'\n';
 }
return 0;
}
//#include <iostream>
//#include <fstream>
//using namespace std;
//ifstream f("euclid3.in");
//ofstream g("euclid3.out");
//int a1,a2,b1,b2;
//int xGood,yGood;
//int cmmdc1(int a,int b)   //cmmdc varianta mea!!!!!
//{
//    while(a)
//    {
//        if(a<b)swap(a,b);
//        a=a%b;
//    }
//    return b;
//}
//int cmmdc2(int a,int b)   //cmmdc varianta mea!!!!!
//{
//    while(b)
//    {
//        if(b<a)swap(a,b);
//        b=b%a;
//    }
//    return a;
//}
//int euclid_extins1(int a ,int b)//cu scaderi repetate  20p(timpul!!!!)
//{
//    a1=1,b1=0,a2=0,b2=1;
//    while (a&&b)
//    {
//        if (a>b)
//        {
//            a-=b;
//            a1-=a2;
//            b1-=b2;
//        }
//        else
//        {
//            b-=a;
//            a2-=a1;
//            b2-=b1;
//        }
//    }
//    if (a) xGood=a1,yGood=b1;
//    else xGood=a2,yGood=b2;
//    if (a) return a;
//    else return b;
//}
//
//
//int euclid_extins2(int a ,int b)//cu impartiri  repetate  100p
//{
//    a1=1,b1=0,a2=0,b2=1;
//    while (a&&b)
//    {
//        if (a>b)
//        {
//            a1-=a2*(a/b);
//            b1-=b2*(a/b);
//            a%=b;
//        }
//        else
//        {
//            a2-=a1*(b/a);
//            b2-=b1*(b/a);
//            b%=a;
//        }
//    }
//    if (a) xGood=a1,yGood=b1;
//    else xGood=a2,yGood=b2;
//    if (a) return a;
//    else return b;
//}
//
//
//
//
//int euclid_extins3(int a ,int b)//cu impartiri repetate 100p
//{
//    int sa1,sb1;  //a(a1,b1)   b(a2,b2)
//    a1=1,b1=0;    //a=1*a+0*b
//    a2=0,b2=1;    //b=0*a+1*b
//    int rest,cat;
//    while (b)
//    {
//        //if(a<b){ swap(a,b); swap(a1,a2); swap(b1,b2); }
//        rest=a%b;
//        cat=a/b;
//        a=b;
//        sa1=a1;
//        sb1=b1;
//        a1=a2;
//        b1=b2;//se salveaza (a1,b1) si a=b
//        b=rest;
//        a2=sa1-=cat*a2;
//        b2=sb1-=cat*b2;//se calculeaza noul b(a2,b2)
//    }                                 //impartire = scaderi repetate de "cat" ori
//    xGood=a1,yGood=b1;
//    return a;
//}
//
//int main()
//{
//    int i,nrt;
//    f>>nrt;
//
//    for(i=1; i<=nrt; i++)
//    {
//        int a,b,c;
//        f>>a>>b>>c;
//        int CMMDC=euclid_extins3(a,b);
//
//        if (c%CMMDC==0)
//        {
//            g<<xGood*(c/CMMDC)<<" "<<yGood*(c/CMMDC)<<'\n';
//        }
//        else
//            g<<0<<" "<<0<<'\n';
//    }
//    return 0;
//}
//#include <iostream> // var Dutu
//#include <fstream>
//using namespace std;
//ifstream f("euclid3.in");
//ofstream g("euclid3.out");
//int a1,a2,b1,b2;
//int xGood,yGood;
//int euclid_extins3(int a ,int b)//cu impartiri  repetate  100p
//{
//    a1=1,b1=0,a2=0,b2=1;
//    while (a&&b)
//    {
//        if (a>b)
//        {
//            a1-=a2*(a/b);
//            b1-=b2*(a/b);
//            a%=b;
//        }
//        else
//        {
//            a2-=a1*(b/a);
//            b2-=b1*(b/a);
//            b%=a;
//        }
//    }
//    if (a) xGood=a1,yGood=b1;
//    else xGood=a2,yGood=b2;
//    if (a) return a;
//    else return b;
//}
//
//
//int main()
//{
//    int i,nrt;
//    f>>nrt;
//    for(i=1; i<=nrt; i++)
//    {
//        int a,b,c;
//        f>>a>>b>>c;
//        if (c<0) a=-a,b=-b,c=-c;
//
//
//        int CMMDC=euclid_extins3(a>0?a:-a,b>0?b:-b);
//
//        if (a<0) xGood=-xGood;
//        if (b<0) yGood=-yGood;
//
//        if (c%CMMDC==0)
//        {
//            g<<xGood*(c/CMMDC)<<" "<<yGood*(c/CMMDC)<<'\n';
//        }
//        else
//            g<<0<<" "<<0<<'\n';
//    }
//    return 0;
//}


//#include <stdio.h>
//int a[100],x[100],n,i,k;
// int main(void){
//
// printf("n=");scanf("%d",&n);
// printf("Radacinile:\n");
// for(i=1;i<=n;i++){
//  printf("x[%d]=",i);scanf("%d",&x[i]);a[i]=0;
// }
// a[0]=1;a[n]=0;
// for(k=1;k<=n;k++){
//  for(i=k;i>=1;i--)
//	a[i]=a[i-1]-a[i]*x[k];
//  a[0]*=-x[k];
// }
// for(i=n;i>=0;i--) printf("a[%d]=%d ",i,a[i]);
// return 0;
//}
