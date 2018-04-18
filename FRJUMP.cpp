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
#define INPUT freopen("myInput.txt","r",stdin);
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

int factors[100005][130],len[100005];
long long int memo[MAX];
double logTable[MAX];
map <int,int> modularInverse;

void smallProblem(int N);

void smallProblem(int N)
{
    int i,Q,a,b,c;
    int arrayy[15];
    long long int ans;


    for(i=1;i<=N;i++)
    {
        getInt(arrayy[i])
    }

    getInt(Q)

    while(Q--)
    {
        getInt(a)

        if(a==2)
        {
            getInt(b)

            ans=1;

            for(i=1;i<=N;i+=b)
            {
                ans*=arrayy[i];
            }

            c=ans%MOD;

            while(ans>=10)
            {
                ans/=10;
            }

            b=ans;

            printf("%d %d\n",b,c);
        }

        else
        {
            getInt(b)
            getInt(c)

            arrayy[b]=c;
        }
    }
}

long long int fastExp(int base , int power);

long long int fastExp(int base , int power)
{
    if(power==0)
        return 1;
    else if(power==1)
        return base;
    else if(power%2==0)
    {
        long long int temp=fastExp(base,power/2);
        return (temp*temp)%MOD;
    }
    else
    {
        long long int temp=fastExp(base,power/2);
        return (((temp*temp)%MOD)*base)%MOD;
    }
}

int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int N,Q;
    int i,j,a,b,c;
    int arrayy[MAX],home;
    double tempd;
    long long int templl;


    getInt(N)

    if(N<=10)
    {
        smallProblem(N);
    }

    else
    {
        getInt(home)

        for(i=1;i<N;i++)
            getInt(arrayy[i])

        for(i=0;i<=N;i++)
        {
            len[i]=0;
            memo[i]=1;
            logTable[i]=0.0;
        }

        for(i=1;i<=N;i++)
        {
            for(j=i;j<=N;j+=i)
            {
                factors[j][len[j]++]=i;
            }
        }

        for(i=1;i<N;i++)
        {
            for(j=0;j<len[i];j++)
            {
                memo[factors[i][j]]=(memo[factors[i][j]]*arrayy[i])%MOD;
                logTable[factors[i][j]]=(logTable[factors[i][j]] + log10((double)arrayy[i]) );
            }
        }

        getInt(Q)

        while(Q--)
        {
            getInt(a)

            if(a==1)
            {
                getInt(b)
                b--;
                getInt(c)

                if(b==0)
                {
                    home=c;
                    continue;
                }

                for(j=0;j<len[b];j++)
                {
                memo[factors[b][j]]=(memo[factors[b][j]]*c)%MOD;

                if(modularInverse.find(arrayy[b])==modularInverse.end())
                    modularInverse[arrayy[b]]=fastExp(arrayy[b],MOD-2);

                memo[factors[b][j]]=(memo[factors[b][j]]*modularInverse[arrayy[b]])%MOD;

                logTable[factors[b][j]]=(logTable[factors[b][j]] + log10((double)c) );
                logTable[factors[b][j]]=(logTable[factors[b][j]] - log10((double)arrayy[b]) );

                }

                arrayy[b]=c;
            }

            else
            {
                getInt(b)
                tempd=logTable[b]+log10((double)home);
                templl=(memo[b]*home)%MOD;
                printf("%d %lld\n",(int)(pow((double)10.0,tempd-floor(tempd))+EPS) ,templl);
            }
        }
    }
    




    return 0;
}


