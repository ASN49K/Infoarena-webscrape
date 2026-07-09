#include <iostream>
#include <fstream>
#define maxn 1024


int x,y, a[maxn], b[maxn], c[maxn][maxn], sir[maxn],jj;

using namespace std;

int main() {
    ifstream input;
    ofstream output;
    input.open("cmlsc.in");
    output.open("cmlsc.out");
    input >> x >> y;
    int i=1;
    for (;i<=x;i++) {
        input >> a[i];
    }
    for (i=1;i<=y;i++){
        input >> b[i];
    }
    int j=1;
    int maxx=0;
    for  (i=1;i<=x;i++)
     for (j=1;j<=y;j++) {
       if (a[i]==b[j])
        c[i][j]=1+c[i-1][j-1];
        else
        c[i][j]=max(c[i-1][j],c[i][j-1]);
       if (c[i][j]>maxx)  maxx=c[i][j];
     }
     int ind=maxx;
     jj=1;

    for  (i=x+1,j=y+1;ind!=0;)
       {
           if (a[i]==b[j]&&c[i][j]==ind) {
                 sir[ind--]=a[i];
                 i--;
                 j--;
           }
                else
            if (c[i-1][j]==ind) i--; else
            j--;

       }

    output << maxx << "\n";

    for (i=1;i<=maxx;i++)
     output<< sir[i] << " ";
    output.close();
    return 0;
}
