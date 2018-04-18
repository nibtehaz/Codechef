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

long long int arr[3][100005];
long long int cumSum[3][100005];
int p,q,r;

long long int getIntervalSum (int id, int lo , int hi)
{
    return ( cumSum[id][hi+1] - cumSum[id][lo+1] + MOD ) % MOD ;
}

int BSAtMost (int id , int len , long long int val)
{
    
    ;
}   
 
int main()
{ 
    // Bismillahir Rahmanir Rahim 
    // Rabbi Zidni Ilma 

    int T;
    int i;
    long long int ans;
    long long int y;
    int i1,i2;

    getInt(T)

    while(T--)
    {
        ans = 0 ;

        // input 

        getInt(p)
        getInt(q)
        getInt(r)

        for(i=0;i<p;i++)
        {
            getLong(arr[0][i])
        }

        for(i=0;i<q;i++)
        {
            getLong(arr[1][i])
        }

        for(i=0;i<r;i++)
        {
            getLong(arr[2][i])
        }

        // sort 

        sort(arr[0],arr[0]+p);
        sort(arr[1],arr[1]+q);
        sort(arr[2],arr[2]+r);


        // cum sum 

        cumSum[0][0] = 0 ;
        cumSum[1][0] = 0 ;
        cumSum[2][0] = 0 ;

        for(i=0;i<p;i++)
        {
            cumSum[0][i+1] = cumSum[0][i] + arr[0][i];
        }

        /*for(i=0;i<q;i++)
        {
            cumSum[1][i+1] = cumSum[1][i] + arr[1][i];
        }*/

        for(i=0;i<r;i++)
        {
            cumSum[2][i+1] = cumSum[2][i] + arr[2][i];
        }

        for(i=0;i<=p;i++)
        {
            cumSum[0][i] %= MOD;
        }

        /*for(i=0;i<=q;i++)
        {
            cumSum[1][i] %= MOD;
        }*/

        for(i=0;i<=r;i++)
        {
            cumSum[2][i] %= MOD;
        }

        // iterate for all y 

        for(i=0;i<q;i++)
        {
            y = arr[1][i];

            i1 = upper_bound(arr[0],arr[0]+p,arr[1][i]) - arr[0]  ;
            i2 = upper_bound(arr[2],arr[2]+r,arr[1][i]) - arr[2]  ;
            
            ans += ( ((cumSum[0][i1] + ((i1)*arr[1][i])%MOD)%MOD)*((cumSum[2][i2] + ((i2)*arr[1][i])%MOD)%MOD) )%MOD ;
            ans %= MOD ;
        }

        printf("%lld\n",ans);

    }

    return 0;
}
