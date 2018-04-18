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

long long int tree[400005];
long long int arr[100005];
int N;

void init(int node , int lo , int hi);
long long int query(int node , int lo , int hi , int rl , int rr);
int BS(int lo,int hi,long long int K,int indi);

void init(int node , int lo , int hi)
{
    if(lo==hi)
    {
        tree[node]=arr[lo];
        return;
    }

    int leftChild = 2*node;
    int rightChild =leftChild+1;

    int mid=(lo+hi)/2;

    init(leftChild,lo,mid);
    init(rightChild,mid+1,hi);

    tree[node]=tree[leftChild] | tree[rightChild];
}

long long int query(int node , int lo , int hi , int rl , int rr)
{
    if(lo>rr || hi<rl)
    {
        return 0;
    }

    if(rl<=lo && hi<=rr)
    {
        return tree[node];
    }

    int leftChild = 2*node;
    int rightChild =leftChild+1;

    int mid=(lo+hi)/2;

    long long int lefty= query( leftChild ,  lo , mid ,  rl , rr);

    long long int righty= query( rightChild ,  mid+1 , hi ,  rl , rr);

    return lefty | righty ;
}

int BS(int lo,int hi,long long int K,int indi)
{
    int mid;

    if(query(1,0,N-1,indi,N-1)<K)
    {
        return -1;
    }

    while(lo<hi)
    {
        mid=(lo+hi)/2;

        //DEBUG(mid)

        if(query(1,0,N-1,indi,mid)<K)
        {
            lo=mid+1;
        }

        else
        {
            hi=mid;
        }
    }

    return lo;
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int T;
    long long int K;
    long long int ans = 0;
    int i;
    int lu;

    getInt(T)

    while(T--)
    {
        getInt(N)

        getLong(K)

        for(i=0;i<N;i++)
        {
            getLong(arr[i])
        }

        init(1,0,N-1);


        ans = 0 ;

        for(i=0;i<N;i++)
        {
            //DEBUG(i)
            lu = BS(i,N-1,K,i);

            if(lu==-1)
            {
                ;
            }

            else
            {
                ans+=(N-1)-(lu)+1;
            }
        }


        printf("%lld\n",ans);
    }



    return 0;
}