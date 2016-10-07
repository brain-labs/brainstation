#include <stdio.h>

int main(int argc, char** argv)
{
  if (argc < 3)
    return -1;

  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
    return -1;
  
  FILE *fWrite = fopen(argv[2], "wb"); 
  
  int c = fgetc(f);
  while(c != EOF)
  {
    switch(c)
    {
      case '>':
      case '<':
      case '+':
      case '-':
      case '^':
      case '_':
      case '*':
      case '/':
      case '%':
      case '[':
      case ']':
      case '{':
      case '}':
      case '?':
      case ':':
      case ';':
      case '.':
      case ',':
      case '!':
      case '#':
      case '$':
      {
        fputc(c, fWrite);
        break;
      }
    } 
    c = fgetc(f);
  }

  fclose(f);
  fclose(fWrite);

  return 0;
}

