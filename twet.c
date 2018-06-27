
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int d[5010], edge[5010][5010], mark[5010], flag;
int n, m, q;
void dfs(int a, int b)
{
    int i;
    if (a == b)
    {
        flag = 0;
    }
    if (mark[a] == 1)
        return;
    mark[a] = 1;
    for (i = 0; i < n; i++)
    {
        if (edge[a][i] != 0x3f3f3f3f)
        {
            dfs(i, b);
        }
    }
    return;
}
int main()
{
    int T;
    scanf("%d", &T);
    int u, v, w;
    int a, b;
    int i, j, k, c;
    while (T--)
    {
        memset(edge, 0x3f3f3f3f, sizeof(edge));
        scanf("%d %d %d", &n, &m, &q);
        for (i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            edge[u][v] = w;
        }
        for (i = 0; i < q; i++)
        {
            memset(d, 0x3f3f3f3f, sizeof(d));
            scanf("%d %d", &a, &b);
            d[a] = 0;
            for (c = 0; c < n - 1; c++)
            {
                for (j = 0; j < n; j++)
                {
                    for (k = 0; k < n; k++)
                    {
                        if (edge[j][k] != 0x3f3f3f3f)
                        {
                            if (d[k] > d[j] + edge[j][k])
                                d[k] = (d[j] + edge[j][k]);
                        }
                    }
                }
            }
            flag = 1;
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (edge[j][k] != 0x3f3f3f3f)
                    {
                        if (d[k] > d[j] + edge[j][k])
                        {
                            memset(mark, -1, sizeof(mark));
                            dfs(j, k);
                            printf("j:%d flag:%d\n", j, flag);
                        }
                    }
                }
            }
            /*for(j=0;j<n;j++)
            {
                printf("D:%d %d\n",d[j],flag);
            }*/
            if (flag == 1 && d[b] != 0x3f3f3f3f)
                printf("%d\n", d[b]);
            else if (flag == 0 || d[b] == 0x3f3f3f3f)
                printf("no\n");
        }
    }
    return 0;
}
