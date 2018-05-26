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

long long int matt[200][200];

int main()
{  
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int T, N;
    long long int maxx,summ;
    int i,j;

    getInt(T)

    while(T--)
    {
        getInt(N)

        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                getLong(matt[i][j])
            }
        }

        maxx = 0;

        for(i=0;i<N;i++)
        {
            summ=0;
            for(j=0;j<N;j++)
            {
                if((i+j)>=N)
                {
                    break;
                }
                summ += matt[i+j][j];
            }

            maxx=BIGGER(summ,maxx);
        }

        for(i=0;i<N;i++)
        {
            summ=0;
            for(j=0;j<N;j++)
            {
                if((i+j)>=N)
                {
                    break;
                }
                summ += matt[j][i+j];
            }

            maxx=BIGGER(summ,maxx);
        }

        printf("%lld\n",maxx);
        
    }



    return 0;
}
