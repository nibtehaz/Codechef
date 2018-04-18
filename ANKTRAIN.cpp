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

    int T,N,D;

    getInt(T)

    while(T--)
    {
        getInt(N)

        D=(N-1)/8;
        D=BIGGER(D,0);
        N=(N%8);

        switch(N)
        {
            case 0 :
                    printf("%dSL\n",7+8*D);
                    break;
            case 1 :
                    printf("%dLB\n",4+8*D);
                    break;
            case 2 :
                    printf("%dMB\n",5+8*D);
                    break;
            case 3 :
                    printf("%dUB\n",6+8*D);
                    break;
            case 4 :
                    printf("%dLB\n",1+8*D);
                    break;
            case 5 :
                    printf("%dMB\n",2+8*D);
                    break;
            case 6 :
                    printf("%dUB\n",3+8*D);
                    break;
            case 7 :
                    printf("%dSU\n",8+8*D);
                    break;

        }
    }

    return 0;
}
