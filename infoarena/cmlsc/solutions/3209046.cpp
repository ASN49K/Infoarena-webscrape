#include <fstream>
#include <vector>
using namespace std;

int main() 
{
    ifstream in;
    ofstream out;
    int v1[1024];
    vector<int> v2;
    
    int m, n, a;
    
    cin>>m>>n;
    
    for(int i = 0; i < m; i++)
    {
        cin>>v1[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        for(int i = 0; i < m; i++)
        {
            if(v1[i] == a) v2.push_back(a);
        }
    }
    
    out<<v2.size()<<endl;
    
    for(int i = 0; i < v2.size(); i++)
    {
        out<<v2[i]<<" ";
    }
    
    in.close();
    out.close();
    return 0;
}