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

#define PI acos(-1.0)
#define MAX 100015
#define MOD 1000000007
#define EPS 1e-15

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("C-large.in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define FPEQUAL(FP1,FP2) fabs(FP1-FP2)<=EPS
#define FPLT(FP1,FP2) (FP1-FP2)<=EPS
#define FPGT(FP1,FP2) (FP1-FP2)>=EPS
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back

#define INF 1000000000


int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T;
    int N,A[MAX],B[MAX],test,i,j;
    bool chk[MAX];
    long long int sum;
    long long int avg;

    getInt(T)

    while(T--)
    {
        getInt(N)

        sum=0;

        B[0]=0;
        chk[0]=0;

        B[N+1]=0;
        chk[0]=0;

        for(i=1;i<=N;i++)
        {
            getInt(B[i])
            chk[i]=1;
            sum+=B[i];
        }

        for(i=1;i<=N;i++)
        {
            getInt(A[i])
            sum+=A[i];
        }

        if(sum%(N)==0)
        {
            avg=sum/(N);

            for(i=1;i<=N;i++)
            {
                //only last
                if(chk[i-1]*B[i-1] + A[i] ==avg)
                {
                    A[i]=avg;
                    chk[i-1]=0;
                }

                //last and current
                else if(chk[i-1]*B[i-1] + chk[i]*B[i] + A[i] ==avg)
                {
                    A[i]=avg;
                    chk[i-1]=0;
                    chk[i]=0;
                }

                //last and later
                else if(chk[i-1]*B[i-1] + chk[i+1]*B[i+1] + A[i] ==avg)
                {
                    A[i]=avg;
                    chk[i-1]=0;
                    chk[i+1]=0;
                }

                // last , current , later
                else if(chk[i-1]*B[i-1] + chk[i]*B[i] + chk[i+1]*B[i+1] + A[i] ==avg)
                {
                    A[i]=avg;
                    chk[i-1]=0;
                    chk[i]=0;
                    chk[i+1]=0;
                }

                //only current
                else if(chk[i]*B[i] + A[i] ==avg)
                {
                    A[i]=avg;
                    chk[i]=0;
                }

                //only later
                else if(chk[i+1]*B[i+1] + A[i] ==avg)
                {
                    A[i]=avg;
                    chk[i+1]=0;
                }

                //current and later
                else if(chk[i]*B[i] + chk[i+1]*B[i+1] + A[i] ==avg)
                {
                    A[i]=avg;
                    chk[i]=0;
                    chk[i+1]=0;
                }
            }

            test=1;


            /*for(i=1;i<=N;i++)
            {
                printf("%d ",A[i] );
            }
            printf("\n");*/

            for(i=1;i<=N;i++)
            {
                if(B[i]*chk[i]!=0 || A[i]!=avg )
                {
                    test=0;
                    break;
                }
            }

            if(test==1)
            {
                printf("%lld\n",avg);
            }

            else
            {
                printf("-1\n");
            }
        }

        else
        {
            printf("-1\n");
        }



    }


    return 0;
}
