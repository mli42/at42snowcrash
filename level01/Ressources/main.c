#include <crypt.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
  printf("%s\n", crypt("abcdefg", "42"));
  return (0);
}
