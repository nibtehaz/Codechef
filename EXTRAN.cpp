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

vector<int>arr;

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int T,N;
    int i;
    int temp;

    getInt(T)

    while(T--)
    {
        getInt(N)

        arr.clear();

        for(i=0;i<N;i++)
        {
            getInt(temp)
            arr.pb(temp);
        }

        sort(arr.begin(),arr.end());

        if(arr[1]-arr[0]!=1)
        {
            printf("%d\n",arr[0]);
        }

        else if(arr[arr.size()-1]-arr[arr.size()-2]!=1)
        {
            printf("%d\n",arr[arr.size()-1]);
        }

        else
        {
            for(i=1;i<arr.size();i++)
            {
                if(arr[i]==arr[i-1])
                {
                    printf("%d\n",arr[i]);
                }
            }
        }
    }

    return 0;
}
