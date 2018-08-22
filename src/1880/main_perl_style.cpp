#include <cstdio>
#include <map>

std :: map<int, int> a;
int ans = 0, n, c;

int main() {
        while (scanf("%d", &n) == 1)
                for (; n; n--)
                        scanf("%d", &c), ans += ++a[c] == 3;
        printf("%d", ans);
}
