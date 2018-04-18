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

    long long int T,a[40],temp;
    int found=0;
    int i,j;

    getLong(T)

    while(T--)
    {
        getLong(a[0])
        getLong(a[1])
        getLong(a[2])
        getLong(a[3])

        found=0;

        for(i=1;i<16;i++)
        {
            temp=0;

            for(j=0;j<4;j++)
            {
                if(checkBit(i,j))
                {
                    temp+=a[j];
                }
            }

            //DEBUG(temp)

            if(temp==0)
            {
                found=1;
            }

        }

        if(found)
        {
            printf("Yes\n");
        }

        else
        {
            printf("No\n");
        }
    }


    return 0;
}