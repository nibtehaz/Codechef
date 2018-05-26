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
#define setBit(a,n) a|=1<<n;
#define resetBit(a,n) a&=~(1<<n);
#define checkBit(a,n) ((a&(1<<n))!=0)
#define toggleBit(a,n) a^=1<<n;

#define INF 1000000000

vector<long long int>odds;
vector<long long int>evens;

int main()
{  
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int T,N,K;
    long long int i,ele;
    long long int oddSum, evenSum;

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(K)

        odds.clear();
        evens.clear();

        for(i=0;i<N;i++)
        {
            getLong(ele)

            if(i%2 == 0) // even
            {
                evens.pb(ele);
            }

            else
            {
                odds.pb(ele);
            }
        }

        sort(evens.begin(),evens.end());
        sort(odds.begin(),odds.end());

        /*for(i=0;i<odds.size();i++)
        {
            printf("%lld ",odds[i]);
        } printf("\n");

        for(i=0;i<evens.size();i++)
        {
            printf("%lld ",evens[i]);
        } printf("\n");*/

        K = SMALLER(K,odds.size());

        for(i=0;i<K;i++)
        {
            if(odds[i]<evens[evens.size()-1-i])
            {
                odds[i] = odds[i] ^ evens[evens.size()-1-i];
                evens[evens.size()-1-i] = odds[i] ^ evens[evens.size()-1-i];
                odds[i] = odds[i] ^ evens[evens.size()-1-i];
            }

            else
            {
                break;
            }
        }

        oddSum = 0;
        evenSum = 0;

        for(i=0;i<odds.size();i++)
        {
            oddSum += odds[i];
        }

        for(i=0;i<evens.size();i++)
        {
            evenSum += evens[i];
        }

        printf("%s\n", oddSum > evenSum ? "YES" : "NO");

    }

    return 0;
}
