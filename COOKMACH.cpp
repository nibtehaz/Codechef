/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);

int main(void) {
	
	int n,m,first,second,ans,step,i,T;
	scanf("%d",&T);
	while(T--)
	{
		step=0;
		scanf("%d%d",&m,&n);
		
		while(1)
		{
			if((m & (m-1) )==0)
				break;
			m/=2;
			step++;
		}
		
		while(m!=n)
		{
			if(m>n)
			{
				m/=2;
				step++;
			}
			else
			{
				m*=2;
				step++;
			}
		}
		
		printf("%d\n",step);
		
	}
	
	return 0;
}
