#include <fstream>

 using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[1030],y[1030],a[1030][1030];

 void afisare(int i, int j)
 {
     if(a[i][j])
     {
         if(x[i]==y[j])
         {
             afisare(i-1,j-1);
             g<<x[i]<<" ";
         }
         else
            if(a[i-1][j]>a[i][j-1])
                afisare(i-1,j);
            else
                afisare(i,j-1);
     }
 }
 int main()
 {
     int xx,yy;

     f>>xx>>yy;
     for(int i=1;i<=xx;++i)
        f>>x[i];
     for(int i=1;i<=xx;++i)
        f>>y[i];
    for(int i=1;i<=xx;++i)
        for(int j=1;j<=yy;++j)
            if(x[i]==y[j])
                a[i][j]=1+a[i-1][j-1];
            else
            {
                if(a[i-1][j]>a[i][j-1])
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=a[i][j-1];
            }
    g<<a[xx][yy]<<"\n";
    afisare(xx,yy);
    return 0;
 }
