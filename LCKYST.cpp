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
    int T,two,five;
    long long int N,temp;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%lld",&N);

        temp=N;

        two=0;
        five=0;
        while(1)
        {
            if(temp%2==0)
            {
                two++;
                temp/=2;
            }
            else
                break;
        }

        while(1)
        {
            if(temp%5==0)
            {
                five++;
                temp/=5;
            }
            else
                break;
        }


        if(two>=five)
            printf("%lld\n",N);
        else
        {
            five-=two;

            two=five/2;

            if(five%2!=0)
                two++;

            while(two--)
                N*=4;

            printf("%lld\n",N);
        }

    }

    return 0;

}



