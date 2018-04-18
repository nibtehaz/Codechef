#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char fact[105][160];

int main()
{
    int t,n,i,j,carry,temp;

   fact[0][0]='1';
    for(i=1;i<160;i++)
        fact[0][i]='0';


  for(i=1;i<101;i++)
    {
        for(j=0;j<160;j++)
            fact[i][j]=fact[i-1][j];



        carry=0;
        for(j=0;j<160;j++)
        {
            temp=((fact[i][j]-48)*i)+carry;
            if(temp>9)
            {
                carry=temp/10;
                temp=temp%10;
            }
            else
                carry=0;

            fact[i][j]=temp+48;
        }
    }

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(i=159;i>=0;i--)
        {
            if(fact[n][i]!='0')
                break;
        }
        for(;i>=0;i--)
            printf("%c",fact[n][i]);

        printf("\n");
    }





    return 0;

}

