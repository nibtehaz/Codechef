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

map<int,int>populationID;
int P[50005];
set<int>valueList;
set<int>::iterator it;
vector<vector<int> >adjList;

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int T,N;
    int i,j,u,v;

    getInt(T)

    while(T--)
    {
        getInt(N)

        for(i=0;i<=N;i++)
        {
            adjList.pb({});
        }

        for(i=1;i<=N;i++)
        {
            getInt(P[i]);

            populationID[P[i]]=i;

            valueList.insert(P[i]);
        }

        for(i=1;i<N;i++)
        {
            getInt(u)
            getInt(v)

            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        // done with inputs
        // now compute

        valueList.erase(P[1]);

        for(i=0;i<adjList[1].size();i++)
        {
            valueList.erase(P[adjList[1][i]]);
        }

        if(valueList.size()==0)
        {
            printf("0");
        }

        else
        {
            it=valueList.end();
            it--;
            printf("%d",populationID[*it]);
        }

        valueList.insert(P[1]);

        for(i=0;i<adjList[1].size();i++)
        {
            valueList.insert(P[adjList[1][i]]);
        }

        for(j=2;j<=N;j++)
        {
            valueList.erase(P[j]);

            for(i=0;i<adjList[j].size();i++)
            {
                valueList.erase(P[adjList[j][i]]);
            }

            if(valueList.size()==0)
            {
                printf(" 0");
            }

            else
            {
                it=valueList.end();
                it--;
                printf(" %d",populationID[*it]);
            }

            valueList.insert(P[j]);

            for(i=0;i<adjList[j].size();i++)
            {
                valueList.insert(P[adjList[j][i]]);
            }
        }

        printf("\n");

        adjList.clear();
        valueList.clear();
    }


    return 0;
}
