#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<int> v1;
    vector<int> v2;
    
    long long m, n, a;
    
    cin>>m>>n;
    
    for(int i = 0; i < m; i++)
    {
        cin>>a;
        v1.push_back(a);
    }
    
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        for(int i = 0; i < m; i++)
        {
            if(v1[i] == a) cout<<a<<" ";
        }
    }

    
    return 0;
}