#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, t, n, x, y, j, m, cnt, a = 0;

    scanf("%d", &t);
    int* max = (int *)malloc(sizeof(int)*t);

    for (i=0;i<t;i++) {
        scanf("%d %d", &x, &y);

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
            if (cnt > a) {
                a = cnt;
            }
        }
        max[i] = a;
    }

    for (i=0;i<t;i++) {
        printf("%d\n", max[i]);
    }

    return 0;
}
