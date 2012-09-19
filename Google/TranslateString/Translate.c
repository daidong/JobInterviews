#include <stdio.h>

#define INT2CHAR(i) (i-1+'a')
#define CHAR2INT(c) (c-'0')
#define CHAR2CHAR(c) ((c-'1')+'a')

char gPrintBuffer[1024];

void fakePrint(char c, int pos){
  gPrintBuffer[pos] = c;
}

void transPrint(char *p, int j){
  int i = j;
  if (*p != '\0' && *p > '0' && *p <= '9'){
    char c = *p;
    fakePrint(CHAR2CHAR(c), i++);
    transPrint(p+1, i);
  } else if (*p == '\0'){
    fakePrint('\0', i);
    printf("%s\n", gPrintBuffer);
    return;
  } else {
    return;
  }

  i = j;
  if (*(p+1) != '\0' && *(p+1) >= '0' && *(p+1) <= '9'){
    char c = *p;
    char cn = *(p+1);
    int doubleC = CHAR2INT(c) * 10 + CHAR2INT(cn);
    if (doubleC <= 26){
      fakePrint(INT2CHAR(doubleC), i++);
      transPrint(p+2, i);
    }
  }
  return;
  
}

int main(int argc, char **argv){

  char *inputs = argv[1];  
  transPrint(inputs, 0);
  
}
