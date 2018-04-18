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
#define MAX 200005
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

vector <int> tempp;

long long int Kadane();

long long int Kadane()
{
    long long int ans=0;
    long long int temp=0;
    int i;

    for(i=0;i<tempp.size();i++)
    {
        if(tempp[i]>0)
            break;
    }

    if(i==tempp.size())
        return 0;

    for(i=0;i<tempp.size();i++)
    {
        temp+=tempp[i];

        if(temp>ans)
        {
            ans=temp;
        }

        if(temp<0)
        {
            temp=0;
        }
    }

    if(temp>ans)
    {
        ans=temp;
    }

    return ans;
}


int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T,N,R[MAX],startt,endd,i;
    long long int cwSum,ccwSum,circleSum,temp,minn;

    //INPUT
    //OUTPUT


    getInt(T)

    while(T--)
    {
        getInt(N)

        circleSum=0;

        for(i=0;i<N;i++)
        {
            getInt(R[i])

            circleSum+=R[i];
        }

        getInt(startt)
        getInt(endd)

        startt--;
        endd--;

        //cw Sum

        cwSum=0;

        for(i=startt;;)
        {
            cwSum+=R[i];

            i=(i+1)%N;

            if(i==endd)
                break;
        }


        //ccw Sum

        ccwSum=0;

        for(i=startt;;)
        {
            i=(i-1+N)%N;

            ccwSum+=R[i];

            if(i==endd)
                break;
        }

        minn=SMALLER(cwSum,ccwSum);

      /*  //DEBUG(minn)

        // case 1 : cw then extend and return

        temp=0;

        for(i=endd;;)
        {
            temp+=R[i];

            minn=SMALLER( minn , cwSum + 2*temp );

            i=(i+1)%N;

            if(i==startt)
                break;
        }



        // case 2 : cw and extend and return from the other side

        temp=0;

        for(i=startt;;)
        {
            i=(i-1+N)%N;

            temp+=R[i];

            minn=SMALLER( minn , cwSum + 2*temp );

            if(i==endd)
                break;
        }

        // case 3 : ccw and extend and return from the other side

        temp=0;

        for(i=startt;;)
        {
            temp+=R[i];

            minn=SMALLER( minn , ccwSum + 2*temp );

            i=(i+1)%N;

            if(i==endd)
                break;
        }



        // case 4 : ccw then extend and return

        temp=0;

        for(i=endd;;)
        {
            i=(i-1+N)%N;

            temp+=R[i];

            minn=SMALLER( minn , ccwSum + 2*temp );

            if(i==startt)
                break;
        }

        */

        // case 5 cw master

        tempp.clear();

        temp=0;

        for(i=endd;;)
        {
            tempp.pb(R[i]);


            i=(i+1)%N;


            if(i==startt)
                break;
        }


        temp=Kadane();

        minn=SMALLER(minn,cwSum+2*ccwSum-2*temp);


        // case 6 ccw master

        tempp.clear();

        temp=0;

        for(i=startt;;)
        {
            tempp.pb(R[i]);

            i=(i+1)%N;

            if(i==endd)
                break;
        }


        temp=Kadane();

        minn=SMALLER(minn,ccwSum+2*cwSum-2*temp);





        printf("%lld\n",minn);



    }


    return 0;
}
