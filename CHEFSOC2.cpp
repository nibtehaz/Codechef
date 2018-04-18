/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("A-large (2).in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back

#define INF 1000000000

long long int memo[1005][2];

int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T;
    int i,j,p;
    int N,M,s,a,b;
    int A[1005];

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(M)
        getInt(s)

        for(i=0;i<M;i++)
            getInt(A[i]);

        for(i=0;i<=N;i++)
        {
            memo[i][0]=0;
            memo[i][1]=0;
        }

        memo[s][0]=1;

        /*printf("%d",memo[1][0]);

        for(i=2;i<=N;i++)
            printf(" %d",memo[i][0]);
        printf("\n");*/


        for(j=0;j<M;j++)
        {
            if(j%2==0)
            {
                for(i=1;i<=N;i++)
                {
                    memo[i][1]=0;
                    a=0;
                    b=0;

                    p=i-A[j];
                    if(p>0)
                        a=memo[p][0];

                    p=i+A[j];
                    if(p<=N)
                        b=memo[p][0];

                    memo[i][1]=(a+b)%MOD;
                }

                /*printf("%d",memo[1][1]);

                for(i=2;i<=N;i++)
                    printf(" %d",memo[i][1]);
                printf("\n");*/
            }

            else
            {
                for(i=1;i<=N;i++)
                {
                    memo[i][0]=0;
                    a=0;
                    b=0;


                    p=i-A[j];
                    if(p>0)
                        a=memo[p][1];

                    p=i+A[j];
                    if(p<=N)
                        b=memo[p][1];

                    memo[i][0]=(a+b)%MOD;
                }

                /*printf("%d",memo[1][0]);

                for(i=2;i<=N;i++)
                    printf(" %d",memo[i][0]);
                printf("\n");*/
            }
        }

        if(M%2==0)
        {
            printf("%lld",memo[1][0]);

            for(i=2;i<=N;i++)
                printf(" %lld",memo[i][0]);
            printf("\n");
        }

        else
        {
            printf("%lld",memo[1][1]);

            for(i=2;i<=N;i++)
                printf(" %lld",memo[i][1]);
            printf("\n");
        }
    }

    return 0;
}

