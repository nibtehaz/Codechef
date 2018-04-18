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
  

int main()
{ 
	// Bismillahir Rahmanir Rahim 
	// Rabbi Zidni Ilma 

	int T,N;
	int i;
	int place;

	getInt(T)

	while(T--)
	{
		getInt(N)

		if(N%2==0)
		{
			printf("2 1");
			for(i=2;;i++)
			{
				if(2*i>N)
				{
					break;
				}
				printf(" %d %d",2*i,2*i-1);
			}
		}

		else
		{
			if(N==3)
			{
				printf("2 3 1");
			}

			else
			{
				printf("2 1");
				for(i=2;;i++)
				{
					if(2*i+2>N)
					{
						printf(" %d %d %d",N-1,N,N-2);
						break;
					}
					printf(" %d %d",2*i,2*i-1);
				}
			}
		}

		printf("\n");
	}

    return 0;
}