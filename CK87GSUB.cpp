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

struct Segment
{
	int L;
	int R;
};

vector<Segment>segments;

long long int lenin(Segment a);
long long int getIt(int len);

long long int lenin(Segment a)
{
	return (long long int )(a.R-a.L+1);
}

long long int getIt(long long int len)
{
	return (len*(len+1))/2;
}

char inp[100005];



int main()
{
	// Bismillahir Rahmanir Rahim 
	// Rabbi Zidni Ilma 

	int T;
	int pre,i,j,tl,tr;
	long long int cnt;
	long long int temp;
	
	getInt(T)

	while(T--)
	{
		scanf("%s",inp);

		segments.clear();
		cnt=0;

		tl=0;
		pre=inp[0];

		for(i=1;inp[i];i++)
		{
			if(inp[i]==pre)
			{
				continue;
			}

			else
			{
				tr=i-1;
				segments.pb({tl,tr});
				tl=i;
				pre=inp[i];
			}
		}

		tr=i-1;
		segments.pb({tl,tr});

		if(lenin(segments[0])>1)
		{
			cnt += getIt(lenin(segments[0])-1);
		}


		for(i=1;i<segments.size();i++)
		{
			if(lenin(segments[i])>1)
			{
				cnt += getIt(lenin(segments[i])-1);
			}


			if(inp[segments[i].L-1]==inp[segments[i].R+1])
			{
				cnt++;
			}
		}

		printf("%lld\n",cnt);


	}

 
    return 0;	
}