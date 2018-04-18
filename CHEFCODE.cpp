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
#define INPUT freopen("C-large.in","r",stdin);
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
 
long long int bank1[33000];
vector <long long int>bank2;
long long int arr[40]; 
long long int K;
 
int main()
{
    // Bismillahir Rahmanir Rahim 
    // Rabbi Zidni Ilma 

    int N;
    int n1,n2;
    int i,j;
    long long int temp;
long long int tol;

    getInt(N)
    getLong(K)

    for(i=0;i<N;i++)
    {
        getLong(arr[i])
    }

    n1 = N/2;
    
    //DEBUG(n1)
    

    n2 = N - n1;
    
    //DEBUG(n2)

    j = (1<<n1)-1;

    for(i=0;i<=j;i++)
    {
        temp = 1 ;

        for(int i2=0;i2<n1;i2++)
        {


            if((i&(1<<i2))!=0)
            {
tol=K/temp;
if(tol<arr[i2]){temp=-1;break;}

                temp *= arr[i2];
            }

            if(temp>K || temp<0)
            {
                temp=-1;
                break;
            }
        }

        bank1[i]=temp;
        
        //DEBUG(bank1[i])
    }


    j = (1<<n2)-1;

    for(i=0;i<=j;i++)
    {
        //printf("  %d\n",i);
        temp = 1 ;

        for(int i2=0;i2<n2;i2++)
        {
            //printf(" %d ",arr[n1+i2]);
            if((i&(1<<i2))!=0)
            {
tol=K/temp;
if(tol<arr[n1+i2]){temp=-1;break;}

                temp *= arr[ n1 + i2 ];
            }

            if(temp > K || temp<0)
            {
                temp = -1;
                break;
            }
        }

        if(temp!=-1)
        {
            bank2.pb(temp);
        }
        
        //DEBUG(temp)
    }

    sort(bank2.begin(),bank2.end());
    
    /*for(i=0;i<bank2.size();i++)
    {
        printf(" %d ",bank2[i]);
        
    }
    
    printf("\n");*/
    

    long long int ans = 0 ;
    long long int divi;
    int lo,hi,mid;

    j = (1<<n1)-1;

    for(i=0;i<=j;i++)
    {
        if(bank1[i]==-1)
        {
            continue;
        }

        else 
        {
            divi = K / bank1[i];
            

            if(bank2[0]<=divi)
            {
                lo = 0 ; 
                hi = bank2.size()-1;

                while(lo<hi)
                {
                    mid = (lo+hi+1)/2;

                    if(bank2[mid]>divi)
                    {
                        hi = mid - 1 ;
                    }

                    else
                    {
                        lo = mid ; 
                    }
                }
                
                //DEBUG(hi)
                
                mid=(lo+hi)/2;
                //DEBUG(mid)
                ans += (mid+1);    
            }
        }
    }

    printf("%lld\n",ans-1);

    return 0;
}