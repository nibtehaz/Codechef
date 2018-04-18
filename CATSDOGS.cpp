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

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N,C,D,L;
    int standingAnimal,minStandingAnimal,maxStandingAnimal;

    getInt(N)

    while(N--)
    {
        getInt(C)
        getInt(D)
        getInt(L)

        if(L%4!=0)
        {
            printf("no\n");
        }

        else
        {
            standingAnimal=L/4;
            maxStandingAnimal = C+D;

            if(D*2>=C)
            {
                minStandingAnimal = D;
            }

            else
            {
                minStandingAnimal = D + (C-2*D) ;
            }

            if((minStandingAnimal<=standingAnimal)&&(standingAnimal<=maxStandingAnimal))
            {
                printf("yes\n");
            }

            else
            {
                printf("no\n");
            }
        }
    }

    return 0;
}
