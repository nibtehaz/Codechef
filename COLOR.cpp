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


int main()
{
    int T,len,R,G,B,max,i;
    char inp[MAX];

    getInt(T)

    while(T--)
    {
        getInt(len)
        scanf("%s",inp);

        R=0;
        G=0;
        B=0;

        for(i=0;i<len;i++)
        {
            if(inp[i]=='R')
                R++;
            else if(inp[i]=='G')
                G++;
            else if(inp[i]=='B')
                B++;
        }

        max=R;

        if(G>max)
            max=G;

        if(B>max)
            max=B;

        printf("%d\n",len-max);
    }

    return 0;
}


