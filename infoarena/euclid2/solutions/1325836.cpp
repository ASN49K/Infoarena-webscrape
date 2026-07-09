#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
struct T
{
    double a,b;
};

double n;
short i;
T c[100000];
void run(dobule x,double a,double b)
{
    short flag=0;
    double cmmdc=1;
    while((x>1)&&(cmmdc==1))
    {
        if((a%x==0)&&(b%x==0))cmmdc=x;
        x--;
    }

    g<<cmmdc<<endl;
}
void rez(double a,double b)
{

    if(a>b){
        run(b,a,b);
    }else{
        run(a,a,b);
    }

}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)f>>c[i].a>>c[i].b;
    for(i=1;i<=n;i++)rez(c[i].a,c[i].b);
    return 0;
}
