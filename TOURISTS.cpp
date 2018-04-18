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

int N,E;

vector<int>adjListOld[100005];
map<int,int>adjListOld2[100005];
map<int,int>adjListNew[100005];
vector< pair<int,int> >inputEdges;
set<int>nodes;
bool color[100005]={0,};
int connected=0;

bool checkEvenDegree();
void dfs1(int node);
bool checkForConnectivity();
void HierholzerAlgorithm();
int dfs2(int node , int startingNode,int starting);
void edgeRearrange();


bool checkEvenDegree()
{
    int i;

    for(i=0;i<N;i++)
    {
        //printf("%d %d\n",i,adjListOld[i].size());
        if(adjListOld[i].size()%2==1)
        {
            return 0;
        }
    }

    return 1;
}

void dfs1(int node)
{
    int i;

    for(i=0;i<adjListOld[node].size();i++)
    {
        if(color[adjListOld[node][i]]==0)
        {
            color[adjListOld[node][i]]=1;
            connected++;
            dfs1(adjListOld[node][i]);
        }
    }
}

bool checkForConnectivity()
{
    connected++;
    color[0]=1;
    dfs1(0);


    if(connected==N)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void HierholzerAlgorithm()
{
    int i;
    int temp;

    for(i=0;i<N;i++)
    {
        if((adjListOld2[i].size()>0))
        {
            nodes.insert(i);
            temp=dfs2(i,i,1);
        }
    }

    int node;
    while(nodes.size()!=0)
    {
        node=*nodes.begin();

        if(adjListOld2[node].size()==0)
        {
            nodes.erase(node);
        }

        else
        {
            temp=dfs2(node,node,1);
        }
    }
}


int dfs2(int node , int startingNode,int starting)
{
    if((node==startingNode)&&(starting==0))
    {
        return 1;
    }

    int nextNode = adjListOld2[node].begin()->first;

    adjListOld2[node][nextNode]--;

    if(adjListOld2[node][nextNode]==0)
    {
        adjListOld2[node].erase(nextNode);
    }

    adjListOld2[nextNode][node]--;

    if(adjListOld2[nextNode][node]==0)
    {
        adjListOld2[nextNode].erase(node);
    }

    if(adjListNew[node].find(nextNode)==adjListNew[node].end())
    {
        adjListNew[node][nextNode]=1;
    }

    else
    {
        adjListNew[node][nextNode]++;
    }

    nodes.insert(nextNode);

    if(dfs2(nextNode,startingNode,0)==1)
    {
        return 1;
    }

    else
    {
        return 0;
    }

}

void edgeRearrange()
{
    int i;
    int u,v;

    for(i=0;i<inputEdges.size();i++)
    {
        u=inputEdges[i].first;
        v=inputEdges[i].second;

        if(adjListNew[u].find(v)!=adjListNew[u].end())
        {
            inputEdges[i].first=u;
            inputEdges[i].second=v;

            adjListNew[u][v]--;

            if(adjListNew[u][v]==0)
            {
                adjListNew[u].erase(v);
            }
        }

        else if(adjListNew[v].find(u)!=adjListNew[v].end())
        {
            inputEdges[i].first=v;
            inputEdges[i].second=u;

            adjListNew[v][u]--;

            if(adjListNew[v][u]==0)
            {
                adjListNew[v].erase(u);
            }
        }

    }
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j,u,v;

    //INPUT

    getInt(N)
    getInt(E)

    for(i=0;i<E;i++)
    {
        getInt(u)
        getInt(v)

        u--;
        v--;

        inputEdges.pb({u,v});

        adjListOld[u].pb(v);
        adjListOld[v].pb(u);

        if(adjListOld2[u].find(v)==adjListOld2[u].end())
        {
            adjListOld2[u][v] = 1;
        }
        else
        {
            adjListOld2[u][v]++;
        }

        if(adjListOld2[v].find(u)==adjListOld2[v].end())
        {
            adjListOld2[v][u] = 1;
        }
        else
        {
            adjListOld2[v][u]++;
        }
    }

    if(checkEvenDegree()==0)
    {
        printf("NO\n");
        return 0;
    }

    if(checkForConnectivity()==0)
    {
        printf("NO\n");
        return 0;
    }

    for(i=0;i<N;i++)
    {
        adjListOld[i].clear();
    }

    //DEBUG(checkEvenDegree())
    //DEBUG(checkForConnectivity())

    HierholzerAlgorithm();

    /*for(i=0;i<N;i++)
    {
        if(adjListNew[i].size()>0)
        {
            printf("%d %d\n",i+1,*adjListNew[i].begin() +1 );
        }
    }*/

    edgeRearrange();

    printf("YES\n");

    for(i=0;i<inputEdges.size();i++)
    {
        printf("%d %d\n",inputEdges[i].first+1 , inputEdges[i].second+1 );
    }

    return 0;
}
