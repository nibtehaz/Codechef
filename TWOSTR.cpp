/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define MAX 105


int main()
{
    int T,i,len1,len2,test;
    char X[1005],Y[1005];

    scanf("%d",&T);
    gets(X);

    while(T--)
    {
        gets(X);
        gets(Y);

        len1=strlen(X);
        len2=strlen(Y);

        if(len1!=len2)
            test=0;
        else
        {
            test=1;

            for(i=0;i<len1;i++)
            {
                if((X[i]!=Y[i])&&(X[i]!='?')&&(Y[i]!='?'))
                {
                    test=0;
                    break;
                }
            }
        }

        if(test==1)
            printf("Yes\n");
        else
            printf("No\n");


    }

    return 0;

}



