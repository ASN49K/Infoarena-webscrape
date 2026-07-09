#include <iostream>
using namespace std;

int main()
{

    int v[100], n , poz;

    cin>>n>>poz;

    for(int i=1; i<=n; i++)
    {

        cin>>v[i];
    }

    for(int i=poz; i<n; i++)
    {

        v[i] = v[i+1];
    }

    n--;

    for(int i=1; i<=n; i++)
    {

        cout<<v[i]<<" ";
    }

    return 0;
}
