#include<stdio.h>
#include<iostream.h>

main()
{
  freopen("euclid2.in","r",stdin);
  freopen("euclid2.in","w",stdout);

  int t,a,b,c;

  scanf("%d",&t);

  while(t--)
  {
    scanf("%d %d", &a, &b);

    while(!b)
    { c=b; b=a%b; a=b; }

    printf("%d\n",&a);
  }


  return 0; }