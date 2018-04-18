
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
#define INPUT freopen("myInput.txt","r",stdin);
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


#define INF 1000000000

long long int fastExp(long long int base , long long int power , long long int mod);


long long int fastExp(long long int base , long long int power , long long int mod)
{
    if(power==0)
        return 1;
    else if(power==1)
        return base;
    else if(power%2==0)
    {
        long long int temp=fastExp(base,power/2,mod);
        return (temp*temp)%mod;
    }
    else
    {
        long long int temp=fastExp(base,power/2,mod);
        return (((temp*temp)%mod)*base)%mod;
    }
}

long long int fact[MAX];

int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int i,T,N,K,actual;
    int inp;
    long long int ans,temp1,temp2;

    fact[0]=1;

    for(i=1;i<MAX;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(K)

        actual=N;

        for(i=0;i<N;i++)
        {
            getInt(inp)

            if(inp==0)
                actual--;
        }

        ans=0;

        for(i=0;i<=actual;i++)
        {
            if(i>K)
                break;

            if((K-i)%2==0 || actual!=N)
            {
                temp2=(fact[i]*fact[actual-i])%MOD;
                temp1=(fact[actual]*fastExp(temp2,MOD-2,MOD))%MOD;

                ans = (ans + temp1) % MOD ;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}






