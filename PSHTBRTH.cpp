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
#define floatingEqual(a,b) (fabs(a-b)<=EPS)
#define floatingLess(a,b) ((b-a)>=EPS)
#define floatingGreater(a,b) ((a-b)>=EPS)
 
#define INF 1000000000
 
 
int memo[65650];
int maxx=0;
 
int tree[400025];
int  arr[100005];
 
void init(int node,int lo,int hi);
void update(int node , int lo , int hi , int index , int value);
int query(int node,int lo,int hi,int i,int j);
 
int dp(int number);
void printMat(bool mat[4][4]);
void precalculation();
void numberToMat(int number,bool mat[4][4]);
int matToNumber(bool mat[4][4]);
int transition(int i,int j,int i1,int j1,int number);
 
void init(int node,int lo,int hi)
{
    if(lo==hi)
    {
        tree[node] = arr[lo];
        return;
    }
 
    int mid = (lo+hi)>>1 ;
    int leftNode = node<<1 ;
    int rightNode = leftNode+1 ;
 
    init(leftNode,lo,mid);
    init(rightNode,mid+1,hi);
 
    tree[node] = tree[leftNode]^tree[rightNode];
}
 
void update(int node , int lo , int hi , int index , int value)
{
    if((lo==hi)&&(lo==index))
    {
        tree[node]=value;
        return;
    }
 
    if(index<lo || hi<index)
    {
        return;
    }
 
    int mid = (lo+hi)>>1 ;
    int leftNode = node<<1 ;
    int rightNode = leftNode+1 ;
 
    update(leftNode,lo,mid,index,value);
    update(rightNode,mid+1,hi,index,value);
 
    tree[node] = tree[leftNode] ^ tree[rightNode];
 
}
 
int query(int node,int lo,int hi,int i,int j)
{
    if(j<lo || hi<i)
    {
        return 0;
    }
 
    if(i<=lo && hi<=j)
    {
        return tree[node];
    }
 
    int mid = (lo+hi)>>1 ;
    int leftNode = node<<1 ;
    int rightNode = leftNode+1 ;
 
    return query(leftNode,lo,mid,i,j) ^ query(rightNode,mid+1,hi,i,j);
}
 
int dp(int number)
{
 
    if(number==0)
    {
        return 0;
    }
 
    if(memo[number]!=-1)
    {
        return memo[number];
    }
 
    set<int>nimbers;
 
    bool mat[4][4];
    int i,j,i1,j1;
    int temp;
    int candidate;
 
    numberToMat(number,mat);
 
    //printMat(mat);
    //DEBUG(matToNumber(mat))
 
    int cumSum[5][5]={0,};
 
 
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cumSum[i+1][j+1] = cumSum[i+1][j] + cumSum[i][j+1] - cumSum[i][j] ;
 
            if(mat[i][j])
            {
                cumSum[i+1][j+1]++;
            }
        }
    }
 
    /*for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            printf("%d ",cumSum[i][j]);
        }
 
        printf("\n");
    }*/
 
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            for(i1=i;i1<4;i1++)
            {
                for(j1=j;j1<4;j1++)
                {
                    //printf("%d %d %d %d -> %d | %d\n",i,j,i1,j1,cumSum[i1+1][j1+1] - cumSum[i][j1+1] - cumSum[i1+1][j] + cumSum[i][j],(i1-i+1)*(j1-j+1));
 
                    if( ( cumSum[i1+1][j1+1] - cumSum[i][j1+1] - cumSum[i1+1][j] + cumSum[i][j] ) ==( (i1-i+1)*(j1-j+1) ) )
                    {
 
                        temp = transition(i,j,i1,j1,number);
 
                        //DEBUG(temp);
                        //bool tempMat[4][4];
 
                        //numberToMat(temp,tempMat);
 
                        //printMat(tempMat);
 
                        temp = dp(temp);
 
                        nimbers.insert(temp);
                    }
                }
            }
        }
    }
 
    //maxx = BIGGER(maxx,nimbers.size());
 
    //maxx += nimbers.size();
 
 
    candidate = 0 ;
 
    while(nimbers.size()!=0)
    {
        if(*nimbers.begin()>candidate)
        {
            break;
        }
 
        else
        {
            candidate++;
            nimbers.erase(nimbers.begin());
        }
    }
 
 
    memo[number] = candidate ;
 
    return candidate;
 
}
 
int transition(int i,int j,int i1,int j1,int number)
{
    int row = 0 ;
    int column = 0 ;
 
    for(int c=j;c<=j1;c++)
    {
        column += 1<<(3-c);
    }
 
    for(int r=i;r<=i1;r++)
    {
        row += 1<<((3-r)*4);
    }
 
    return number - row*column;
}
 
void printMat(bool mat[4][4])
{
    printf("******************\n");
 
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<mat[i][j];
        }
 
        printf("\n");
 
    }
 
    printf("******************\n");
}
 
void numberToMat(int number,bool mat[4][4])
{
    for(int i=3;i>=0;i--)
    {
        for(int j=3;j>=0;j--)
        {
            mat[i][j] = number & 1;
            number>>=1;
        }
    }
}
 
int matToNumber(bool mat[4][4])
{
    int number = 0 ;
 
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            number = number<<1 ;
 
            if(mat[i][j])
            {
                number++;
            }
        }
    }
 
    return number;
}
 
void precalculation()
{
    memset(memo,-1,sizeof(memo));
 
    memo[0] = 0 ;
 
    for(int i=0;i<65536;i++)
    {
        if(memo[i]==-1)
        {
            dp(i);
            //printf("%d %d\n",i,memo[i]);
        }
    }
 
    //DEBUG(maxx)
}
 
 
int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma
 
    int T;
    char inp[40];
    int i,j;
    int N,M;
    int temp;
    int q,lo,hi,pos;
 
 
    precalculation();
 
    getInt(T)
 
    while(T--)
    {
        getInt(N)
        getInt(M)
 
        for(i=0;i<N;i++)
        {
            temp = 0 ;
 
            scanf("%s",inp);
 
            for(j=0;j<4;j++)
            {
                temp = (temp<<1) + (inp[j]-'0');
            }
 
            scanf("%s",inp);
 
            for(j=0;j<4;j++)
            {
                temp = (temp<<1) + (inp[j]-'0');
            }
 
            scanf("%s",inp);
 
            for(j=0;j<4;j++)
            {
                temp = (temp<<1) + (inp[j]-'0');
            }
 
            scanf("%s",inp);
 
            for(j=0;j<4;j++)
            {
                temp = (temp<<1) + (inp[j]-'0');
            }
 
 
            //DEBUG(temp)
            //DEBUG(memo[temp])
 
            arr[i]=memo[temp];
        }
 
        init(1,0,N-1);
 
        while(M--)
        {
            getInt(q)
 
            if(q==1)
            {
                getInt(lo)
                getInt(hi)
 
                temp = query(1,0,N-1,lo-1,hi-1);
 
                if(temp==0)
                {
                    printf("Lotsy\n");
                }
 
                else
                {
                    printf("Pishty\n");
                }
            }
 
            else
            {
                getInt(pos)
 
                temp = 0 ;
 
                scanf("%s",inp);
 
                for(j=0;j<4;j++)
                {
                    temp = (temp<<1) + (inp[j]-'0');
                }
 
                scanf("%s",inp);
 
                for(j=0;j<4;j++)
                {
                    temp = (temp<<1) + (inp[j]-'0');
                }
 
                scanf("%s",inp);
 
                for(j=0;j<4;j++)
                {
                    temp = (temp<<1) + (inp[j]-'0');
                }
 
                scanf("%s",inp);
 
                for(j=0;j<4;j++)
                {
                    temp = (temp<<1) + (inp[j]-'0');
                }
                
                
                //DEBUG(temp)
                //DEBUG(memo[temp])
 
                //DEBUG(query(1,0,N-1,0,0))
                //DEBUG(query(1,0,N-1,1,1))
                //DEBUG(query(1,0,N-1,2,2))
                
                update(1,0,N-1,pos-1,memo[temp]);
                
                //DEBUG(query(1,0,N-1,0,0))
                //DEBUG(query(1,0,N-1,1,1))
                //DEBUG(query(1,0,N-1,2,2))
            }
        }
 
    }
 
 
    return 0;
}
 