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

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("A-large (2).in","r",stdin);
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

    int T,N,score,type,inp;
    char inpStr[MAX];

    getInt(T)

    while(T--)
    {
        getInt(N)
        scanf("%s",inpStr);

        if(strcmp(inpStr,"INDIAN")==0)
            type=1;
        else
            type=2;

        score=0;

        while(N--)
        {
            scanf("%s",inpStr);

            if(strcmp(inpStr,"CONTEST_WON")==0)
            {
                score+=300;

                getInt(inp)

                if(inp<20)
                    score+=20-inp;
            }

            else if(strcmp(inpStr,"TOP_CONTRIBUTOR")==0)
            {
                score+=300;
 
            }

            else if(strcmp(inpStr,"BUG_FOUND")==0)
            {
                getInt(inp)
                    score+=inp;
            }

            else
            {
                score+=50;
            }
        }

        printf("%d\n",(score/(200*type)) );
    }

    return 0;
}

