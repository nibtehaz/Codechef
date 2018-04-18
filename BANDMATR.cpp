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
#define floatingEqual(a,b) (fabs(a-b)<=EPS)
#define floatingLess(a,b) ((b-a)>=EPS)
#define floatingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000

int mat[505][505];

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int T,N;
    int i,j,cnt,inp,K;

    getInt(T)

    while(T--)
    {
        getInt(N)

        cnt = 0 ;

        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                getInt(inp)
                mat[i][j]=inp;

                if(mat[i][j]==1)
                {
                    cnt++;
                }
            }
        }

        for(K=0;;K++)
        {
            if(cnt<=0)
            {
                printf("%d\n",K);
                break;
            }

            if(K==0)
            {
                cnt -= N;
            }

            else
            {
                cnt -= 2*(N-K);
            }

            if(cnt<=0)
            {
                printf("%d\n",K);
                break;
            }
        }
    }

    return 0;
}
