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
#define setBit(a,n) a|(1<<n)
#define setBitStatement(a,n) a|=1<<n;
#define resetBit(a,n) a&=~(1<<n);
#define checkBit(a,n) ((a&(1<<n))!=0)
#define toggleBit(a,n) a^=1<<n;
#define doubleingEqual(a,b) (fabs(a-b)<=EPS)
#define doubleingLess(a,b) ((b-a)>=EPS)
#define doubleingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000



int N,K,P;

map <int,int> bank;
map <int,int>::iterator it;

int arr[100005];

int cumSum[100005]={0,};

char inp[100005];

void bankInsert(int inp);
void bankRemove(int inp);
int bankMax();

void bankInsert(int inp);
void bankRemove(int inp);
int bankMax();
int getSum(int starta , int enda);

void bankInsert(int inp)
{
    if(bank.find(inp)==bank.end())
    {
        bank[inp] = 1 ;
    }

    else
    {
        bank[inp]++;
    }
}

void bankRemove(int inp)
{
    if(bank[inp]==1)
    {
        bank.erase(inp);
    }

    else
    {
        bank[inp]--;
    }
}

int bankMax()
{
    it = bank.end();
    it--;
    return it->first;
}

int getSum(int starta , int enda)
{
    //return 0;
    if(starta<enda)
    {
        //printf("In Functions 1 %d %d\n", enda , cumSum[enda]  );
        //printf("In Functions 1 %d %d\n", (starta-1)+1 , cumSum[(starta-1)]  );

        //printf("%d   %d : %d\n",starta,enda,cumSum[enda] - cumSum[starta-1]);

        return cumSum[enda] - cumSum[starta-1];
    }

    else
    {

        //printf("In Functions 2 %d %d\n", enda , (cumSum[enda])  );
        //printf("In Functions 2 %d %d\n", (starta-1)+1 , (cumSum[N]-cumSum[starta-1])  );

        //printf("%d   %d : %d\n",starta,enda,(cumSum[N]-cumSum[starta-1]) + (cumSum[enda]));

        return (cumSum[N]-cumSum[starta-1]) + (cumSum[enda]);
    }
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma


    int i,j;
    int beginner,beginnerEnd,ender,enderStart,temp;

    //INPUT


    getInt(N)
    getInt(K)
    getInt(P)

    K= SMALLER(N,K);

    for(i=1;i<=N;i++)
    {
        getInt(arr[i])
    }

    scanf("%s",inp);

    for(i=1;i<=N;i++)
    {
        cumSum[i] = cumSum[i-1] + arr[i];
    }

    for(i=K;i<=N;i++)
    {
        bankInsert(cumSum[i] - cumSum[i-K]);
    }

    beginner = 1 ;
    ender = N ;


    for(j=0;j<P;j++)
    {
        if(inp[j]=='?')
        {
            printf("%d\n",SMALLER(bankMax(),K));
        }

        else
        {
            //printf("      %d\n",j);

            beginnerEnd = (beginner + K - 1) % N ;

            if(beginnerEnd==0)
            {
                beginnerEnd = N ;
            }

            enderStart = ( ender - K + 1 + N) % N ;

            if(enderStart==0)
            {
                enderStart = N ;
            }

            //printf("Begin %d End %d\n",beginner,ender );

            //printf("First : %d -> %d  \n", beginner , beginnerEnd );
            //printf("Last : %d -> %d  \n" , enderStart , ender );

            temp = getSum( enderStart , ender );

            //printf("delete %d\n",temp);

            bankRemove(temp);

            temp = getSum( beginner, beginnerEnd )  - arr[beginnerEnd] + arr[ender] ;

            bankInsert(temp);

            //printf("insert %d\n",temp);

            beginner = ( beginner - 1 ) % N;

            if(beginner==0)
            {
                beginner = N ;
            }

            ender = ( ender - 1 ) % N;

            if(ender==0)
            {
                ender = N ;
            }

            it = bank.end();
            it--;
            //printf("%d %d\n",j,(it->first));
        }

    }



    return 0;
}