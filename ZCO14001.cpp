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

int arr[100005]={0,};

int main()
{
	// Bismillahir Rahmanir Rahim 
	// Rabbi Zidni Ilma 

	int N,H;
	int i;
	int command;
	int position , carry;

	getInt(N)
	getInt(H)

	for(i=0;i<N;i++)
	{
		getInt(arr[i])
	}

	position = 0;
	carry = 0 ;

	while(1)
	{
		getInt(command)

		switch(command)
		{
			case 0:
				goto End;
				break;
			
			case 1:

				position = BIGGER(0,position-1);
				break;

			case 2:

				position=SMALLER(N-1,position+1);
				break;

			case 3:

				if(arr[position]>0)
				{
					arr[position] -= 1 - carry ;
					carry = 1;
				}
				break;

			case 4:

				if(arr[position]<H)
				{
					arr[position] += carry;
					carry=0;
				}
				break;

		}
	}

	End:

	printf("%d",arr[0]);

	for(i=1;i<N;i++)
	{
		printf(" %d",arr[i]);
	}
	printf("\n");
    

    return 0;

}
