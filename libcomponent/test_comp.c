#include <stdio.h>
#include <stdlib.h>
int main() {

  int *res_array = (int*)malloc(sizeof(int)*3);
  int orig_resistance;
  int i;

  printf("Ersättningsresistans: ");
  scanf("%d", &orig_resistance);	
  
  int count = e_resistance(orig_resistance, res_array);
  
  printf("Antal resistorer: %d\n", count);
  
  for(i = 0; i < 3; i++)                                    
  printf("%d ",res_array[i]);
  printf("\n");		
}
