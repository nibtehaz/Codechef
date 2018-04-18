    #include<stdio.h>

    int main ()
    {
        int i,j,k,m,result;  // j->T , i -> N in question

        scanf("%d",&j);
        for(;j;j--)
        {
            m=5,result=0;
            scanf("%d",&i);
            for(;;){
                    k=i/m;
            result=result+k;
            m=m*5;
            if (i<m) break ;
              }
              printf("%d\n",result);

        }
        return 0;
    }
