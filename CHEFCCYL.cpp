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

int n;

vector <int>nodeCount;
vector < vector <long long int> >cwCycle;
vector < vector <long long int> >ccwCycle;
vector <long long int>cwBetwnCycle;
vector <long long int>ccwBetwnCycle;

vector < vector <long long int> >w;
vector <long long int>wCycle;
vector <int> st;
vector <int> nxt;

long long int calc(int cyc , int x , int y);
void init();
long long int calcCycle(int x,int y,int mode);
long long int query(int cyc1,int cyc2,int u1,int u2);
void input();

long long int calc(int cyc , int x , int y)
{
	if(x>y)
	{
		x=x^y;
		y=x^y;
		x=x^y;
	}

	return SMALLER(cwCycle[cyc][y]-cwCycle[cyc][x], ccwCycle[cyc][1] - ccwCycle[cyc][x] + w[cyc][nodeCount[cyc]] + cwCycle[cyc][nodeCount[cyc]] - cwCycle[cyc][y] );
}


void init()
{
	int i,j;

	//cwcycle
	for(i=1;i<=n;i++)
	{
		cwCycle[i][1] = 0 ;

		for(j=2;j<=nodeCount[i];j++)
		{
			cwCycle[i][j] = cwCycle[i][j-1] + w[i][j-1];
		}
	}

	//ccwcycle
	for(i=1;i<=n;i++)
	{
		ccwCycle[i][nodeCount[i]] = 0 ;

		for(j=nodeCount[i]-1;j>=1;j--)
		{
			ccwCycle[i][j] = ccwCycle[i][j+1] + w[i][j];
		}
	}

	// cw betwn cycle 

	cwBetwnCycle[1] = 0 ;
	
	for(j=2;j<=n;j++)
	{
		cwBetwnCycle[j] = cwBetwnCycle[j-1] + calc(j-1,st[j-1],nxt[j-1]) + wCycle[j-1] ;
	}

	// ccw betwn cycle 

	ccwBetwnCycle[n] = 0 ;
	
	for(j=n-1;j>=1;j--)
	{
		ccwBetwnCycle[j] = ccwBetwnCycle[j+1] + calc(j+1,st[j+1],nxt[j+1]) + wCycle[j] ;
	}
}

long long int query(int cyc1,int cyc2,int u1,int u2)
{
	if(cyc1>cyc2)
	{
		cyc1 = cyc1^cyc2;
		cyc2 = cyc1^cyc2;
		cyc1 = cyc1^cyc2;

		u1 = u1^u2;
		u2 = u1^u2;
		u1 = u1^u2;
	}

	return SMALLER( calc(cyc1,u1,nxt[cyc1]) + wCycle[cyc1] + cwBetwnCycle[cyc2] - cwBetwnCycle[cyc1+1] + calc(cyc2,st[cyc2],u2) , calc(cyc1,u1,st[cyc1]) + cwBetwnCycle[cyc1] + wCycle[n] + ccwBetwnCycle[cyc2] + calc(cyc2,u2,nxt[cyc2]) );

}

void input()
{
	int i,j,inp;

	nodeCount.clear();
	cwCycle.clear();
	ccwCycle.clear();
	cwBetwnCycle.clear();
	ccwBetwnCycle.clear();
	w.clear();
	wCycle.clear();
	st.clear();
	nxt.clear();

	nodeCount.pb(0);
	cwCycle.pb({});
	ccwCycle.pb({});
	w.pb({});
	st.pb(0);
	nxt.pb(0);
	wCycle.pb(0);
	cwBetwnCycle.pb(0);
	ccwBetwnCycle.pb(0);

	for(i=1;i<=n;i++)
	{
		getInt(inp)

		nodeCount.pb(inp);
		cwCycle.pb({});
		cwCycle[i].pb(0);
		ccwCycle.pb({});
		ccwCycle[i].pb(0);
		w.pb({});
		w[i].pb(0);
		st.pb(0);
		nxt.pb(0);
		cwBetwnCycle.pb(0);
    	ccwBetwnCycle.pb(0);


		for(j=1;j<=nodeCount[i];j++)
		{
			getInt(inp)
			w[i].pb(inp);
			cwCycle[i].pb(0);
			ccwCycle[i].pb(0);
		}
	}


	for(i=1;i<=n;i++)
	{
		getInt(inp)
		nxt[i] = inp;

		getInt(inp)
		if(i==n)
		{
			st[1]=inp;
		}
		else
		{
			st[i+1]=inp;
		}

		getInt(inp)
		wCycle.pb(inp);

		
	}
}

int main()
{   
	// Bismillahir Rahmanir Rahim
	// Rabbi Zidni Ilma 

	int T,q;
	int c1,c2,u1,u2;

	getInt(T)

	while(T--)
	{
		getInt(n)
		getInt(q)
		input();
		init();

		while(q--)
		{
			getInt(u1)
			getInt(c1)
			getInt(u2)
			getInt(c2)

			printf("%lld\n",query(c1,c2,u1,u2));
		}
	}

    return 0;	
}
