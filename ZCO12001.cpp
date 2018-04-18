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
 
struct bracket
{
	int pos;
	int type;
};

int ans11,ans12;
int ans21,ans22;
vector <bracket> arr;
stack <bracket> steak;

void problem1()
{
	int i;

	ans12 = -1;


	for(i=0;i<arr.size();i++)
	{
		if(arr[i].type==1)
		{
			steak.push(arr[i]);
		}

		else
		{
			//printf("%d %d\n",steak.size(),steak.top().pos);
			//printf("%d\n",ans12);
			if(ans12<(int)steak.size())
			{
				ans12 = steak.size();
				ans11 = steak.top().pos;

			}

			steak.pop();
		}
	}
}

void problem2()
{
	while(!steak.empty())
	{
		steak.pop();
	}

	int i;
	ans22 = -1 ;
	int len;

	for(i=0;i<arr.size();i++)
	{
		if(arr[i].type==1)
		{
			steak.push(arr[i]);
		}

		else
		{
			//printf("%d %d\n",steak.size(),steak.top().pos);
			//printf("%d\n",ans12);
			len = arr[i].pos - steak.top().pos + 1;

			if(ans22<len)
			{
				ans22 = len;
				ans21 = steak.top().pos;

			}

			steak.pop();
		}
	}
}

int main()
{
	// Bismillahir Rahmanir Rahim 
	// Rabbi Zidni Ilma 

	int N; 
	int i,j;

	getInt(N)

	for(i=0;i<N;i++)
	{
		getInt(j)
		arr.pb({i,j});
	}

	problem1();
	problem2();

	printf("%d %d %d %d\n",ans12,ans11+1,ans22,ans21+1);


    return 0;

}
