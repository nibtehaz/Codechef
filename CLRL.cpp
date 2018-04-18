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
	int lo;
	int hi;

	bool contains(int num)
	{
		return ((lo<=num)&&(num<=hi));
	}
};

int main()
{ 
	// Bismillahir Rahmanir Rahim
	// Rabbi Zidni Ilma 

	int T,N;
	int M;
	int i,inp,linp;
	int test;
	Segment s1,s2;
	

	getInt(T)

	while(T--)
	{
		getInt(N)
		getInt(M)

		test=1;

		getInt(inp)

		s1.lo=0;
		s1.hi=inp;

		s2.lo=inp;
		s2.hi=1000000000+1;
		
		for(i=1;i<N;i++)
		{
			//printf("(%d,%d) : (%d,%d)\n",s1.lo,s1.hi,s2.lo,s2.hi);
			getInt(inp)

			if(s1.contains(inp))
			{
				s1.lo=s1.lo;
				
				s2.hi=s1.hi;

				s1.hi=inp;

				s2.lo=inp;
			}

			else if(s2.contains(inp))
			{
				s2.lo=s2.lo;
				
				s1.hi=s2.hi;

				s2.hi=inp;

				s1.lo=inp;				
			}

			else
			{
				test=0;
			}
		}

		printf("%s\n",test==0? "NO" : "YES");


	}

 
	
    return 0;	
}
 