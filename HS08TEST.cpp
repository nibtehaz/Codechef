    #include<stdio.h>

    int main ()
    {
        int x;
        double y;

        while(scanf("%d%lf",&x,&y)!=EOF)
    {

        if(x%5!=0)
            printf("%.2lf\n",y);
        else if(x+0.5>y)
            printf("%.2lf\n",y);
        else
            printf("%.2lf\n",y-x*1.0-0.5);

    }
        return 0;
    }
