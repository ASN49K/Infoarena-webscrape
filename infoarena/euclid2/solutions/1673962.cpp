#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,c,r,i;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    cin>>c;
    for (i=1;i<=c;i++){
        cin>>a>>b;
        while (b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a;
    }
    return 0;
}
