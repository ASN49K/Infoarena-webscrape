#include <iostream>
#include <fstream>

using namespace std;

int main()
{   int n,nr=1;
    int a,b,r;
//    cout << "Hello world!" << endl;
    fstream f1 ("euclid2.in",ios::in);
    fstream f2 ("euclid2.out",ios::out);
//    f1<<"A venit toamna";
f1>>n;
while(nr<=n)
{f1>>a;f1>>b;
while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    f2<<a<<"\n";
    nr++;
}


    f1.close();
    f2.close();
    return 0;
}
