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

vector <int> arr;

int main()
{  
	// Bismillahir Rahmanir Rahim
	// Rabbi Zidni Ilma 

	int T,N;
	int left;

	getInt(T)

	while(T--)
	{
		getInt(N)

		arr.clear();

		left = N-99991;

		arr.pb(2);

		

		for(int i=0;i<99989;i++)
		{
			if(i<39785)
			{
				arr.pb(42955);
				
			}

			else
			{
				arr.pb(42954);
				
			}
		}

		arr.pb(1);
		
		for(int i=0;i<left;i++)
		{
			arr[i+1]--;
			arr.pb(1);
		}

		printf("%d",arr[0]);

		for(int i=1;i<arr.size();i++)
		{
			printf(" %d",arr[i]);
		}

		printf("\n");


	}
	
    return 0;	
}
