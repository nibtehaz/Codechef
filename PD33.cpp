#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
 
int main()
{
    int c,r,len,i,j;
    char inp[2000],mat[205][205];
 
    while(1)
    {
        scanf("%d",&c);
        if(c==0)
            break;
 
        scanf("%s",inp);
        len=strlen(inp);
        r=len/c;
 
        for(i=0;i<r;i++)
        {
            if(i%2==0)
            {
                for(j=0;j<c;j++)
                {
                    mat[i][j]=inp[i*c+j];
                }
            }
            else
            {
                for(j=0;j<c;j++)
                {
                    mat[i][j]=inp[i*c+c-j-1];
                }
            }
        }
 
 
        for(i=0;i<c;i++)
            for(j=0;j<r;j++)
            printf("%c",mat[j][i]);
        printf("\n");
 
    }
 
 
    return 0;
}