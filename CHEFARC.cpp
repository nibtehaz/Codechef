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

#define PI acos(-1.0)
#define MAX 100015
#define MOD 1000000007
#define EPS 1e-9

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("myInput.in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define FPEQUAL(FP1,FP2) fabs(FP1-FP2)<=EPS
#define FPLT(FP1,FP2) (FP1-FP2)<=EPS
#define FPGT(FP1,FP2) (FP1-FP2)>=EPS
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back

#define INF 1000000000

struct Node
{
    int x;
    int y;
};

int T,N,M,K1,K2;

int color[105][105];

int time1[105][105];
int time2[105][105];

int grid[105][105];

bool acceptable(int r,int c);

bool acceptable(int r,int c)
{
    return ( 1<=r && r<=N && 1<=c && c<=M && grid[r][c]==0 && color[r][c]==0);
}


int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int i,j,r,c,minn;

    queue <Node> grays;
    Node temp;

    //INPUT

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(M)
        getInt(K1)
        getInt(K2)

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                getInt(grid[i][j]);

                color[i][j]=0;

                time1[i][j]=INF;
                time2[i][j]=INF;
            }
        }

        grays.push({1,1});
        time1[1][1]=0;
        color[1][1]=1;

        while(grays.size())
        {
            temp=grays.front();

            grays.pop();

            for(i=0;i<=K1;i++)
            {
                for(j=K1-i;j>=0;j--)
                {
                    r=temp.x+i;
                    c=temp.y+j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time1[r][c]=1+time1[temp.x][temp.y];
                        grays.push({r,c});
                    }

                    r=temp.x+i;
                    c=temp.y-j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time1[r][c]=1+time1[temp.x][temp.y];
                        grays.push({r,c});
                    }

                    r=temp.x-i;
                    c=temp.y+j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time1[r][c]=1+time1[temp.x][temp.y];
                        grays.push({r,c});
                    }

                    r=temp.x-i;
                    c=temp.y-j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time1[r][c]=1+time1[temp.x][temp.y];
                        grays.push({r,c});
                    }
                }
            }
        }

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                color[i][j]=0;
            }
        }

        grays.push({1,M});
        time2[1][M]=0;
        color[1][M]=1;

        while(grays.size())
        {
            temp=grays.front();

            grays.pop();

            for(i=0;i<=K2;i++)
            {
                for(j=K2-i;j>=0;j--)
                {
                    r=temp.x+i;
                    c=temp.y+j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time2[r][c]=1+time2[temp.x][temp.y];
                        grays.push({r,c});
                    }

                    r=temp.x+i;
                    c=temp.y-j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time2[r][c]=1+time2[temp.x][temp.y];
                        grays.push({r,c});
                    }

                    r=temp.x-i;
                    c=temp.y+j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time2[r][c]=1+time2[temp.x][temp.y];
                        grays.push({r,c});
                    }

                    r=temp.x-i;
                    c=temp.y-j;

                    if(acceptable(r,c))
                    {
                        color[r][c]=1;
                        time2[r][c]=1+time2[temp.x][temp.y];
                        grays.push({r,c});
                    }
                }
            }
        }

        minn=INF;

        /*for(i=1;i<=N;i++)
            {for(j=1;j<=M;j++) printf("%d ",time1[i][j]); printf("\n");}
            printf("*******************************\n");
                    for(i=1;i<=N;i++)
            {for(j=1;j<=M;j++) printf("%d ",time2[i][j]); printf("\n");}*/


        for(i=1;i<=N;i++)
            for(j=1;j<=M;j++)
                minn=SMALLER(minn,BIGGER(time1[i][j],time2[i][j]));

        if(minn==INF)
            minn=-1;


        printf("%d\n",minn);

    }


    return 0;
}

