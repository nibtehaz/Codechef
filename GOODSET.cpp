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
#define SAAD_HAQUE 1000000000
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


struct PrimeFactor
{
    int factor;
    int power;
};

struct Query
{
    int L;      // segment
    int R;
    int X;      // divider
    int Y;
    int index;
    int segment;
};

int sieve[1000005] = {0,};
vector <int> primo ;
PrimeFactor factors[100005][20];
int factorsLen[100005]={0,};
int answers[100005];
int leftTranslation[1000005];
int rightTtranslation[1000005];
Query queries[100005];
int sqrtSegment;
int tree[314999]={0,};
set <int>updateBox;
set <int>::iterator it;
int updateBoxVal[1000005];
int deleteBox[1000005];
int deleteBoxLen;

void sieveAndPrimo()
{
    int i,j;

    sieve[0]=1;
    sieve[1]=1;

    for(i=2;i<1100;i++)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<1000002;j+=i)
            {
                sieve[j] = 1 ;
            }
        }
    }

    for(i=2;i<1000001;i++)
    {
        if(sieve[i]==0)
        {
            primo.pb(i);
        }
    }

    j=0;

    for(i=0;i<primo.size();i++)
    {
        for(;j<=primo[i];j++)
        {
            leftTranslation[j]=primo[i];
        }
    }

    i--;

    for(;j<1000002;j++)
    {
        leftTranslation[j]=-1;
    }

    j=0;

    for(;j<primo[0];j++)
    {
        rightTtranslation[j]=-1;
    }

    for(i=1;i<primo.size();i++)
    {
        for(;j<primo[i];j++)
        {
            rightTtranslation[j]=primo[i-1];
        }
    }

    i--;

    for(;j<1000002;j++)
    {
        rightTtranslation[j]=primo[i];
    }
    
    for(i=0;i<primo.size();i++)
    {
        sieve[primo[i]] = i;
 
        //printf("%d %d %d\n",primo[i],sieve[primo[i]],i);
        
    }

}

void primeFactorization(int index , int number)
{
    int num;
    int i;
    int cnt;

    num = number;

    for(i=0;i<primo.size();i++)
    {
        if(primo[i]*primo[i]>num)
        {
            break;
        }

        if(num % primo[i]==0)
        {
            cnt = 1 ;
            num /= primo[i];

            while(num % primo[i] ==0)
            {
                num /= primo[i];
                cnt++;
            }

            
            factors[index][factorsLen[index]].factor=primo[i];
            factors[index][factorsLen[index]].power=cnt;
            factorsLen[index]++;
        }
    }

    if(num!=1)
    {
        factors[index][factorsLen[index]].factor=num;
        factors[index][factorsLen[index]].power=1;
        factorsLen[index]++;
    }
}

bool isFirstSmaller(Query a , Query b)
{
    if(a.segment != b.segment)
    {
        return a.segment < b.segment;
    }

    else
    {
        return a.R < b.R ;
    }
}

int quora(int node , int L , int R , int X , int Y )
{
    if(X<=L && R<=Y)
    {
        return tree[node];
    }

    if(R<X || Y<L)
    {
        return 0;
    }

    int mid = (L+R)>>1;
    int leftChild = node<<1;
    int rightChild = leftChild + 1 ;

    return quora(leftChild,L,mid,X,Y) + quora(rightChild,mid+1,R,X,Y);
}

void update(int node , int L , int R , int index , int incri)
{
    if(L==R)
    {
        tree[node] += incri;
        return;
    }

    int mid = (L+R)>>1;
    int leftChild = node<<1;
    int rightChild = leftChild + 1 ;

    if(index<=mid)
    {
        update(leftChild,L,mid,index,incri);
    }

    else
    {
        update(rightChild,mid+1,R,index,incri);
    }

    tree[node] = tree[leftChild] + tree[rightChild];
}

void add(int index)
{
    for(int i=0;i<factorsLen[index];i++)
    {
        if(updateBox.find(sieve[factors[index][i].factor])==updateBox.end())
        {
            updateBox.insert(sieve[factors[index][i].factor]);
            updateBoxVal[sieve[factors[index][i].factor]] = factors[index][i].power ;
        }
 
        else
        {
            updateBoxVal[sieve[factors[index][i].factor]] += factors[index][i].power ;
        }
    }    
}

void removee(int index)
{
    for(int i=0;i<factorsLen[index];i++)
    {
        if(updateBox.find(sieve[factors[index][i].factor])==updateBox.end())
        {
            updateBox.insert(sieve[factors[index][i].factor]);
            updateBoxVal[sieve[factors[index][i].factor]] = -factors[index][i].power ;
        }
 
        else
        {
            updateBoxVal[sieve[factors[index][i].factor]] -= factors[index][i].power ;
        }
    }    
}

void lazyUpdate(int X , int Y)
{
 
    it =  updateBox.upper_bound(X-1);
 
    while((*it<=Y)&&(it!=updateBox.end()))
    {
        update(1,0,78500,*it,updateBoxVal[*it]);
        deleteBox[deleteBoxLen++]=*it;
        it++;
    }
 
    
 
    for(int i=0;i<deleteBoxLen;i++)
    {
        updateBox.erase(deleteBox[i]);
    }
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N,Q;
    int i,j;
    int L,R,X,Y;
    int currentL = 0 , currentR = 0 ;


    // generate sieve and primes

    sieveAndPrimo();

    //printf("%d %d\n",leftTranslation[2],rightTtranslation[2]);
    //printf("%d %d\n",leftTranslation[1],rightTtranslation[1]);
    //printf("%d %d\n",leftTranslation[10],rightTtranslation[10]);
    //printf("%d %d\n",leftTranslation[1000000],rightTtranslation[1000000]);
    


    // factorizing the numbers

    getInt(N)

    for(i=0;i<N;i++)
    {
        getInt(j)

        primeFactorization(i,j);
    }

    // getting queries

    getInt(Q)

    sqrtSegment = sqrt(Q);

    for(i=0;i<Q;i++)
    {
        scanf("%d%d%d%d",&L,&R,&X,&Y);

        queries[i].L = L; 
        queries[i].R = R;
        queries[i].X = X;
        queries[i].Y = Y;
        queries[i].index = i;
        queries[i].segment = L/sqrtSegment;
    }

    // sort queries

    sort(queries,queries+Q,isFirstSmaller);

    // mo's algorithm

    //add(0);

    for(i=0; i<Q; i++)
    {
        L = queries[i].L;
        R = queries[i].R;

        while(currentL < L)
        {
            removee(currentL-1);
            currentL++;
        }

        while(currentL > L)
        {
            add(currentL-2);
            currentL--;
        }

        while(currentR <= R)
        {
            add(currentR-1);
            currentR++;
        }

        while(currentR > R+1)
        {
            removee(currentR-2);
            currentR--;
        }

        if(leftTranslation[queries[i].X]==-1 || rightTtranslation[queries[i].Y]==-1 || leftTranslation[queries[i].X]>rightTtranslation[queries[i].Y])
        {
            answers[queries[i].index]=0;
        }

        else 
        {
            //printf("Sum from %d to %d\n",sieve[leftTranslation[queries[i].X]],sieve[rightTtranslation[queries[i].Y]]);
            lazyUpdate(sieve[leftTranslation[queries[i].X]],sieve[ rightTtranslation[queries[i].Y]]);
            answers[queries[i].index] = quora(1,0,78500,sieve[leftTranslation[queries[i].X]],sieve[rightTtranslation[queries[i].Y]]);
        }

    }

    for(i=0;i<Q;i++)
    {
        printf("%d\n",answers[i]);
    }
    
    return 0;

}
