#include <stdio.h>
#include <math.h>
#include "component.h"

int e_resistance( float orig_resistance, float *res_array){
  
  int i, numcomp =0; 		//numcomp = antal resistorer (1-3)
  float comp = 100;    		//comp*mult används för att få alla värden i E12-serien.
  float mult = 10000;  		
  float res = orig_resistance; 	//ersättningsresistansen

  for(i = 0; i < 3; i++) 				
    {

      while(comp*mult >= 10 && res/(comp*mult) < 1) 	//Lopar igenom E12-serien, tills e.resistansen är delbart med ett värde. 
	{                                       
	  if(comp*mult == 39*mult || comp*mult == 56*mult)  //Värden som inte kan avrundas till närmaste heltal. Avrundas uppåt.
	    comp = ceil(comp/1.21);
	  else if(comp*mult == 100*mult)    		//Värden som inte kan avrundas till närmaste heltal. Avrundas neråt.
	    comp = floor(comp/1.21);  
	  else                             		//Övriga avrundas till närmaste heltal.
	    comp = roundf(comp/1.21); 
	  if(comp == 10 && mult > 1){   		//mult minskas med en tiopotens efter vaje gång som comp gått från 100 till 10 
	    mult = mult/10;           
	    comp = 100;
	  }
	}                              			
      if(comp >= 10){			
	res_array[i] = comp*mult;  
	res = res - comp*mult;     	
	numcomp++;                	
      }
      else
	res_array[i] = 0;		
      }
  return numcomp;
 }
