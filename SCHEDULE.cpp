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

char inp[1000010];
vector<long long int>pq;
long long int N;


int minnn;

void check()
{
    int maxx=0,cnt=0,pre=-1;

    for(int i=0;i<16;i++)
    {
        if(inp[i]==pre)
        {
            cnt++;
        }

        else
        {
            pre=inp[i];
            cnt=1;
        }

        maxx = BIGGER(maxx,cnt);
    }

    if(minnn == -1)
    {
        minnn = maxx;
    }

    else
    {
        minnn = SMALLER(minnn,maxx);
    }

    //DEBUG(maxx)
}

void recursiveBacktracking(int i,int k)
{
    if(i==16)
    {
        check();
        return;
    }

    if(k>0)
    {
        inp[i]= 1 -(inp[i]-'0') + '0' ;
        recursiveBacktracking(i+1,k-1);
        inp[i]= 1 -(inp[i]-'0') + '0' ;
    }

    recursiveBacktracking(i+1,k);
}

int smallSubProblem(int k)
{
    minnn=-1;
    recursiveBacktracking(0,k);
    return minnn;
}



bool divisionSimulation(long long int limiter,long long int k)
{
    long long int i;
    long long int divisions=0;
    long long int trial,temp;
    long long int lo,hi,mid;

    for(i=0;i<pq.size();i++)
    {
        //DEBUG(pq[i])
        lo = 0 ;
        hi = pq[i];

        while(lo<hi)
        {
            mid=(lo+hi)/2;

            if((limiter*(mid+1)+mid)>=pq[i])
            {
                hi = mid;
            }

            else
            {
                lo = mid+1;
            }
        }

        divisions += lo;
    }

    //printf("%d %d\n",limiter,divisions);

    if(divisions<=k)
    {
        return true;
    }

    else
    {
        return false ;
    }
}

long long int newSolution(long long int k)
{
    long long int i,temp;

    temp = 0 ;

    // check for 1
    for(i=0;i<N;i++)
    {
        if(i%2==0)
        {
            if(inp[i]=='0')
            {
                temp++;
            }
        }

        else
        {
            if(inp[i]=='1')
            {
                temp++;
            }
        }
    }

    if(temp<=k)
    {
        return 1;
    }


    temp = 0 ;

    // check for alternate 1
    for(i=0;i<N;i++)
    {
        if(i%2==1)
        {
            if(inp[i]=='0')
            {
                temp++;
            }
        }

        else
        {
            if(inp[i]=='1')
            {
                temp++;
            }
        }
    }

    if(temp<=k)
    {
        return 1;
    }

    pq.clear();

    long long int cnt=1,pre=inp[0];

    for(i=1;i<N;i++)
    {
        if(pre==inp[i])
        {
            cnt++;
        }

        else
        {
            pq.pb(cnt);
            pre = inp[i];
            cnt=1;
        }
    }

    pq.pb(cnt);

    long long int lo = 2 ;
    long long int hi = N;
    long long int mid;

    while(lo<hi)
    {
        mid=(lo+hi)/2;

        if(divisionSimulation(mid,k))
        {
            hi = mid;
        }

        else
        {
            lo = mid+1;
        }
    }

    return lo;

}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    long long int T;
    long long int k;

    //INPUT
    //OUTPUT

    getLong(T)

    while(T--)
    {
        //DEBUG(1)
        getLong(N)
        getLong(k)

        scanf("%s",inp);

        printf("%lld\n",newSolution(k));

        /*if(newSolution(k)!=smallSubProblem(k))
        {
            printf("%d %s %d %d\n",k,inp,newSolution(k),smallSubProblem(k));
        }*/
    }


    return 0;
}
