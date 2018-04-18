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

#define PI acos(-1.0)
#define MAX 100015
#define MOD 1000000007
#define EPS 1e-9

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("myInput.in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define FPEQUAL(FP1,FP2) fabs(FP1-FP2)<=EPS
#define FPLT(FP1,FP2) (FP1-FP2)<=EPS
#define FPGT(FP1,FP2) (FP1-FP2)>=EPS
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back

#define INF 1000000000

struct Village
{
    bool power;
    int x;
};

bool isFirstSmaller ( Village a , Village b);

bool isFirstSmaller ( Village a , Village b)
{
    return (a.x<=b.x);
}

int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T,N,N_;
    Village arr[MAX];
    int i,left,right,maxx;
    char inp[MAX];
    long long int ans;

    getInt(T)

    while(T--)
    {
        getInt(N)

        scanf("%s",inp);

        for(i=0;i<N;i++)
        {
            arr[i].power=inp[i]-'0';
            getInt(arr[i].x);
        }

        sort(arr,arr+N,isFirstSmaller);

        ans=0;

        for(i=0;i<N;i++)
        {
            if(arr[i].power==1)
                break;

            ans+=arr[i+1].x-arr[i].x;
        }

        left=i;


        //DEBUG(ans);

        for(i=N-1;i>=0;i--)
        {
            if(arr[i].power==1)
                break;

            ans+=arr[i].x-arr[i-1].x;
        }

        right=i;

        maxx=0;

        //DEBUG(ans);

        for(i=left+1;i<=right;i++)
        {
            ans+=arr[i].x-arr[i-1].x;

            maxx=BIGGER(maxx,arr[i].x-arr[i-1].x);

            if(arr[i].power==1)
            {
                ans-=maxx;
                maxx=0;
            }
        }

        printf("%lld\n",ans);


    }


    return 0;
}

