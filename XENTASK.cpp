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
#define floatingEqual(a,b) (fabs(a-b)<=EPS)
#define floatingLess(a,b) ((b-a)>=EPS)
#define floatingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int T,N;
    long long int i,temp;
    vector<long long int>arr1;
    vector<long long int>arr2;
    long long int way1,way2;

    getInt(T)

    while(T--)
    {
        getInt(N)

        arr1.clear();
        arr2.clear();

        for(i=0;i<N;i++)
        {
            getLong(temp)
            arr1.pb(temp);
        }

        for(i=0;i<N;i++)
        {
            getLong(temp)
            arr2.pb(temp);
        }

        way1 = 0 ;
        way2 = 0 ;

        for(i=0;i<N;i++)
        {
            if(i%2==0)
            {
                way1 += arr1[i];
            }

            else
            {
                way1 += arr2[i];
            }
        }

        for(i=0;i<N;i++)
        {
            if(i%2==1)
            {
                way2 += arr1[i];
            }

            else
            {
                way2 += arr2[i];
            }
        }

        printf("%lld\n",SMALLER(way1,way2));
    }


    return 0;
}
