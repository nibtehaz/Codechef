/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);

int main()
{
    int M,x,y,T,i,m,p,cnt;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d",&M,&x,&y);
        p=x*y;
        int safe[105]={0,};
        cnt=100;

        while(M--)
        {
            scanf("%d",&m);

            for(i=m-p;i<=(m+p);i++)
            {
                if(i<=0)
                    continue;
                if(i>100)
                    continue;
                if(safe[i]==0)
                {
                    cnt--;
                    safe[i]=1;
                }
            }
        }

        printf("%d\n",cnt);
    }

}

