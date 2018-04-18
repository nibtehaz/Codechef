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
#define EPS 1e-15

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

struct Interval
{
    long long int lo;
    long long int hi;
    bool impossible;
    bool infinite;
};

Interval func(long long int h1,long long int h2,long long int r1,long long int r2);

Interval func(long long int h1,long long int h2,long long int r1,long long int r2)
{
    // we are finding out h1 > h2

    Interval ans;
    ans.impossible=0;
    ans.infinite=0;
    ans.lo=-1;              // this means impossible
    ans.hi=-1;              // this measn infinite

    if(h1>h2)
    {
        ans.lo=0;
    }

    else
    {
        if(r1<=r2)
        {
            ans.impossible=1;
            return ans;
        }

        else
        {
            ans.lo = (h2-h1)/(r1-r2);

            while(h1+r1*ans.lo <= h2+r2*ans.lo)  // when h1 > h2 we're done here
            {
                ans.lo++;
            }

            h1+=r1*ans.lo;
            h2+=r2*ans.lo;
        }
    }

    // hi is the last moment before h2 >= h1

    if(r1>=r2)
    {
        ans.infinite=1;
        return ans;
    }

    else
    {
        ans.hi=(h1-h2)/(r2-r1);

        while(h2+r2*ans.hi >= h1+r1*ans.hi)
        {
            ans.hi--;
        }

        ans.hi+=ans.lo;
    }

    return ans;


}


long long int h[20],r[20];

void smallSubtask(int n);


void smallSubtask(int n)
{
    int i,j,mode,Q;
    bool chk[200]={0,},test;

    for(i=0;i<200;i++)
    {
        mode=0;
        test=1;

        for(j=1;j<n;j++)
        {
            if(mode==0)
            {
                if(h[j]>=h[j-1])
                {
                    test=0;
                    break;
                }

                mode=1;
            }

            else
            {
                if(h[j]<=h[j-1])
                {
                    test=0;
                    break;
                }

                mode=0;
            }
        }

        chk[i] |= test;

        mode=1;
        test=1;

        for(j=1;j<n;j++)
        {
            if(mode==0)
            {
                if(h[j]>=h[j-1])
                {
                    test=0;
                    break;
                }

                mode=1;
            }

            else
            {
                if(h[j]<=h[j-1])
                {
                    test=0;
                    break;
                }

                mode=0;
            }
        }

        chk[i] |= test;

        //printf("\n%d\n",chk[i]);
        for(j=0;j<n;j++)
        {
            h[j]+=r[j];
            //printf("%d ",h[j]);
        }


    }

    Q=0;
    test=1;

    for(i=0;i<200;i++)
    {
        if(chk[i]==1)
        {
            if(test==1)
            {
                Q++;
                test=0;
            }
        }

        else
        {
            if(test==0)
            {
                test=1;
            }
        }
    }

    printf("%d\n",Q);

    test=1;
    for(i=0;i<200;i++)
    {
        if(chk[i]==1)
        {
            if(test==1)
            {
                printf("%d",i);
                test=0;
            }
        }

        else
        {
            if(test==0)
            {
                printf(" %d\n",i-1);
                test=1;
            }
        }
    }

    if(chk[199]==1)
    {
        printf(" Inf\n");
    }




}

int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T,n,i,Q,mode,maxx;
    Interval zigzag,zagzig,temp;

    //OUTPUT
    //INPUT

    getInt(T)

    while(T--)
    {
        getInt(n)
        maxx=0;

        for(i=0;i<n;i++)
        {
            getLong(h[i])
            getLong(r[i])

            maxx=BIGGER(maxx,h[i]);
            maxx=BIGGER(maxx,r[i]);

        }

        if(maxx<12)
        {
            smallSubtask(n);
            continue;
        }


        //first zIg zag

        zigzag=func(h[0],h[1],r[0],r[1]);
        //printf("%lld %lld %d %d\n",zigzag.lo,zigzag.hi,zigzag.impossible,zigzag.infinite);

        mode=0;

        for(i=2;i<n;i++)
        {
            if(mode==1)
            {
                temp=func(h[i-1],h[i],r[i-1],r[i]);
                //printf("%d %d\n",i,mode);
                //printf("%lld %lld %d %d\n\n",temp.lo,temp.hi,temp.impossible,temp.infinite);

                mode=0;
            }

            else
            {
                temp=func(h[i],h[i-1],r[i],r[i-1]);
                //printf("%d %d\n",i,mode);
                //printf("%lld %lld %d %d\n\n",temp.lo,temp.hi,temp.impossible,temp.infinite);

                mode=1;
            }

            zigzag.lo=BIGGER(zigzag.lo,temp.lo);

            if(temp.hi!=-1)
                zigzag.hi=SMALLER(zigzag.hi,temp.hi);
            if(zigzag.hi==-1)
                zigzag.hi=temp.hi;

            zigzag.infinite &= temp.infinite;
            zigzag.impossible |= temp.impossible;

            if(zigzag.lo>zigzag.hi && zigzag.infinite!=1)
            {
                zigzag.impossible=1;
            }

            //printf("%lld %lld %d %d\n",zigzag.lo,zigzag.hi,zigzag.impossible,zigzag.infinite);

        }

        //printf("%lld %lld %d %d\n",zigzag.lo,zigzag.hi,zigzag.impossible,zigzag.infinite);

        //now zag zIg

        zagzig=func(h[1],h[0],r[1],r[0]);
        mode=1;

        for(i=2;i<n;i++)
        {
            if(mode==1)
            {
                temp=func(h[i-1],h[i],r[i-1],r[i]);
                mode=0;
            }

            else
            {
                temp=func(h[i],h[i-1],r[i],r[i-1]);
                mode=1;
            }

            zagzig.lo=BIGGER(zagzig.lo,temp.lo);
            if(temp.hi!=-1)
                zagzig.hi=SMALLER(zagzig.hi,temp.hi);
            if(zagzig.hi==-1)
                zagzig.hi=temp.hi;
            zagzig.infinite  &= temp.infinite;
            zagzig.impossible |= temp.impossible;

            if(zagzig.lo>zagzig.hi && zagzig.infinite!=1 )
            {
                zagzig.impossible=1;
            }
        }

        //printf("%lld %lld %d %d\n",zagzig.lo,zagzig.hi,zagzig.impossible,zagzig.infinite);

        if(zigzag.lo>zagzig.lo && zigzag.impossible|zagzig.impossible==0)
        {
            temp=zigzag;
            zigzag=zagzig;
            zagzig=temp;
        }

        Q=2-int(zigzag.impossible)-int(zagzig.impossible);

        if(Q==2)
        {
            if(zigzag.hi+1==zagzig.lo)
            {
                zigzag.hi=zagzig.hi;
                zigzag.infinite=zagzig.infinite;
                zagzig.impossible=1;
                Q--;
            }

        }
        printf("%d\n",Q);

        if(zigzag.impossible==0)
        {
            printf("%lld",zigzag.lo);

            if(zigzag.infinite==1)
            {
                printf(" Inf\n");
            }

            else
            {
                printf(" %lld\n",zigzag.hi);
            }
        }

        if(zagzig.impossible==0)
        {
            printf("%lld",zagzig.lo);

            if(zagzig.infinite==1)
            {
                printf(" Inf\n");
            }

            else
            {
                printf(" %lld\n",zagzig.hi);
            }
        }

    }





    return 0;
}
