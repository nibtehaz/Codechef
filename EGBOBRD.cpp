/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    long long int N,K,A,pre,box,i;
    int t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&N,&K);
        pre=0;
        box=0;

        for(i=0;i<N;i++)
        {
            scanf("%lld",&A);

            if(A>pre)
            {
                A-=pre;
                box+=(A)/K;
                A%=K;

                if(A!=0)
                {
                    box++;
                    pre=K-A;
                }
                else
                    pre=0;

            }
            else if(A<=pre)
            {
                pre-=A;
            }

            if(pre>0)
                pre--;
        }
        printf("%lld\n",box);
    }


    return 0;
}
