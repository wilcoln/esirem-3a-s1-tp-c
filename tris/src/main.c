#include <stdio.h>
#include <time.h>
#include "events.h"

// #define N 10
int swap_nb,compare_nb;
clock_t nb_coups;

int main(){
	/* event events[N];
	create_events(N,events, RANDOM);
	display_events(N,events);

	quick_sort(events,0, N-1);
	printf(" On tri le tableau par tri rapide\n");
	display_events(N,events);*/


// Evaluation random
   FILE *file;
   int data_size[30];
   int k;
   for(k = 0; k < 30; k++){
	   data_size[k] = 50*(k+1);
   }
   size_t j,i;
   Perf p;
   int iterations_nb;
   int data_size_index = 30;
   

   Sort sorts[6] = {BASIC, SELECTION, BUBBLE, INSERTION, QUICK, MERGE};
   Case cases[3] = {RANDOM,WORST,BEST};
   int s;
   int c;

   for(c = 0; c < 3; c++){
      if(c == 0){
         file = fopen("random.csv","w");
         iterations_nb = 100;
      }
      else if (c == 1){
         file = fopen("worst.csv","w");
         iterations_nb = 1;
      }
      else{
         file = fopen("best.csv","w");
         iterations_nb = 1;
      }
      for(s = 0; s < 6; s++){
         for(j = 0; j < data_size_index; j++){
            p = evaluate_performance(sorts[s], data_size[j],iterations_nb,cases[c]);
            record_performance(file,p);
         }
      }
       fclose(file);
   }

	return 0;
	
}
