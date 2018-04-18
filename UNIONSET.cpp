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
#define INPUT freopen("myInput.in","r",stdin);
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
#define setBit(a,n) a|(1<<n)
#define setBitStatement(a,n) a|=1<<n;
#define resetBit(a,n) a&=~(1<<n);
#define checkBit(a,n) ((a&(1<<n))!=0)
#define toggleBit(a,n) a^=1<<n;
#define doubleingEqual(a,b) (fabs(a-b)<=EPS)
#define doubleingLess(a,b) ((b-a)>=EPS)
#define doubleingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000

int adjList [2501][2501];
int adjMat [2501][2501];

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma
    
   
    
    int T,tp=1;
    int N,K;
    int inp1,inp2;
    int i,i1,i2,i3;
    int j1,j2;
    int bakiAse,localLagbe;
    int ans;

    getInt(T)

    while(T--)
    {
        ans = 0 ;

        // all inputs

        getInt(N)
        getInt(K)

        for(i=0;i<N;i++)
        {
            getInt(inp1)

            adjList[i][0] = inp1;
            

            for(i1=1;i1<=adjList[i][0];i1++)
            {
                getInt(inp1)
                
                 //DEBUG("hi")

                adjMat[i][inp1] = tp ;

                adjList[i][i1] = inp1 ;
            }
        }
        // computation

        for(i1=0;i1<N;i1++)
        {


            for(i2=i1+1;i2<N;i2++)
            {
                if(adjList[i1][0]>adjList[i2][0])
                {
                    j1 = i1 ;
                    j2 = i2 ;
                }

                else
                {
                    j1 = i2 ;
                    j2 = i1 ;
                }

                localLagbe = K - adjList[j1][0];

                bakiAse = adjList[j2][0];

                if(localLagbe>bakiAse)
                {
                    goto parlamNa;
                }


                for(i3=1;i3<=adjList[j2][0];i3++)
                {
                    if(adjMat[j1][adjList[j2][i3]]!=tp)
                    {
                        localLagbe--;
                    }

                    bakiAse--;

                    if(localLagbe>bakiAse)
                    {
                        goto parlamNa;
                    }
                }


                ans++;

                parlamNa :
                    ;
            }
        }


        // done

        printf("%d\n",ans);

        tp++;
    }


    return 0;

}
