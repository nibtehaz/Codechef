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
#define INPUT freopen("myInput.in","r",stdin);
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

int present;
map <int,int>steak;
int adjList[MAX];
int ans;
bool color[MAX];

void dfs(int node);

void dfs(int node)
{
    color[node]=1;
    steak[node]=present;
    present++;

    if(color[adjList[node]]==0)
    {
        dfs(adjList[node]);
    }

    else
    {
        if(steak.find(adjList[node])!=steak.end())
        {
            ans+=present-steak[adjList[node]];
        }
    }
}

int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T,N,i;
    int a;

    getInt(T);

    while(T--)
    {
        getInt(N)

        for(i=0;i<N;i++)
        {
            color[i]=0;
            getInt(a)

            adjList[i]=(1+i+a)%N;

            //printf("%d ",adjList[i]);
        }

        //printf("\n");

        ans=0;

        for(i=0;i<N;i++)
        {
            if(color[i]==0)
            {
                present=0;
                steak.clear();
                dfs(i);
            }
        }

        printf("%d\n",ans);
    }



    return 0;
}
