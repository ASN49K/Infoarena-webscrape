#include <iostream>

using namespace std;

int main()
{
    int n,k,nr,i=1,min1=1000000,max1=-1,p1,p2;
    cin>>k;
    cin>>nr;
    if(nr==0)
    {
        cout<<"NU EXISTA";
        return 0;
    }
    while(nr)
    {
        if(nr%10==k && nr<min1)
        {
            min1=nr;
            p1=i;
        }
        if(nr%10==k && nr>max1)
        {
            max1=nr;
            p2=i;
        }
        cin>>nr;
        i++;
    }
    if(max1==-1)
        cout<<"NU EXISTA";
    else
    {
        if(p1>p2)
            cout<<p1-p2+1;
        else
            cout<<p2-p1+1;
    }
    return 0;
}
