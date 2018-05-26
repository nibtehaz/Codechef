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

char inp[100000];

int cumLat[27][8000];
int sumLat[27];

int main()
{  
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int T;
    long long int tot;
    int i,j,k,dc,tt;
    int K,n;

    getInt(T)

    while(T--)
    {
        scanf("%s",inp);
        n =strlen(inp);

        memset(cumLat,0,sizeof(cumLat));

        getInt(K)

        tot=0;


        for(i=1;i<=n;i++)
        {

            for(j=0;j<26;j++)
            {
                cumLat[j][i]=cumLat[j][i-1];
            }

            cumLat[inp[i-1]-'a'][i]++;
        }

        

        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                dc=0;
                tt=0;

                for(k=0;k<26;k++)
                {
        
                    sumLat[k] = cumLat[k][j] - cumLat[k][i-1];

                    if(dc==0 && sumLat[k]!=0)
                    {
                        dc=sumLat[k];
                        tt++;
                    }

                    else if(sumLat[k]!=0)
                    {
                        if(sumLat[k]!=dc)
                        {
                            goto NExt;
                        }
                        else
                        {
                            tt++;
                        }
                    }
                }

                if(tt>=K)
                {
                    tot++;
                }

                NExt:
                ;

            }
        }

        printf("%lld\n",tot);
    }


    return 0;
}
