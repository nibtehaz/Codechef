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


long long int BigMod(long long int base , long long int power)
{
    if(power==0)
        return 1;
    else if(power==1)
        return base;
    else if(power%2==0)
    {
        long long int temp=BigMod(base,power/2)%MOD;
        return (temp*temp)%MOD;
    }
    else
    {
        long long int temp=BigMod(base,power/2)%MOD;
        return (((temp*temp)%MOD)*base)%MOD;
    }
}

int main()
{
    long long int T,N,K,Ans;

    /*while(1)
    {
        getLong(N)
        getLong(K)

        DEBUG(BigMod(N,K))
    }*/

    getLong(T)

    while(T--)
    {
        getLong(N)
        getLong(K)


            Ans=K;

            Ans=(Ans*BigMod(K-1,N-1))%MOD;


        printf("%lld\n",Ans);
    }

    return 0;
}


