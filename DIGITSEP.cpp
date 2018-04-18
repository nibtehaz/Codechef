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


int N;
int M,X,Y;
char inp[400];
long long int anss=0;

set<int> memo[303][303];
                            // state 1 : index
                            // state 2 : separators
                            // state 3 : gcd so far
                            // compact way


/*map<int, map<long long int, set<int> > > memo;
                        // state 1 : index
                        // state 2 : gcd so far
                        // state 3 : separators*/

long long int getGcd(long long int a,long long int b);
void dp( int index , long long int gcd , int separators);


long long int getGcd(long long int a,long long int b)
{
    long long int c;

    while(1)
    {
        if(b==0)
        {
            return a;
        }

        c=b;
        b=a%b;
        a=c;

    }
}

void dp( int index , long long int gcd , int separators)
{
    // termination

    if(index==N)
    {
        if(separators>=X && separators<=Y)
        {
            anss=BIGGER(anss,gcd);
        }
        return;
    }

    if(separators>Y)
    {
        return;
    }

    // check for memo

    /*if(memo.find(index)!=memo.end())
    {
        if(memo[index].find(gcd)!=memo[index].end())
        {
            if(memo[index][gcd].find(separators)!=memo[index][gcd].end())
            {
                return;
            }
        }
    }*/

    if(memo[index][separators].find(gcd)!=memo[index][separators].end())
    {
        return;
    }

    // proceed

    int i;
    long long int temp=0;

    for(i=0;i<M;i++)
    {
        if((index+i)>=N)
        {
            break;
        }
        temp=temp*10+inp[index+i];

        // next step
        if(separators<Y)
        {
            dp(index+i+1,getGcd( BIGGER(gcd,temp) , SMALLER(gcd,temp) ),separators+1);
        }
    }

    // save
    memo[index][separators].insert(gcd);
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    //INPUT

    int T;
    int i,j;

    getInt(T)

    while(T--)
    {

        getInt(N)
        scanf("%s",inp);

        for(i=0;i<N;i++)
        {
            inp[i] -= '0' ;
        }

        getInt(M)
        getInt(X)
        getInt(Y)

        X++;
        Y++;

        for(i=0;i<=N;i++)
        {
            for(j=0;j<=Y;j++)
            {
                memo[i][j].clear();
            }
        }



        anss=0;

        dp(0,(long long int)0,0);

        printf("%lld\n",anss);
    }

    return 0;
}
