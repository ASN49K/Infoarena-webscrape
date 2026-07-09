#include <fstream>

using namespace std;

FILE* F(fopen("euclid2.in", "r"));
//ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

void euclid( int a , int b)
{
    int r;
        r=a%b;
    while(r!=0)
    {

        a=b;
        b=r;
        r=a%b;


    }
    fout<<b<<endl;
}

int main()
{
    int a , b , t;
    fscanf(F, "%d" , &t);
    for(int i=1;i<=t;i++)
    {
        fscanf(F,"%d  %d", &a, &b);
        euclid(a,b);

    }
    return 0;
}
