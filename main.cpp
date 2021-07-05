#include <cstdlib>
#include <stdio.h>

const long long inf = 100000000;

struct pair_intp_int
{
    long long *first;
    long long second;
};


pair_intp_int factor(long long xx)
{

    long long x = xx;
    long long ptr = 0;

    pair_intp_int ret;
    long long *ans = (long long*) malloc(sizeof(long long));
    long long n;
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans[ptr] = i;
            while (x % i == 0)
            {
                x /= i;
            }
            ptr++;
            ans = (long long*) realloc(ans, sizeof(long long) * (ptr + 1));
        }
    }

    if (x > 1)
    {
        //ptr++;
        ans = (long long*) realloc(ans, sizeof(long long) * (ptr + 1));
        ans[ptr] = x;
    }

    ret.first = ans;
    ret.second = ptr + 1;
    return ret;
}

long long get_div(long long x, long long y)
{
    long long a = x, b = y;
    for (long long i = 0; i < x; i++)
    {
        a *= a;
        a %= b;
    }
    return a;
}


int main()
{
    long long x;
    scanf("%ld", &x);
    pair_intp_int s = factor(x);
    long long *a = s.first;
    long long n = s.second;
    long long mult = 1;
    for (long long i = 0; i < n; i++)
        mult *= a[i];
    if (mult >= 32)
        printf("%ld", mult);
    else
    {
        for (long long i = 1; i <= 32; i++)
            if (get_div(mult * i, x) == 0)
            {
                printf("%ld", get_div(mult * i, x));
                break;
            }
    }
    return 0;
}
