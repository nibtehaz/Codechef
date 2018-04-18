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
#define MAX 1000015
#define MOD 1000000007
#define EPS 1e-9
 
#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("B-large-practice.in","r",stdin);
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
 
 
 
int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma
 
    int T;
    long long int H,S;
    double a,b,c,temp,theta;
 
    getInt(T)
 
    while(T--)
    {
        getLong(H)
        getLong(S)
 
        if(4*S>H*H)
            printf("-1\n");
 
        else
        {
            a=(double)H;
 
            theta = (asin((4.0*(double)S)/(a*a)))/2.0;
 
            b=a*sin(theta);
            c=a*cos(theta);
 
            if(b-c>EPS)
            {
                temp=b;
                b=c;
                c=temp;
            }
 
 
            printf("%.6lf %.6lf %.6lf\n",b,c,a);
 
        }
    }
 
    return 0;
}
 