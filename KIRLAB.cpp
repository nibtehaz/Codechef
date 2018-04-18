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

bool Sieve[10000001]={0,};
vector<int>primo;
map<int,int>memo;
int arr[100005];
vector<int>tempo;

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j;
    int T,N;
    int num;
    int maxx,tempMax;


    Sieve[0]=1;
    Sieve[1]=1;

    for(i=2;i<3165;i++)
    {
        if(Sieve[i]==0)
        {
            for(j=i*i;j<10000001;j+=i)
            {
                Sieve[j]=1;
            }
        }
    }

    for(i=2;i<3165;i++)
    {
        if(Sieve[i]==0)
        {
            primo.pb(i);
        }
    }

    //DEBUG(primo.size());

    getInt(T)

    while(T--)
    {
        getInt(N)

        for(i=0;i<N;i++)
        {
            getInt(arr[i])
        }

        memo.clear();

        maxx=0;

        for(i=N-1;i>=0;i--)
        {
            num=arr[i];

            if(num==1)
            {
                continue;
            }

            if(Sieve[num]==0)
            {
                if(memo.find(num)==memo.end())
                {
                    memo[num]=1;
                }

                else
                {
                    memo[num]++;
                }

                maxx=BIGGER(maxx,memo[num]);
            }

            else
            {
                tempo.clear();
                tempMax=0;
                for(j=0;j<primo.size();j++)
                {
                    if((primo[j]*primo[j])>num)
                    {
                        break;
                    }

                    if(num%primo[j]==0)
                    {
                        while(num%primo[j]==0)
                        {
                            num/=primo[j];
                        }

                        if(memo.find(primo[j])==memo.end())
                        {
                            ;
                        }

                        else
                        {
                            tempMax=BIGGER(tempMax,memo[primo[j]]);
                        }

                        tempo.pb(primo[j]);

                    }

                }

                if(num!=1)
                {
                    if(memo.find(num)==memo.end())
                    {
                        ;
                    }

                    else
                    {
                        tempMax=BIGGER(tempMax,memo[num]);
                    }

                    tempo.pb(num);
                }

                tempMax++;
                maxx=BIGGER(tempMax,maxx);

                for(j=0;j<tempo.size();j++)
                {
                    memo[tempo[j]]=tempMax;
                }
            }
        }

        maxx=BIGGER(maxx,1);

        printf("%d\n",maxx);
    }

    return 0;
}
