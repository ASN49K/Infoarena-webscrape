#include <iostream>
#include <fstream>
using namespace std;

int main()
{   int i, j, a[20],b[20],c[20], m, n, cont;

    ifstream f; ofstream g;
    f.open("cmlsc.in"); g.open("cmlsc.out");
    f>>m>>n;

    for(i=1;i<=m;i++){
        f>>a[i];
    }
    for(i=1;i<=n;i++){
        f>>b[i];
    }

    j=1; cont=0;
    while(j<=m)
    {

        i=1;
        while(i<=n)
        {
            if(a[j]==b[i])
            {cont++; c[cont]=a[j]; break;}

            i++;
        }

        j++;
    }

    g<<cont<<"\n";
    for(i=1;i<=cont;i++){g<<c[i]<<" ";}
    f.close(); g.close();



    return 0;
}
