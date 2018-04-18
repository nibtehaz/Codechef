#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
   int t,x,y,ans;

   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&x,&y);

       if(x%2==0)
            ans=x*2;
       else
        ans=x*2-1;

       if(y==x)
        printf("%d\n",ans);
       else if(y==(x-2))
        printf("%d\n",ans-2);
       else
        printf("No Number\n");

   }
    return 0;
}




