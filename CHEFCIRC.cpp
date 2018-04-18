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
 
int N,M;
double pi = acos(-1.0);
double pi2=2.0*pi;
 
bool distanceMemo[505][505]={0,};
double distanceData[505][505];
 
bool alphaMemo[505][505]={0,};
double alphaData[505][505];
 
struct Point
{
    double x;
    double y;
};
 
struct CenterPosition
{
    double theta;
    bool end;
                    // if start then end = 0
                    // if end then end =1
};
 
Point points[505];
CenterPosition centerPositions[2525];
 
bool isFirstSmaller(CenterPosition a, CenterPosition b)
{
    return (b.theta-a.theta>EPS) || ((fabs(b.theta-a.theta)<=EPS) && (a.end==0) ) ;
}
 
double getDistance(int point1 , int point2)
{
    distanceData[point1][point2]=sqrt( (points[point1].x-points[point2].x)*(points[point1].x-points[point2].x) + (points[point1].y-points[point2].y)*(points[point1].y-points[point2].y) );
}
 
void getAlpha(int point1 , int point2)
{
    double alpha = atan2(points[point1].y-points[point2].y,points[point1].x-points[point2].x);
 
    if(alpha<EPS)
    {
        alpha += 2.0*pi;
    }
 
    alphaData[point1][point2]=alpha;
}
 
int checkForPoint (int pointIndex , double radius)
{
    int i;
    int maxx=1;
    int cnt=1;
    double dist;
    double diameter = 2.0 * radius ;
    double alpha , phi , theta ;
    CenterPosition temp;
    int len = 0 ;
 
 
    for(i=0;i<N;i++)
    {
        if(i==pointIndex)
        {
            continue;
        }
 
        dist = distanceData[pointIndex][i];
 
        if((dist-diameter)>EPS)
        {
            continue;
        }
 
        alpha = alphaData[pointIndex][i];
 
        phi = acos(dist/(2.0*radius));
 
 
        centerPositions[len].theta = alpha - phi ;
        centerPositions[len].end = 0 ;
        
        len++;
        

        
        centerPositions[len].theta = alpha + phi ;
        centerPositions[len].end = 1 ;
        
        len++;
        

 
 
    }
 
    if( ((len/2)+1)<M)
    {
        return 1;
    }
 
    else
    {
        sort(centerPositions,centerPositions+len,isFirstSmaller);
 
        for(i=0;i<len;i++)
        {
            if(centerPositions[i].end==0)
            {
                cnt++;
 
                maxx = BIGGER(cnt,maxx);
 
                if(maxx>=M)
                {
                    return maxx;
                }
            }
 
            else
            {
                cnt--;
            }
        }
        
        // 2nd rotation 
        
        for(i=0;i<len;i++)
        {
            if(centerPositions[i].end==0)
            {
                cnt++;
 
                maxx = BIGGER(cnt,maxx);
 
                if(maxx>=M)
                {
                    return maxx;
                }
            }
 
            else
            {
                cnt--;
            }
        }
 
        return maxx;
    }
 
}
 
int iterateAllPoints ( double radius)
{
    int i;
 
    for(i=0;i<N;i++)
    {
        if(checkForPoint(i,radius)>=M)
        {
            return 1;
        }
    }
 
    return 0;
}
 
double BS()
{
    double lo = EPS;
    double hi = 1420.0+EPS;
    double mid;
    double tolerance = 1e-2*.3;
 
    for(int i=0;;i++)
    {
        mid = (lo+hi)/2.0;
 
        if(iterateAllPoints(mid)==1)
        {
            hi = mid;
        }
 
        else
        {
            lo = mid;
        }
 
        if((hi-lo-tolerance)<EPS)
        {
 
            //DEBUG(i)
            break;
        }
    }
 
 
    mid = (lo+hi)/2.0;
 
    return mid;
 
}
 
int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma
 
    int i,j;
    double xx,yy;
    Point temp;
 
    getInt(N)
    getInt(M)
 
    for(i=0;i<N;i++)
    {
        scanf("%lf",&points[i].x);
        scanf("%lf",&points[i].y);
 
    }
 
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            getDistance(i,j);
            getAlpha(i,j);
        }
    }
 
    printf("%.8f\n",BS()+EPS);
 
    return 0;
}
 