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


int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int N,Q;
    int i,inp,t;
    int minn,maxx;

    getInt(N)
    getInt(Q)

    getInt(inp)
    minn=inp;
    maxx=inp;

    for(i=1;i<N;i++)
    {
        getInt(inp)
        minn=SMALLER(minn,inp);
        maxx=BIGGER(maxx,inp);
    }

    while(Q--)
    {
        getInt(t)

        if(minn<=t && t<=maxx)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}






