#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool manza(int x)
{
    char s[20];
    int i  = 0;
    sprintf(s, "%d", x);
    char *str = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    if (str == NULL)
        return (NULL);
    int len = strlen(s);
    while (len > 0)
        str[i++] = s[--len];
    str[i] = '\0';
    if (strcmp(s, str) == 0)
        return (true);
    else
        return (false);
}

int main()
{
    int x = 121;
    bool TF = manza(x);
    printf("This the result : %b", TF);

    return (0);
}
