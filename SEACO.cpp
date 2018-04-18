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

long long int zero = (long long int)0;
 
int  qType1LR[100005][2];
int qType1I[100005];
int qType2LR[100005][2];
int qType2I[100005];

struct SegmentTreeLazyPropagation
{
	long long int tree[400020][2];

	SegmentTreeLazyPropagation()
	{
		memset(tree,0,sizeof(tree));
	}

	void update(int node , int lo , int hi , int qlo , int qhi , long long int val)
	{
		if(qlo>hi || qhi<lo)
		{
			return;
		}

		if(qlo<=lo && hi<=qhi)
		{
			tree[node][0] = (tree[node][0] + (hi-lo+1)*val)%MOD;
			tree[node][1] = (tree[node][1] + val)%MOD;
			return;
		}

		int leftNode = node<<1;
		int rightNode = leftNode+1;
		int mid = (lo+hi)>>1;

		update(leftNode,lo,mid,qlo,qhi,val);
		update(rightNode,mid+1,hi,qlo,qhi,val);

		tree[node][0] = (tree[leftNode][0] + tree[rightNode][0] + (hi-lo+1)*tree[node][1] )%MOD;
	}

	long long int  query(int node , int lo , int hi , int index , long long int propagate)
	{
		if(index<lo || index>hi)
		{
			return zero;
		}

		if(lo==hi && index==lo)
		{
			return (propagate + tree[node][0])%MOD;
		}

		int leftNode = node<<1;
		int rightNode = leftNode+1;
		int mid = (lo+hi)>>1;
		long long int temp = (propagate + tree[node][1])%MOD;

		return ( query(leftNode,lo,mid,index,temp) + query(rightNode,mid+1,hi,index,temp) ) % MOD ;
				
	}
};


int main()
{
	// Bismillahir Rahmanir Rahim 
	// Rabbi Zidni Ilma 
	 
	int T,N,M;
	int nType1,nType2;
	int L,R,t,i;

	getInt(T)

	while(T--)
	{
		getInt(N)
		getInt(M)

		nType1 = 0 ;
		nType2 = 0 ;

		SegmentTreeLazyPropagation type1 = SegmentTreeLazyPropagation();
		SegmentTreeLazyPropagation type2 = SegmentTreeLazyPropagation();

		for(i=1;i<=M;i++)
		{
			getInt(t)
			getInt(L)
			getInt(R)

			if(t==1)
			{
				qType1I[nType1] = i;
				qType1LR[nType1][0] = L;
				qType1LR[nType1][1] = R;

				nType1++;
			}

			else
			{
				qType2I[nType2] = i;
				qType2LR[nType2][0] = L;
				qType2LR[nType2][1] = R;

				nType2++;
			}
		}


		// update type 2  
		for(i=nType2-1;i>=0;i--)
		{
			type2.update(1,1,100005,qType2LR[i][0],qType2LR[i][1],type2.query(1,1,100005,qType2I[i],0)+1);			
		}

		// check all the type 2 
		for(i=0;i<nType2;i++)
		{
			type1.update(1,1,100005,qType2LR[i][0],qType2LR[i][1],type2.query(1,1,100005,qType2I[i],0)+1);
		}		

		SegmentTreeLazyPropagation ans= SegmentTreeLazyPropagation();

		// check all the type 1
		for(i=0;i<nType1;i++)
		{
			ans.update(1,1,100005,qType1LR[i][0],qType1LR[i][1],type1.query(1,1,100005,qType1I[i],0)+1);
		}

		printf("%lld",ans.query(1,1,100005,1,0)%MOD);

		for(i=2;i<=N;i++)
		{
			printf(" %lld",ans.query(1,1,100005,i,0)%MOD);
		}

		printf("\n");

		/*printf("%lld",type1.query(1,1,100005,1,0));

		for(i=2;i<=N;i++)
		{
			printf(" %lld",type1.query(1,1,100005,i,0));
		}

		printf("\n");

		printf("%lld",type2.query(1,1,100005,1,0));

		for(i=2;i<=N;i++)
		{
			printf(" %lld",type2.query(1,1,100005,i,0));
		}

		printf("\n");*/
	}

    return 0;

}