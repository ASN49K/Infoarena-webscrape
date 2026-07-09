# include <stdio.h>

# define input "euclid2.in"
# define output "euclid2.out"

int x,y,r,t;

int main()
{
    freopen(input, "r", stdin);
    freopen(output, "w",stdout);
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d%d",&x,&y);
    
    while(y)
    {
           r = x%y;
           x=y;
           y=r;
    }
    
    printf("%d\n",x);
    }
    
    return 0;
}
