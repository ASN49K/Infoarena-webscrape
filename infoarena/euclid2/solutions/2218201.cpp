#include <iostream>
#include <fstream>

using namespace std;

int divizor(int x, int y){
int i,z=1;
if (x<y) {i=x;x=y;y=i;};
for (i=1;i<=y;++i)
    if (x%i==0 && y%i==0)  z=i;
return z;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t,i;
    cin >> t;
    for (i=0;i<t;++i){
        cin >> a >> b;
        while(a!=b)
        {
            if(a>b) a=a-b;
            else b=b-a;
        }
        cout << a << "\n";
    }

    return 0;
}
