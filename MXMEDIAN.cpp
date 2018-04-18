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
#define INPUT freopen("C-large.in","r",stdin);
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
 
int arr[100005];
int ans[100005];

 
int main()
{
    // Bismillahir Rahmanir Rahim 
    // Rabbi Zidni Ilma 
    
    int T;
    int N,N2;
    int i,j;
    
    getInt(T)
    
    while(T--)
    {
        getInt(N)
        
        N2 = N*2;
        
        for(i=0;i<N2;i++)
        {
            getInt(arr[i])
        }
        
        sort(arr,arr+N2);
        
        printf("%d\n",arr[N+(N/2)]);
        
        for(i=0;i<N;i++)
        {
            ans[2*i]=arr[i];
        }
        
        for(i=0;i<N;i++)
        {
            ans[2*i+1]=arr[i+N];
        }
        
        printf("%d",ans[0]);
        
        for(i=1;i<N2;i++)
        {
            printf(" %d",ans[i]);
        }
        
        printf("\n");
        
        
    }
    
    return 0;
}