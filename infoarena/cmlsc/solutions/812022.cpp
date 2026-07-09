#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int x[1025];
int x2[1025];
int mat[1025][1025];

void citire (int a,int b)
{
    int i,j;
    for (i=1;i<=a;i++)
    {
        in>>x[i];
    }
    for (i=1;i<=b;i++)
    {
        in>>x2[i];
    }
}


void rezolvare (int a,int b)
{
    int i,j;
    for (i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            if (x[i]==x2[j]) mat[i][j]=mat[i-1][j-1]+1;
            else if (x[i]!=x2[j]) mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }


}

int max(int a,int b)
{
    if (a>b) return a;
    if (b>a) return b;


}

int elemente (int a,int b)
{
    int g,ok=0,i,j;

    for (i=1;i<=a;i++)
    {
        for (j=1;j<=b;j++)
        {
            if (ok==0) {g=mat[i][j]; ok=1;}
            if (mat[i][j]>g)g=mat[i][j];
        }
    }
return g;
}

void afisare(int a,int b,int ok)
{
    int i,j,k=1;
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=b;j++)
        {
            if (mat[i][j]==k)
            {
             if (ok==1)   out<<x[i]<<" ";
             else out<<x2[j]<<" ";
                k=k+1;
            }
        }
    }


}


int main()
{
   int a,b,ok=0;
   in>>a>>b;
   if (a>b) ok=1;
   citire (a,b);
   rezolvare(a,b);
   out<<elemente(a,b)<<"\n";

   afisare (a,b,ok);


return 0;
}
