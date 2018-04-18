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
#define MAX 1000005
#define MOD 1000000007
#define EPS 1e-9
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

    int T,lenA,lenB,present0,present1,missplaced0,missplaced1;
    int i,ans,minn,fail;
    char A[MAX],B[MAX];

    getInt(T)

    while(T--)
    {
        scanf("%s",A);
        scanf("%s",B);

        lenA=strlen(A);
        lenB=strlen(B);

        if(lenB!=lenA)
        {
            printf("Unlucky Chef\n");
            continue;
        }

        missplaced1=0;
        missplaced0=0;
        present1=0;
        present0=0;
        fail=0;

        for(i=0;i<lenA;i++)
        {
            if(A[i]=='1')
                present1=1;
            if(A[i]=='0')
                present0=1;

            if(A[i]=='1' && A[i]!=B[i])
                missplaced1++;

            if(A[i]=='0' && A[i]!=B[i])
                missplaced0++;

        }

        minn=SMALLER(missplaced1,missplaced0);

        ans=minn;

        missplaced0-=minn;
        missplaced1-=minn;

        if(missplaced0!=0)
        {
            if(present1!=0)
            {
                ans+=missplaced0;
            }
            else
                fail=1;
        }

        if(missplaced1!=0)
        {
            if(present0!=0)
            {
                ans+=missplaced1;
            }
            else
                fail=1;
        }

        if(fail==1)
        {
            printf("Unlucky Chef\n");
            continue;
        }

        else
        {
            printf("Lucky Chef\n");
            printf("%d\n",ans);
        }
    }


    return 0;
}






