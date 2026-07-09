#include <iostream>

int main()
{
    int n;
    std::cin>>n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin>>a>>b;
        while(b)
        {
            const int r = a % b;
            a = b;
            b = r;
        }
        std::cout<<a<<"\n";
    }

    return 0;
}
