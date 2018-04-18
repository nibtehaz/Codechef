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
 
set<long long int>summSet;
map<long long int,long long int>bank;
set<long long int>::iterator it;
long long int arr[100005];
long long int summ[100005];
 
int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma
 
    int T;
    long long int P;
    int N;
    int i,j;
    long long int maxx,maxxcnt;
    long long int temp,maybe ;
 
    getInt(T)
 
    while(T--)
    {
 
        summSet.clear();
        bank.clear();
 
        getInt(N)
        getLong(P)
 
        for(i=0;i<N;i++)
        {
            getLong(arr[i])
        }
 
        summ[0] = arr[0] % P;
 
        maxx = summ[0] ;
        maxxcnt = 1;
 
        summSet.insert(summ[0]);
 
        bank[0] = 1 ;
 
        i = 0;
        
        if(bank.find(summ[i])==bank.end())
        {
            bank[summ[i]] = 1 ;
        }
 
        else
        {
            bank[summ[i]]++;
        }
 
        for(i=1;i<N;i++)
        {
            summ[i] = (summ[i-1] + arr[i]) % P;
 
            if(summ[i]>maxx)
            {
                maxx=summ[i];
                maxxcnt=bank[0];
            }
 
            else if(summ[i]==maxx)
            {
                maxxcnt+=bank[0];
            }
 
 
            /*it = summSet.begin();
 
            temp = *it;
 
            maybe = ( summ[i] - temp + P ) % P ;
 
 
            if(maybe>maxx)
            {
                maxx = maybe;
                maxxcnt= bank[temp] ;
            }
            else if(maybe==maxx)
            {
                maxxcnt += bank[temp] ;
            }*/
 
 
            it = summSet.upper_bound(summ[i]);
 
            if(it==summSet.end())
            {
                //DEBUG("mara")
                ;
            }
 
            else
            {
                temp = *it;
 
                maybe = ( summ[i] - temp + P ) % P ;
 
                //DEBUG(maybe)
 
                if(maybe > maxx)
                {
                    maxx = maybe ;
                    maxxcnt= bank[temp] ;
                }
 
                else if(maybe==maxx)
                {
                    maxxcnt += bank[temp] ;
                }
            }
 
            summSet.insert(summ[i]);
 
            if(bank.find(summ[i])==bank.end())
            {
                bank[summ[i]] = 1 ;
            }
 
            else
            {
                bank[summ[i]]++;
            }
        }
 
        printf("%lld %lld\n",maxx,maxxcnt);
 
    }
 
    return 0;
}
 