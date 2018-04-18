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

char reservior[1003][1003];

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int T,N,M;
    int stability;
    int i,j;
    int blockOnTop,airInBottom,waterInBottom,waterOnTop;

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(M)

        stability = 1 ;

        for(i=0;i<N;i++)
        {
            scanf("%s",reservior[i]);
        }

        for(j=0;j<M;j++)
        {
            blockOnTop = 0 ;
            airInBottom = 0 ;
            waterInBottom = 0;
            waterOnTop = 0;

            for(i=0;i<N;i++)
            {
                if(reservior[i][j]=='B')
                {
                    blockOnTop=1;
                }

                else if(reservior[i][j]=='W' )
                {
                    waterOnTop = 1;

                    if(blockOnTop==1 )
                    {
                        waterInBottom = 1;
                        stability=0;
                        break;
                    }

                    if(j!=0)
                    {
                        if(reservior[i][j-1]=='A')
                        {
                            stability=0;
                            break;
                        }
                    }

                    if(j==0)
                    {
                        stability=0;
                        break;
                    }

                    if(j==M-1)
                    {
                        stability=0;
                        break;
                    }

                    if((j+1)<M)
                    {
                        if(reservior[i][j+1]=='A')
                        {
                            stability=0;
                            break;
                        }
                    }
                }

                else if(reservior[i][j]=='A' )
                {
                    if( (blockOnTop==1 || waterOnTop==1)  )
                    {
                        airInBottom = 1;
                        stability=0;
                        break;
                    }

                    /*if(j==0)
                    {
                        stability=0;
                        break;
                    }

                    if((j+1)==M)
                    {
                        stability=0;
                        break;
                    }*/
                }


            }

            if(stability==0)
            {
                break;
            }

        }

        if(stability==0)
        {
            printf("no\n");
        }

        else
        {
            printf("yes\n");
        }
    }


    return 0;
}
