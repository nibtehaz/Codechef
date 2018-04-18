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
#define MOD 100000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back


int main()
{
    int T;
    int N,K,i;
    long long int A[MAX],B[MAX];
    long long int sum,max,temp;

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(K)

        sum=0;

        for(i=0;i<N;i++)
        {
            getLong(A[i])
        }

        for(i=0;i<N;i++)
        {
            getLong(B[i])
        }

        for(i=0;i<N;i++)
        {
            sum+=A[i]*B[i];
        }

        max=sum;

        for(i=0;i<N;i++)
        {
            temp=B[i]*K;

            if(sum+temp>max)
                max=sum+temp;
            if(sum-temp>max)
                max=sum-temp;
        }

        printf("%lld\n",max);


    }

    return 0;
}
