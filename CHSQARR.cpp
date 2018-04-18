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
#include <set>
#include <deque>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("myInput.txt","r",stdin);
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

int maxx=0;
int sparseTable[1005][1005][12][12];
int mat[1005][1005];
int cumulSum[1005][1005]={0,};


int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int N,M,Q,a,b;
    int i,j,k1,k2,p1,p2,c,d;
    int minn,pre,x,y,z;

    getInt(N)
    getInt(M)

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            getInt(mat[i][j])
        }
    }

    //rmq part

    for(k1=0;;k1++)
    {
        p1=1<<k1;

        if(p1>N)
            break;

        for(k2=0;;k2++)
        {
            p2=1<<k2;

            if(p2>M)
                break;

            for(i=0;;i++)
            {
                if(i+p1>N)
                    break;

                for(j=0;;j++)
                {
                    if(j+p2>M)
                        break;

                    if(k1==0 && k2==0)
                    {
                        sparseTable[i][j][k1][k2] = mat[i][j];
                    }

                    else if(k1==0)
                    {
                        sparseTable[i][j][k1][k2] = BIGGER (sparseTable[i][j][k1][k2-1] , sparseTable[i][j+(1<<(k2-1))][k1][k2-1] );
                    }

                    else if(k2==0)
                    {
                        sparseTable[i][j][k1][k2] = BIGGER (sparseTable[i][j][k1-1][k2] , sparseTable[i+(1<<(k1-1))][j][k1-1][k2] );
                    }

                    else
                    {
                        sparseTable[i][j][k1][k2] = BIGGER ( BIGGER (sparseTable[i][j][k1-1][k2-1] , sparseTable[i+(1<<(k1-1))][j][k1-1][k2-1] ) , BIGGER (sparseTable[i+(1<<(k1-1))][j+(1<<(k2-1))][k1-1][k2-1] , sparseTable[i][j+(1<<(k2-1))][k1-1][k2-1] ) );
                    }


                }
            }
        }
    }

    /*while(1)
    {
        getInt(i)
        getInt(j)
        getInt(k1)
        getInt(k2)

        DEBUG(sparseTable[i][j][k1][k2])
    }*/



    // sum part

    cumulSum[0][0]=mat[0][0];

    for(i=1;i<M;i++)
        cumulSum[0][i]=cumulSum[0][i-1]+mat[0][i];

    for(i=1;i<N;i++)
        cumulSum[i][0]=cumulSum[i-1][0]+mat[i][0];

    for(i=1;i<N;i++)
    {
        for(j=1;j<M;j++)
        {
            cumulSum[i][j] = cumulSum[i-1][j] + cumulSum[i][j-1] - cumulSum[i-1][j-1] + mat[i][j];
        }
    }

    /*for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%d ",cumulSum[i][j] );
        }
        printf("\n");
    }*/

    /*while(1)
    {
        getInt(i)
        getInt(j)
        getInt(a)
        getInt(b)

        if(i==0)
            x=0;
        else
            x=cumulSum[i-1][j+b-1];

        if(j==0)
            y=0;
        else
            y=cumulSum[i+a-1][j-1];
        if(i==0 || j==0)
            z=0;
        else
            z=cumulSum[i-1][j-1];
        DEBUG(cumulSum[i+a-1][j+b-1] - x - y + z);
    }*/


    getInt(Q)

    while(Q--)
    {
        getInt(a)
        getInt(b)
        c=a*b;

        minn=-1;

        k1=log2(a);
        k2=log2(b);

        for(i=0;i<N;i++)
        {
            if(i+a>N)
                break;

            for(j=0;j<M;j++)
            {
                if(j+b>M)
                    break;

                pre = c* BIGGER(  BIGGER( sparseTable[i][j][k1][k2] ,  sparseTable[i+a-(1<<k1) ][j][k1][k2]  )  ,  BIGGER( sparseTable[i][j+b -(1<<k2)][k1][k2] , sparseTable[i+a-(1<<k1) ][j+b -(1<<k2) ][k1][k2]  )  ) ;

                if(i==0)
                    x=0;
                else
                    x=cumulSum[i-1][j+b-1];

                if(j==0)
                    y=0;
                else
                    y=cumulSum[i+a-1][j-1];
                if(i==0 || j==0)
                    z=0;
                else
                    z=cumulSum[i-1][j-1];

                pre = pre -(cumulSum[i+a-1][j+b-1] - x - y + z);

                if(minn==-1)
                    minn=pre;
                else
                    minn=SMALLER(minn,pre);

                if(minn==0)
                    goto done;
            }
        }

        done:
            printf("%d\n",minn);

    }

    return 0;
}
