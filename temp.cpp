#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int mystrcmp(const char *a, const char *b)
{
    while (*a && *a == *b) ++a, ++b;
    return *a - *b;
}

int main(void)
{
    int in, N, size;
    char str[15];

    scanf("%d", &N);

    dq.clear(); /* 초기화 */
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);

        if (mystrcmp(str, "push_front") == 0)
        {
            scanf("%d", &in);
            dq.push_front(in);
        }
        else if (mystrcmp(str, "push_back") == 0)
        {
            scanf("%d", &in);
            dq.push_back(in);
        }
        else if (mystrcmp(str, "pop_front") == 0)
        {
            if (dq.size() == 0) printf("-1\n");
            else
            {
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
        else if (mystrcmp(str, "pop_back") == 0)
        {
            if (dq.size() == 0) printf("-1\n");
            else
            {
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        }
        else if (mystrcmp(str, "size") == 0)
            printf("%d\n", dq.size());
        else if (mystrcmp(str, "empty") == 0)
            printf("%d\n", dq.empty());
        else if (mystrcmp(str, "front") == 0)
            printf("%d\n", (dq.size() == 0) ? -1 : dq.front());
        else if (mystrcmp(str, "back") == 0)
            printf("%d\n", (dq.size() == 0) ? -1 : dq.back());
    }

    return 0;
}