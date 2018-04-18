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

char inp[100005];

int main()
{ 
	// Bismillahir Rahmanir Rahim
	// Rabbi Zidni Ilma 

	int T;
	int i,N;
	int lefty,righty;
	int cur,cnt;

	int A,B;

	getInt(T)

	while(T--)
	{
		scanf("%s",inp);
		N=strlen(inp);

		cur=inp[0];
		A=0;
		B=0;
		cnt=0;

		if(cur=='A')
		{
			lefty=cur;
			A++;
		}

		else if(cur=='B')
		{
			lefty=cur;
			B++;
		}
		else
		{
			lefty=cur;
			cnt++;
		}

		for(i=1;i<N;i++)
		{
			if(inp[i]=='.')
			{
				if(cur!='.')
				{
					cnt=1;
					lefty=cur;
				}

				else
				{
					cnt++;
				}
			}

			else
			{
				if(cur=='.')
				{
					righty=inp[i];

					if(lefty==righty)
					{
						if(lefty=='A')
						{
							A+=cnt;
						}

						else if(lefty=='B')
						{
							B+=cnt;
						}
					}
				}

				if(inp[i]=='A')
				{
					A++;
				}

				else if(inp[i]=='B')
				{
					B++;
				}

				lefty=inp[i];
			}

			cur = inp[i];
		}

		printf("%d %d\n",A,B);
	}

 
	
    return 0;	
}
 