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

	int T;
	long long int a,b,c;
	int arrA[20];
	int arrB[20];
	int arrC[20];
	int i;

	getInt(T)

	while(T--)
	{
		getLong(a)
		getLong(b)

		memset(arrA,0,sizeof(arrA));
		memset(arrB,0,sizeof(arrB));
		memset(arrC,0,sizeof(arrC));

		i=0;
		c=0;

		for(i=0;i<20;i++)
		{
			arrA[i]=a%10;
			arrB[i]=b%10;
			arrC[i]=(arrA[i]+arrB[i])%10;
			a/=10;
			b/=10;
		}

		for(i=19;i>=0;i--)
		{
			c=c*10+arrC[i];
		}

		printf("%lld\n",c);
	}

	
 
    return 0;	
}
 