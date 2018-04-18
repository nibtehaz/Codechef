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

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("A-large (2).in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000009
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back

#define INF 1000000000

int N;
long long int H[MAX],R[MAX];
long long int W,L;

bool possible(long long int month);
long long int binarySearch(long long int lo , long long int hi);


bool possible(long long int month)
{
    long long int sum=0,temp;
    int i;

    for(i=0;i<N;i++)
    {
        temp = H[i] + R[i]*month;

        if(temp>=L)
            sum+=temp;

        if(sum>=W)
            return true;
    }

    if(sum>=W)
        return true;
    else
        return false;

}

long long int binarySearch(long long int lo , long long int hi)
{
    long long int mid;

    while(lo<hi)
    {
        mid=(lo+hi)/2;

        if(possible(mid))
        {
            hi=mid;
        }

        else
        {
            lo=mid+1;
        }
    }

    mid=(lo+hi)/2;

    return mid;
}


int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma


    int i;
    long long int min=1000000000000000000,temp,pp;

    getInt(N)
    getLong(W)
    getLong(L)
    pp=BIGGER(W,L);

    for(i=0;i<N;i++)
    {
        getLong(H[i])
        getLong(R[i])

        if(H[i]>=pp)
            temp=0;
        else
        {
            temp=(pp-H[i])/R[i];
            temp++;
        }

        min=SMALLER(temp,min);
    }

    printf("%lld\n",binarySearch(0,min));


    return 0;
}

