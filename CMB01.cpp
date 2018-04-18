#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

unsigned long long int revert (unsigned long long int num);

int main()
{
    int T;
    unsigned long long int a,b,c;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%llu%llu",&a,&b);

        c=revert(a)+revert(b);
        printf("%llu\n",revert(c));
    }


    return 0;

}



unsigned long long int revert (unsigned long long int num)
{
    unsigned long long int pum=0;

    for(;;)
    {
        pum=(pum*10)+(num%10);
        num/=10;
        if(num==0)
            break;
    }
    return pum;
}
