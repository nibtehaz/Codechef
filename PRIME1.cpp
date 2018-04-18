#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int sieve[100200]={0,},prime[32000];

int main()
{
    int primo=0,t,tp=1;
    long long int i,j,p,a,b;

    for(i=2;i<32000;i++)
    {
        if(sieve[i]==0)
        {
            prime[primo]=i;
            primo++;
            {
                for(j=i*i;j<34000;j+=i)
                    sieve[j]=1;
            }
        }
    }


    scanf("%d",&t);

    while(t--)
    {
        if(tp==0)
            printf("\n");
        tp=0;

        scanf("%lld%lld",&a,&b);

        if(a>b)
        {
            b=a^b;
            a=a^b;
            b=a^b;
        }

        for(i=0;i<100200;i++)
            sieve[i]=0;

        for(p=0;p<primo;p++)
        {
            i=a/prime[p];

            for(;;i++)
            {
                j=prime[p]*i;

                if(j>b)
                    break;

                if(j>=a&&i>1)
                    sieve[j-a]=1;
            }
        }
        b-=a;

        for(i=0;i<=b;i++)
        {
            if(i+a==1) continue;

            if(sieve[i]==0)
                printf("%lld\n",i+a);
        }


    }


    return 0;

}

