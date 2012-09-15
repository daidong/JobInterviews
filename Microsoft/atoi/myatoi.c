#include <stdio.h>

int legal(char c){
  if (c >= '0' && c <= '9')
    return 1;
  if (c == '-')
    return 1;
  return 0;
}

int myatoi(char* seq){
  int rtn = 0;
  if (seq == NULL)
    return 0;
  int flag = 1;
  char *p = seq;

  while ( *p != '\0' ){
    if (legal(*p)){
      if (*p == '-' && flag == 1)
	flag = 0;
      else if (*p == '-' && flag == 0)
	return 0;
      else
	rtn = rtn * 10 + (*p - '0');
    } else {
      return 0;
    }
    p++;
  }

  if (flag == 0)
    return (0 - rtn);
  else
    return rtn;
}

int main(int argc, char **argv){
  printf("%d\n", myatoi("-1-234"));
  return 1;
}
