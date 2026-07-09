# include <stdio.h>

# define input "euclid2.in"
# define output "euclid2.out"

int x,y,r;

int main()
{
    freopen(input, "r", stdin);
    freopen(output, "w",stdout);
    
    scanf("%d%d",&x,&y);
    
    while(y)
    {
           r = x%y;
           x=y;
           y=r;
    }
    
    printf("%d",x);
    
    return 0;
}
