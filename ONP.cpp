#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int t,len,i,j,b1,b2,sig,pos[1000];
    char inp[1000],sign[1000];

   scanf("%d",&t);

    while(t--)
    {
        scanf("%s",inp);
        len=strlen(inp);

        while(1)
            {
                b1=len+1;
                for(i=0;i<len;i++)
                {
   //                printf("%s\n",inp);
                    if(inp[i]=='(')
                        b1=i;
                    if(inp[i]==')')
                    {
                        b2=i;
                        inp[b1]=' ';
                        sig=0;
                        for(j=b2-1;j>b1;j--)
                        {
                            if((inp[j]<=122)&&(inp[j]>=97))
                                continue;
                            else if(inp[j]!=' ')
                            {
                              //  sign[sig]=inp[j];
                                //pos[sig]=j;
                                //sig++;
                                inp[b2]=inp[j];
                                for(;j<b2;j++)
                                {
                                    inp[j]=inp[j+1];
                                }

                                inp[b2]=' ';


                                break;

                            }
                        }

//    printf("%d\t%c\n",b2,inp[b2]);
 //   printf("%d\t%c\n",b2-1,inp[b2-1]);

                        for(j=b1;j>=0;j--)
                        {
                     //       printf("%d\t%c\n",j,inp[j]);
//                            printf("%s\n",inp);

                            if((inp[j]<=122)&&(inp[j]>=97))
                                continue;
                            if(inp[j]=='(')
                                break;
                            else if(inp[j]!=' ')
                            {
   //                             printf("aschi\n");

     //                       printf("%d\t%c\n",j,inp[j]);
                                inp[b2]=inp[j];
                                inp[j]=' ';
                                break;
                            }
                        }


                       // inp[pos[sig/2]]='0';
                        //inp[b2]=sign[sig/2];
                        break;

                    }
                }
                if(b1==len+1)
                    break;
            }
        for(i=0;i<len;i++)
        {
            if(inp[i]==' ')
                continue;
            else
                printf("%c",inp[i]);
        }
        printf("\n");
    }
    return 0;
}




