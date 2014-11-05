#include <stdio.h>
#include <math.h>
int e_resistance( int orig_resistance, int *res_array){
  
  int i, numcomp =0; 		//numcomp = antal resistorer i arrayen (1-3)
  int comp = 100;    		//comp*mult används för att få alla värden i E12-serien.
  int mult = 10000;  		
  int res = orig_resistance; 	//ersättningsresistansen

  printf("skickad ersättningsres. %d\n", orig_resistance);

  for(i = 0; i < 3; i++) 				
    {

      while(comp*mult >= 10 && res/(comp*mult) < 1) 	//Lopar igenom E12-serien, tills e.resistansen är delbart med ett värde. 
	{                                       
	  if(comp*mult == 39*mult || comp*mult == 56*mult)  //Värden som inte kan avrundas till närmaste heltal. Avrundas uppåt.
	    comp = ceil(comp/1.21);
	  else if(comp*mult == 100*mult)    		//Värden som inte kan avrundas till närmaste heltal. Avrundas neråt.
	    comp = floor(comp/1.21);  
	  else                             		//Övriga avrundas till närmaste heltal.
	    comp = round(comp/1.21); 
	  //printf("E12-värde i loopen: %d\n", comp*mult);  
	  if(comp == 10 && mult > 1){   		//mult minskas med en tiopotens efter vaje gång som comp gått från 100 till 10 
	    mult = mult/10;           
	    comp = 100;
	  }
	}                              			
      if(comp >= 10){			
	res_array[i] = comp*mult;  
        //printf("Resistor: %d\n",res_array[i]);
	res = res - comp*mult;     	
        //printf("Resterande res: %d\n", res);
	numcomp++;                	
      }
      else
	res_array[i] = 0;		
      }
  return numcomp;
 }
