#include <stdio.h>
#include <ctype.h>

/*
expression:
  term
  term + expression

term:
  factor
  factor * term

factor:
  number
  ( expression )

*/

void parseFactor(const char **ptr);
void parseTerm(const char **ptr);
void parseExpression(const char **ptr);

int main () {

    const char *expr = "10*10+90";
    parseExpression(&expr);
    printf("Cant parse: %s \n", expr);
    return 0;
}

void parseTerm(const char **expr) {

  parseFactor(expr);
   if(**expr == '*') {
    *expr += 1;
    parseTerm(expr);
    printf("Op: *\n");
  }

  if(**expr == '/') {
    *expr += 1;
    parseTerm(expr);
    printf("Op: /\n");
  }

}


void parseExpression(const char **expr) {
  
  parseTerm(expr);

  if(**expr == '+') {
    *expr += 1;
    parseExpression(expr);
    printf("Op: +\n");
  }

  if(**expr == '-') {
    *expr += 1;
    parseExpression(expr);
    printf("Op: -\n");
  }
  
}

void parseFactor(const char **ptr) {
  char number[256];
  const char *expr = *ptr;

  if (**ptr == '(') {
    *ptr += 1;
    parseExpression(ptr);
    *ptr += 1;
  }
  else {
     int i = 0;
  while ((expr[i] >= '0' && expr[i] <= '9') ) {
    number[i] = expr[i];
    i++;
  }
  number[i] = 0;

  *ptr = expr + i;

  printf("%s \n",number);
}
  }

 
