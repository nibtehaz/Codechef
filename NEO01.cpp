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
#define INPUT freopen("myInput.in","r",stdin);
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

vector <long long int> arr ;

int main()
{
    // Bismillahir Rahmanir Rahim 
    // Rabbi Zidni Ilma 

    int T,N;
    int i;
    long long int summ ;
    long long int cnt ;
    long long int ans ;
    long long int inp ;

    getLong(T)

    while(T--)
    {
        arr.clear();

        summ = 0 ; 
        cnt = 0 ;
        ans = 0 ;

        getLong(N)

        while(N--)
        {
            getLong(inp)

            if(inp<0)
            {
                arr.pb(-inp);
            }

            else
            {
                summ += inp ; 
                cnt++;
            }

        }

        sort(arr.begin(),arr.end());

        for(i=0;i<arr.size();i++)
        {
            if(((summ-arr[i])*(cnt+1))>(summ*cnt-arr[i]))
            {
                summ -= arr[i];
                cnt++;
            }

            else 
            {
                ans = summ*cnt;

                for(;i<arr.size();i++)
                {
                    ans -= arr[i];
                }

                goto done;
            }
        }

        ans = summ*cnt;

        for(;i<arr.size();i++)
        {
            ans -= arr[i];
        }



        done:

            printf("%lld\n",ans);

    }


     
    return 0;
}
