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

	int T,S;
	int cntA,cntB,x,y,blockA,blockB,newX,newY;
	int i,j;

	getInt(T)

	while(T--)
	{
		cntA = 0;
		cntB = 0;

		blockA = 0;
		blockB = 0;

		scanf("%s",inp);

		for(i=0;inp[i];i++)
		{
			if(inp[i]=='a')
			{
				cntA++;
			}

			else if(inp[i]=='b')
			{
				cntB++;
			}
		}

		getInt(x)
		getInt(y)

		blockA = cntA/x;
		blockB = cntB/y;

		if(blockA>=cntB)
		{
			for(i=0;i<cntB;i++)
			{
				for(j=0;j<x;j++)
				{
					printf("a");
					cntA--;
				}

				printf("b");
				
			}

			for(j=0;j<x;j++)
			{
				if(cntA==0)
				{
					break;
				}

				printf("a");
				cntA--;
			}


			while(cntA>0)
			{
				printf("*");

				for(j=0;j<x;j++)
				{
					if(cntA==0)
					{
						break;
					}

					printf("a");
					cntA--;
				}
			}
		}

		else if(blockB>=cntA)
		{
			for(i=0;i<cntA;i++)
			{
				for(j=0;j<y;j++)
				{
					printf("b");
					cntB--;
				}

				printf("a");
				
			}

			for(j=0;j<y;j++)
			{
				if(cntB==0)
				{
					break;
				}
				
				printf("b");
				cntB--;
			}

			while(cntB>0)
			{
				printf("*");

				for(j=0;j<y;j++)
				{
					if(cntB==0)
					{
						break;
					}

					printf("b");
					cntB--;
				}
			}
		}

		else
		{
			if((blockA==blockB))
			{
				if(cntA%x!=0)
				{
					for(i=0;i<blockA;i++)
					{
						for(j=0;j<x;j++)
						{
							printf("a");
							cntA--;
						}

						for(j=0;j<y;j++)
						{
							printf("b");
							cntB--;
						}
					}

					
					while(cntA>0)
					{
						printf("a");
						cntA--;
					}

					while(cntB>0)
					{
						printf("b");
						cntB--;
					}

				}


				else 
				{
					for(i=0;i<blockA;i++)
					{
						for(j=0;j<y;j++)
						{
							printf("b");
							cntB--;
						}

						for(j=0;j<x;j++)
						{
							printf("a");
							cntA--;
						}
					}

					while(cntB>0)
					{
						printf("b");
						cntB--;
					}

					
					while(cntA>0)
					{
						printf("a");
						cntA--;
					}

				
				}

			}

			else if(blockA>blockB)
			{
				

				for(i=0;i<blockA;i++)
				{
					for(j=0;j<x;j++)
					{
						printf("a");
						cntA--;
					}

					for(j=0;j<y;j++)
					{
						if(blockA-i>cntB)
						{
							break;
						}

						printf("b");
						cntB--;
					}
				}

				while(cntA>0)
				{
					printf("a");
					cntA--;
				}

				while(cntB>0)
				{
					printf("b");
					cntB--;
				}
			}

			else
			{
				for(i=0;i<blockB;i++)
				{
					for(j=0;j<y;j++)
					{
						printf("b");
						cntB--;
					}

					for(j=0;j<x;j++)
					{
						if(blockB-i>cntA)
						{
							break;
						}

						printf("a");
						cntA--;
					}

				}

				while(cntB>0)
				{
					printf("b");
					cntB--;
				}

				while(cntA>0)
				{
					printf("a");
					cntA--;
				}


			}
		}

		printf("\n");

	}

    return 0;	
}
