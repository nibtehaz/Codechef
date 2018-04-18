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


long long int T,N;

long long int fastPow(long long int base,long long int power);
long long int BS1(long long int lo,long long int hi,long long int digits);
long long int BS2(long long int lo,long long int hi,long long int digits);

long long int fastPow(long long int base,long long int power)
{
    if(power==0)
    {
        return 1;
    }

    else if(power==1)
    {
        return base;
    }

    else if(power%2==0)
    {
        long long int temp=fastPow(base,power/2);
        return temp*temp;
    }

    else
    {
        long long int temp=fastPow(base,power/2);
        return temp*temp*base;
    }
}

long long int BS1(long long int lo,long long int hi,long long int digits)
{
    long long int mid;

    while(lo<hi)
    {
        mid=(lo+hi+1)/2;

        if((2*fastPow(mid,digits))>N)
        {
            hi=mid-1;
        }

        else
        {
            lo=mid;
        }
    }

    return lo;
}

long long int BS2(long long int lo,long long int hi,long long int digits)
{
    long long int mid;

    while(lo<hi)
    {
        mid=(lo+hi+1)/2;

        if(fastPow(mid,digits)>N)
        {
            hi=mid-1;
        }

        else
        {
            lo=mid;
        }
    }

    return lo;
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    long long int base,digits;
    long long int cnt,num;
    long long int startt,endd;
    long long int hi;

    /*long long int temp=100000000000012;

    printf("%lld\n",temp);
    printf("%f\n",(double)temp);*/

    getLong(T)

    while(T--)
    {
        getLong(N)

        cnt=0;

        for(base=2;base<11;base++)
        {
            num = N ;
            digits=0;

            while(num>0)
            {
                if(num==1)
                {
                    cnt++;
                }

                digits++;
                num/=base;
            }
        }

        //DEBUG(cnt);

        while(digits>0)
        {
            hi=(long long int)(pow((double)100000000000012,(double)(1.0/digits)) + EPS) + 2;

            startt = BS1(10,hi,digits);
            endd = BS2(10,hi,digits);

            if(endd>=startt)
            {
                cnt+=endd-startt;
            }

            digits--;
        }

        if(N==1)
        {
            printf("INFINITY\n");
        }

        else
        {
            printf("%lld\n",cnt);
        }

    }

    return 0;
}
