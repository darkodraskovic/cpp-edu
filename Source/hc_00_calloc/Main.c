#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t size = 6;

  char* pStr = (char*)malloc(size * sizeof(char));
  for (int i = 0; i < size; ++i) {
    printf("s[%d]=%c\n", i, pStr[i]);
  }
  free(pStr);
  printf("\n");

  pStr = (char*)calloc(size, sizeof(char));
  if (pStr == NULL) {
    printf("calloc failed!\n");
  }
  for (int i = 0; i < size; ++i) {
    printf("s[%d]=%d=%c\n", i, pStr[i], pStr[i]);
  }
  free(pStr);
  printf("\n");

  int* pInt = (int*)calloc(size, sizeof(int));
  for (int i = 0; i < size; ++i) {
    printf("s[%d]=%d\n", i, pInt[i]);
  }
  free(pInt);
  printf("\n");
}
