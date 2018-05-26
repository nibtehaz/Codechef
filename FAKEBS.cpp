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

map<int,int>position;
map<int,int>sortedPos;

vector<int>arr1;
vector<int>arr2;


int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int T,N,Q;
    int i;
    int ele;
    int boroLagbe, chotoLagbe, chotoAche, boroAche, cmn, ans;
    int lo, hi, mid, target;

    getInt(T)


    while(T--)
    {
        getInt(N)
        getInt(Q)

        position.clear();
        sortedPos.clear();
        arr1.clear();
        arr2.clear();

        arr1.pb(-1);
        arr2.pb(-1);

        for(i=0;i<N;i++)
        {
            getInt(ele);

            position[ele] = i+1;

            arr1.pb(ele);
            arr2.pb(ele);
        }

        sort(arr2.begin(),arr2.end());

        for(i=1;i<arr2.size();i++)
        {
            sortedPos[arr2[i]] = i;
        }

        while(Q--)
        {
            getInt(ele)

            boroLagbe = 0;
            chotoLagbe = 0;
            chotoAche = sortedPos[ele] - 1;
            boroAche = N - chotoAche - 1 ;

            lo = 1;
            hi = N;
            target = position[ele];
            
            while(lo<=hi)
            {
                mid = (lo + hi) / 2;
                
                if(mid==target)
                {
                    break;
                }

                else if(mid<target) // we need to go right, choto lagbe
                {
                    lo = mid + 1;

                    if(arr1[mid]<ele)
                    {
                        chotoAche--; // ekta choto fix kore rakhlam
                    }

                    else
                    {
                        chotoLagbe++;
                    }
                }

                else  // we need to go left, boro lagbe
                {
                    hi = mid - 1;

                    if(arr1[mid]>ele)
                    {
                        boroAche--; // ekta boro fix kore rakhlam
                    }

                    else
                    {
                        boroLagbe++;
                    }
                }
            }

            cmn = SMALLER(boroLagbe, chotoLagbe);

            ans = cmn;

            if( (boroLagbe>boroAche) || (chotoLagbe>chotoAche) )
            {
                ans= -1;
            }

            else
            {
                boroLagbe -= cmn;
                chotoLagbe -= cmn;
                ans += boroLagbe + chotoLagbe;
            }

            printf("%d\n",ans);

        }
    }

    return 0;
}
