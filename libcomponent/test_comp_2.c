#include <stdio.h>
#include <stdlib.h>
#include "component_2.h"

int main() {

  float *res_array = (float*)malloc(sizeof(float)*3);
  float orig_resistance;
  int i;

  printf("Ersättningsresistans: ");
  scanf("%f", &orig_resistance);
  //printf("orig_resistance=%f", orig_resistance);	
  
  int count = e_resistance(orig_resistance, res_array);
  
  printf("Antal resistorer: %d\n", count);
  
  for(i = 0; i < 3; i++) {
  
	printf("%f ",res_array[i]);
	
  }
  
  printf("\n");

  free(res_array);
  exit(0);			
}
