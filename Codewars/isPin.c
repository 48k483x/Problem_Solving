#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
bool validate_pin(const char *pin) {
  int i = 0;
  while (isdigit(pin[i]))
    i++;
  if (pin[i] != '\0'|| (i < 4 || i > 6))
    return false;
  else
    return true;
}

int main (int ac, char **av)
{
  (void)ac;
  if (validate_pin((const char *)av[1]))
    printf("True\n");
  else if (!validate_pin((const char *)av[1])) {
    printf("False\n");
  }
}
