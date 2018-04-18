#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
 
 
 
int main()
{
    int num;
    
    while(1)
    {
        scanf("%d",&num);
        if(num==42)
            break;
        else
            printf("%d\n",num);
    }
 
    return 0;
 
}