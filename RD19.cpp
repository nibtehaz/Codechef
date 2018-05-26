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

int gcd(int a, int b);

int gcd(int a, int b)
{
    int c;

    if(b>a)
    {
        a = a^b;
        b = a^b;
        a = a^b;
    }

    while(b!=0)
    {
        c = b;
        b = a%b;
        a = c;
    }

    return a;
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma   

    int T,N;
    int numm;
    int gcdd;

    getInt(T)

    while(T--)
    {
        getInt(N)

        getInt(numm)
        gcdd = numm;
        N--;

        while(N--)
        {
            getInt(numm)
            gcdd = gcd(numm,gcdd);
        }

        if(gcdd==1)
        {
            printf("0\n");
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
