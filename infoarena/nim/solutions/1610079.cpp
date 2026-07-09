#include<iostream>
#include<fstream>
using namespace std;
int  s,a,shp,i,n;
int main()
{

    ifstream cin("nim.in");
    ofstream cout("nim.out");
    cin>>shp;
    while(shp)
    {

        cin>>n;
        s=0;
        for(i=1;i<=n;i++)
        {

            cin>>a;
            s=s^a;
        }
        if(s!=0)
            cout<<"DA";
        else cout<<"NU";
        cout<<"\n";
        shp--;
    }
}
