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
#define INPUT freopen("in.in","r",stdin);
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



int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int T,N,A;
    int i,j;

    //INPUT

    getInt(T)

    while(T--)
    {
        getInt(N)
        getInt(A)

        if(A==1)
        {
            printf("%d ",N);

            for(i=0;i<N;i++)
            {
                printf("a");
            }
            printf("\n");
        }

        else if(A==2)
        {
            switch(N)
            {
                case 1:
                        printf("1 a\n");
                        break;
                case 2:
                        printf("1 ab\n");
                        break;
                case 3:
                        printf("2 aab\n");
                        break;
                case 4:
                        printf("2 aabb\n");
                        break;
                case 5:
                        printf("3 aaaba\n");
                        break;
                case 6:
                        printf("3 aaabab\n");
                        break;
                case 7:
                        printf("3 aaababb\n");
                        break;
                case 8:
                        printf("3 aaababbb\n");
                        break;
                default:
                        printf("4 ");
                        char basis[20]="abaabbabaabb";
                        for(i=0;i<N;i++)
                        {
                            j=i%12;

                            if(basis[j]=='a')
                            {
                                printf("a");
                            }

                            else
                            {
                                printf("b");
                            }
            
                        }
                        printf("\n");
                        break;
            }
        }

        else
        {
            printf("1 ");

            for(i=0;i<N;i++)
            {
                switch(i%3)
                {
                    case 0:
                            printf("a");
                            break;
                    case 1:
                            printf("b");
                            break;
                    case 2:
                            printf("c");
                            break;
                }
            }

            printf("\n");
        } 
        
    }

    

  

    return 0;
    

}
