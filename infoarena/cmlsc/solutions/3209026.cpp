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
        v2.push_back(a);
    }
    
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(v1[i] == v2[j]) cout<<v1[i]<<" ";
        }
    }
    
    return 0;
}