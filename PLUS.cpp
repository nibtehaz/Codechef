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
#define setBit(a,n) a|=1<<n;
#define resetBit(a,n) a&=~(1<<n);
#define checkBit(a,n) ((a&(1<<n))!=0)
#define toggleBit(a,n) a^=1<<n;

#define INF 1000000000

long long int matt[1005][1005];
long long int vertCumSum[1005][1005];
long long int horiCumSum[1005][1005];

int main()
{  
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int T;
    int N,M;
    int i,j,k;
    long long int maxx,summ;
    long long int maxx1,maxx2,maxx3,maxx4;

    getInt(T)
    
    while(T--)
    {
        getInt(N)
        getInt(M)

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                getLong(matt[i][j])
            }
        }

        

        memset(vertCumSum,0,sizeof(vertCumSum));
        memset(horiCumSum,0,sizeof(horiCumSum));

        

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                horiCumSum[i][j] = horiCumSum[i][j-1] + matt[i][j];
            }
        }

        for(j=1;j<=M;j++)
        {
            for(i=1;i<=N;i++)
            {
                vertCumSum[i][j] = vertCumSum[i-1][j] + matt[i][j];
            }
        }

        //DEBUG("hi")

        maxx = matt[2][1]+matt[2][2]+matt[2][3]+matt[1][2]+matt[3][2];

        for(i=1;i<N;i++)
        {
            for(j=1;j<M;j++)
            {
                maxx1 = matt[i][j] + matt[i][j+1];
                for(k=2;(j+k)<=M;k++)
                {
                    maxx1 = BIGGER(maxx1, horiCumSum[i][j+k]-horiCumSum[i][j-1]);
                }

                maxx2 = matt[i][j] + matt[i+1][j];
                for(k=2;(i+k)<=N;k++)
                {
                    maxx2 = BIGGER(maxx2, vertCumSum[i+k][j]-vertCumSum[i-1][j]);
                }

                maxx3 = matt[i][j] + matt[i][j-1];
                for(k=2;(j-k)>0;k++)
                {
                    maxx3 = BIGGER(maxx3, horiCumSum[i][j]-horiCumSum[i][j-k-1]);
                }

                maxx4 = matt[i][j] + matt[i-1][j];
                for(k=2;(i-k)>0;k++)
                {
                    maxx4 = BIGGER(maxx4, vertCumSum[i][j]-vertCumSum[i-k-1][j]);
                }

                maxx = BIGGER(maxx,maxx1+maxx2+maxx3+maxx4-3*matt[i][j]);
            }
        }

        printf("%lld\n",maxx);
        
    }

    return 0;
}
