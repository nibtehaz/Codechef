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

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
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


int main()
{
    long long int T,R,G,B,K,ans;

    getLong(T)

    while(T--)
    {
        getLong(R)
        getLong(G)
        getLong(B)

        getLong(K)

        ans=3*K - 2;

        K--;

        if(R<K)
            ans-=K-R;

        if(G<K)
            ans-=K-G;

        if(B<K)
            ans-=K-B;

        printf("%lld\n",ans);
    }
    return 0;
}


