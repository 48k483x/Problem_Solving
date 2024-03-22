//  do not allocate memory for return string
//  assign the value to the pointer "result"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse( char *str){
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++){
    char tmp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = tmp;
  }
}

int count(const char *s){
  int i = 0;
  int count = 0;
  if (s[i] == ' ')
    count--;
  while (s[i])
  {
    if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1])
      count++;
    i++;
  }
  count++;
  return count;
}

char *malloc_str(const char *s)
{
  char *word;
  int i = 0;

  while (s[i] && s[i] != ' ')
    i++;
  word = malloc((i + 1) * sizeof(char *));   
  if (word == NULL)
    return NULL;
  i = 0;
  while (s[i] && s[i] != ' ')
  {
    word[i] = s[i];
    i++;
  }
  word[i] = '\0';
  return word; 
}

char **ft_split(const char *s)
{
  int words = count(s);
  char **result = malloc((words + 1) * sizeof(char *));
  if (result == NULL)
    return NULL;
  int i = 0;
  while (*s)
  {
      while (*s == ' ')
        s++;
      if (*s && *s != ' ')
      {
        result[i] = malloc_str(s);
        i++;
        while (*s && *s != ' ')
          s++;
      }
  }
  result[i] = NULL;
  return result;
}

void spin_words(const char *sentence, char *result) {
  int len = count(sentence);
  char **words = ft_split(sentence);
  result[0] = '\0';
  for (int i = 0; i < len; i++){
    if (strlen(words[i]) >= 5)
      reverse(words[i]);
    strcat(result, words[i]);
    if (i < len - 1)
      strcat(result, " ");
  }
}

int main(int ac, char **av)
{
  char *result = malloc(100 * sizeof(char));
  spin_words(av[1], result);
  printf("%s\n", result);
  return 0;
}
