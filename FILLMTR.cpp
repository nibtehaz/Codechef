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
#define INPUT freopen("in.in","r",stdin);
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
 
map<int , set<int> >zeros;
map<int ,set<int> >ones;

bool color[100005];

set<int> even;
set<int> odd;

vector< vector<int> >adjList;
vector< vector<int> >adjWeight;

int error;

void dfs(int node,int level);

void dfs(int node,int level)
{
	int i;

	color[node]=1;

	if(level==0)
	{
		even.insert(node);
	}

	else
	{
		odd.insert(node);
	}

	for(i=0;i<adjList[node].size();i++)
	{
		if(adjWeight[node][i]==1)
		{
			if(color[adjList[node][i]]==1)
			{
				if(level==0)
				{
					if(even.find(adjList[node][i])!=even.end())
					{
						error=1;
						return;
					}
				}

				else
				{
					if(odd.find(adjList[node][i])!=odd.end())
					{
						error=1;
						return;
					}
				}
			}

			else
			{
				dfs(adjList[node][i],1-level);
			}
		}

		else 
		{
			if(color[adjList[node][i]]==1)
			{
				if(level==1)
				{
					if(even.find(adjList[node][i])!=even.end())
					{
						error=1;
						return;
					}
				}

				else
				{
					if(odd.find(adjList[node][i])!=odd.end())
					{
						error=1;
						return;
					}
				}
			}

			else
			{
				dfs(adjList[node][i],level);
			}
		}
	}	
}



int main()
{
	// Bismillahir Rahmanir Rahim 
	// Rabbi Zidni Ilma 

	int T;
	int N,Q;
	int i,j,v;

	getInt(T)

	while(T--)
	{
		getInt(N)
		getInt(Q)

		memset(color,0,sizeof(color));

		zeros.clear();
		ones.clear();
		even.clear();
		odd.clear();

		adjList.clear();
		adjWeight.clear();

		error=0;

		for(i=0;i<=N;i++)
		{
			adjList.pb({});
			adjWeight.pb({});
		}

		while(Q--)
		{
			getInt(i)
			getInt(j)
			getInt(v)

			if(i==j && v!=0)
			{
				error=1;
			}

			if(v==1)
			{
				if(ones.find(i)==ones.end())
				{
					ones[i].insert(j);
				}

				else
				{
					// check 

					if(zeros.find(i)!=zeros.end())
					{
						if(zeros[i].find(j)!=zeros[i].end())
						{
							error=1;
						}
					}

					// insert 

					ones[i].insert(j);
				}
			}

			else 
			{
				if(zeros.find(i)==zeros.end())
				{
					zeros[i].insert(j);
				}

				else
				{
					// check 

					if(ones.find(i)!=ones.end())
					{
						if(ones[i].find(j)!=ones[i].end())
						{
							error=1;
						}
					}

					// insert 

					zeros[i].insert(j);
				}
			}

			adjList[i].pb(j);
			adjWeight[i].pb(v);

			i = i^j;
			j = i^j;
			i = i^j;


			if(v==1)
			{
				if(ones.find(i)==ones.end())
				{
					ones[i].insert(j);
				}

				else
				{
					// check 

					if(zeros.find(i)!=zeros.end())
					{
						if(zeros[i].find(j)!=zeros[i].end())
						{
							error=1;
						}
					}

					// insert 

					ones[i].insert(j);
				}
			}

			else 
			{
				if(zeros.find(i)==zeros.end())
				{
					zeros[i].insert(j);
				}

				else
				{
					// check 

					if(ones.find(i)!=ones.end())
					{
						if(ones[i].find(j)!=ones[i].end())
						{
							error=1;
						}
					}

					// insert 

					zeros[i].insert(j);
				}
			}

			adjList[i].pb(j);
			adjWeight[i].pb(v);

		}

		for(i=1;i<=N;i++)
		{
			if(color[i]==0)
			{
				dfs(i,0);
			}
		}

		if(error==0)
		{
			printf("yes\n");
		}

		else
		{
			printf("no\n");
		}
	}

	 
    return 0;

}