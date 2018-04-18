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
#define floatingEqual(a,b) (fabs(a-b)<=EPS)
#define floatingLess(a,b) ((b-a)>=EPS)
#define floatingGreater(a,b) ((a-b)>=EPS)
 
#define INF 1000000000
 
char inp[100005];
 
int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma
 
    int T;
    int N;
    int cnt,i,pre;
 
    getInt(T)
 
    while(T--)
    {
        cnt=0;
        scanf("%s",inp);
        N=strlen(inp);
 
        pre = inp[0];
        if(pre=='1')
        {
            cnt++;
        }
 
        for(i=1;i<N;i++)
        {
            if(pre==inp[i])
            {
                continue;
            }
 
            else
            {
                pre=inp[i];
 
                if(pre=='1')
                {
                    cnt++;
                }
 
            }
        }
 
        if(cnt==1)
        {
            printf("%s\n","YES");
        }
        else
        {
            printf("%s\n","NO");
        }
    }
 
 
    return 0;
}
 