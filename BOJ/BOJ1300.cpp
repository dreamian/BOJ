#include<cstdio>
#define min(x,y) x<y?x:y;
int n, k, l, r, m;
int main() {
    scanf("%d%d", &n, &k);
    l = 1; r = k;
    while (l <= r) {
        long long c = 0;
        m = (l + r) / 2;
        for (int i = 1; i <= n; i++) c += min(n, m / i);
        c < k ? l = m + 1 : r = m - 1;
    }
    printf("%d", l);
    return 0;
}