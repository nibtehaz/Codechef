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
#define floatingEqual(a,b) (fabs(a-b)<=EPS)
#define floatingLess(a,b) ((b-a)>=EPS)
#define floatingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000

int chk[1002][1025];

struct Days
{
    int whole;
    int used;
};

Days memo[1001][1025][25];
                            // state 1 : current node
                            // state 2 : bitmask
                            // state 3 : time used


int adjList[1001][1001];
int timee[1001];
int dayLength;

bool isFirstSmaller(Days a,Days b);
Days dp(int node, int mask ,int used);

bool isFirstSmaller(Days a,Days b)
{

    return ( (a.whole<b.whole) || ( (a.whole==b.whole) && (a.used<b.used) ) ) ;

    /*if(a.whole<b.whole)
    {
        return true;
    }

    else if(a.whole==b.whole)
    {
        return (a.left<b.left);
    }

    else
    {
        return false;
    }*/
}



Days dp(int node, int mask ,int used)
{
    //printf("%d %d %d\n",node,mask,used);


    if(((mask>>1)+1)==(1<<adjList[node][0]))
    {
        //printf("%d %d\n",node,mask);
        Days temp;
        temp.whole = 0;
        temp.used = used;
        return temp;
    }

    if(checkBit(chk[node][mask],used))
    {
        //printf("hi\n");
        return memo[node][mask][used];
    }

    Days minn = {-1,-1};
    Days temp,temp2;

    for(int i=1;i<=adjList[node][0];i++)
    {
        if(!checkBit(mask,i))
        {
            if((dayLength-used)>=timee[adjList[node][i]])
            {
                temp.whole = 0 ;
                temp.used = used + timee[adjList[node][i]];
            }

            else
            {
                temp.whole = 1 ;
                temp.used = timee[adjList[node][i]];
            }


            temp2 = dp(adjList[node][i],0,temp.used);

            temp.whole += temp2.whole;
            temp.used = temp2.used;


            temp2 = dp(node,setBit(mask,i),temp.used);

            temp.whole += temp2.whole;
            temp.used = temp2.used;

            if( (minn.whole==-1) || (isFirstSmaller(temp,minn)) )
            {
                minn.whole = temp.whole;
                minn.used = temp.used;
            }
        }
    }


    memo[node][mask][used] = minn;

    setBitStatement(chk[node][mask],used);

    return minn;
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int T;

    int N;
    int i,j;

    //INPUT

    Days ans;

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(dayLength)

        for(i=0;i<N;i++)
        {
            getInt(timee[i])
        }

        for(i=0;i<N;i++)
        {
            getInt(adjList[i][0])

            for(j=1;j<=adjList[i][0];j++)
            {
                getInt(adjList[i][j])
                adjList[i][j]--;
            }
        }

        if(N==1)
        {
            printf("1\n");
        }

        else
        {
            memset(chk,0,sizeof(chk));

            ans = dp(0,0,timee[0]);

            if(ans.used!=0)
            {
                ans.whole++;
            }

            printf("%d\n",ans.whole);
        }
    }


    return 0;
}
