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

map<int,vector<int> >bank;
set<int>chk;
set<int>steak;
set<int>::iterator it,sit;

int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T;
    int N,N_;
    int i,j,k,last,len,tempo,tempo2,tempo3;
    int arr[MAX];
    long long int ans=0,incri;

    //INPUT

    getInt(T)

    while(T--)
    {
        getInt(N)
        N_=N-1;

        bank.clear();

        for(i=0; i<N; i++)
        {
            getInt(arr[i]);

            bank[arr[i]].pb(i);

            //DEBUG("Y")
        }

        ans=0;

        for(i=0; i<N; i++)
        {
            chk.clear();
            steak.clear();
            steak.insert(N);
            incri=0;

            for(j=i; j<N_; j++)
            {
                if(j==i)
                {
                    len=N-j-1;
                    incri+=(len*(len+1))/2;
                }

                else
                {
                    tempo=j;

                    it=steak.upper_bound(tempo);

                    tempo3=*it;
                    it--;
                    tempo2=*it;

                    len=tempo3-tempo2-1;
                    incri-=(len*(len+1))/2;

                    len=tempo3-tempo-1;
                    incri+=(len*(len+1))/2;

                    len=tempo-tempo2-1;
                    incri+=(len*(len+1))/2;

                }

                steak.insert(j);


                /*printf("STAGE init %lld\n",incri);

                printf("%d %d\n",i,j);

                for(k=i;k<=j;k++)
                    printf("%d ",arr[k] );
                printf("\n");*/

                if(chk.find(arr[j])==chk.end())
                {
                    chk.insert(arr[j]);

                    for(k=0; k<bank[arr[j]].size(); k++)
                    {
                        tempo=bank[arr[j]][k];

                        if(tempo<=j)
                            continue;

                        //inserting so incri to incriment

                        it=steak.upper_bound(tempo);

                        //printf("tempo %d\n",tempo);

                        // Case 1 : first element

                        if(it==steak.begin())
                        {
                            tempo2=*it;
                            len=tempo2-tempo-1;
                            incri+=(len*(len+1))/2;

                            //printf("Case 1 %lld\n",incri);
                        }

                        // Case 2 : last element ( this is impossible :p)

                        else if(it==steak.end())
                        {
                            it--;
                            tempo2=*it;
                            len=tempo-tempo2-1;
                            incri+=(len*(len+1))/2;

                            //printf("Case 2 %lld\n",incri);
                        }

                        // Case 3 : in between

                        else
                        {
                            tempo3=*it;
                            it--;
                            tempo2=*it;

                            len=tempo3-tempo2-1;
                            incri-=(len*(len+1))/2;

                            len=tempo3-tempo-1;
                            incri+=(len*(len+1))/2;

                            len=tempo-tempo2-1;
                            incri+=(len*(len+1))/2;

                            //printf("Case 3 %lld\n",incri);

                        }

                        steak.insert(tempo);
                    }
                }

                // Time for erasing

                while(steak.size())
                {

                    it=steak.begin();

                    if(*it<j)
                    {
                        tempo=*it;
                        it++;
                        tempo2=*it;

                        len=tempo2-tempo-1;
                        incri-=(len*(len+1))/2;

                        it--;

                        steak.erase(it);
                    }

                    else
                    {
                        break;
                    }
                }

                ans+=incri;

                //printf("incri %lld\n",incri);

                /*if(steak.size())
                {
                    it=steak.begin();
                    last=*it;
                    len=last-j-1;
                    ans+=(len*(len+1))/2;
                    it++;


                    for(; it!=steak.end(); it++)
                    {
                        len=*it-last-1;
                        last=*it;
                        ans+=(len*(len+1))/2;
                    }

                }*/

            }
        }

        printf("%lld\n",ans);

    }

    return 0;
}
