#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, t, n, x, y, j, max, m, cnt;
    scanf("%d", &t);

    for (i=0;i<t;i++) {
        scanf("%d %d", &x, &y);
        max = 0;

        for (j=x;j<=y;j++) {
            n = m = 1;
            cnt = 1;

            while (n != j) {
                m = m*2;

                if ((n + m) > j) {
                    m = 1;
                }
                n = n + m;
                cnt++;
            }
            if (cnt > max) {
                max = cnt;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
