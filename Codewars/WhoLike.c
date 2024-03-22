#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// result string must be a heap-allocated, nul-terminated string
// to be freed by the tests suite

char *likes(size_t n, const char *const names[n]) {
    char *result = NULL;

    if (n == 0 || names[0][0] == '\0')
    {
            result = calloc(12, sizeof(char));
            if (result == NULL)
                return NULL;
            strcat(result, "no one likes this");
            return result;
    }
    else if (n == 1)
    {
        result = calloc(strlen(names[0]) + 1 + 12, sizeof(char));
        if (result == NULL)
            return NULL;
        strcat(result, names[0]);
        strcat(result, " likes this");
        return result;
    }
    else if (n == 2)
    {
        result = calloc(strlen(names[0]) + strlen(names[1]) + 1 + 15, sizeof(char));
        if (result == NULL)
            return NULL;
        strcat(result, names[0]);
        strcat(result, " and ");
        strcat(result, names[1]);
        strcat(result, " like this");
        return result;
    }
    else if (n == 3)
    {
        result = calloc(strlen(names[0]) + strlen(names[1]) + strlen(names[2]) + 1 + 17, sizeof(char));
        if (result == NULL)
            return NULL;
        strcat(result, names[0]);
        strcat(result, ", ");
        strcat(result, names[1]);
        strcat(result, " and ");
        strcat(result, names[2]);
        strcat(result, " like this");
        return result;
    }
    else{
        result = calloc(strlen(names[0]) + strlen(names[1]) + 1 + 25, sizeof(char));
        if (result == NULL)
            return NULL;
        strcat(result, names[0]);
        strcat(result, ", ");
        strcat(result, names[1]);
        strcat(result, " and ");
        int others = n - 2;
        char others_str[12];
        sprintf(others_str, "%d", others);
        strcat(result, others_str);
        strcat(result, " others like this");
        return result;
    }
}
int main()
{
    const char *names[] = {};
    printf("%s\n", likes(0, names));
    return 0;
}

