#include <stdio.h>

int main(void) {
  
  FILE *fptr;
  fptr = fopen("large.txt", "w");
  int i = 0;
  fprintf(fptr,"1 1000000 999999");
  for(i=1;i<1000000;i++)
   fprintf(fptr," %i %i",i,(i+1));
  
  fclose(fptr);
  
  
  
  return 0;
}
