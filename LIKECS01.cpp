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

char inp[200];
vector<int>cnt[28]; 

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int T;
    int fnd;
    int i,j,n;

    getInt(T)

    while(T--)
    {
        scanf("%s",inp);

        for(i=0;i<26;i++)
        {
            cnt[i].clear();
        }

        fnd = 0 ;

        for(i=0;inp[i];i++)
        {
            cnt[inp[i]-'a'].pb(i);

            if(cnt[inp[i]-'a'].size()>1)
            {
                fnd=1;
                goto donee;
            }
        }

        

        for(i=0;i<26;i++)
        {
            if(cnt[i].size()==0)
            {
                continue;
            }

            for(j=0;j<26;j++)
            {
                if(cnt[j].size()<2)
                {
                    continue;
                }

                if(cnt[i][0]<cnt[j][cnt[j].size()-2])
                {
                    fnd=1;
                    goto donee;
                }
            }
        }

        donee:

        printf("%s\n",fnd==1?"yes":"no");
    }


    return 0;
}

