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

    #define INF 1000000000

    long long int fib[100005][2];

    void initFibo()
    {
        int i;

        fib[1][0] = (long long int)1;
        fib[1][1] = (long long int)0;

        fib[2][0] = (long long int)0;
        fib[2][1] = (long long int)1;

        for(i=3;i<=100002;i++)
        {
            fib[i][0] = (fib[i-1][0] + fib[i-2][0]) % MOD;
            fib[i][1] = (fib[i-1][1] + fib[i-2][1]) % MOD;
        }

    }

    int main()
    {  
        // Bismillahir Rahmanir Rahim
        // Rabbi Zidni Ilma 

        int T,M,N;
        int i;
        long long int ele;
        long long int ans;

        initFibo();

        getInt(T)

        while(T--)
        {
            getInt(M)
            getInt(N)

            ans = (long long int)0;

            for(i=0;i<M;i++)
            {
                getLong(ele)

                ele = (((ele * fib[N][0])% MOD) * M ) % MOD;

                ans = (ans+ele)%MOD;
            }

            for(i=0;i<M;i++)
            {
                getLong(ele)

                ele = (((ele * fib[N][1])% MOD) * M ) % MOD;

                ans = (ans+ele)%MOD;
            }

            printf("%lld\n",ans);
        }


        return 0;
    }
