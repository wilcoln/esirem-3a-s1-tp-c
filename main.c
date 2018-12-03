#include <stdio.h>
#include <time.h>
#include "events.h"

//#define N 100
// const int iterations_nb = 500;
int swap_nb,compare_nb;
clock_t nb_coups;

int main(){
	/*event events[N];
	create_events(N,events);
	display_events(N,events);

	basic_sort(events,N);
	printf(" On tri le tableau par bubble\n");
	display_events(N,events);*/

// Calcul du temps de cacul de chaque tri;;
	/*printf("\n\n***Test avec taille du tableau = %d et nombre itération  = %d ***\n\n\n", N,iterations_nb);
	clock_t t = temps_calcul(BASIC);
	printf("> Temps mis par le tri Basic %ld coups, nb_swap = %d, nb_compare = %d\n\n", t, nb_swap,nb_compare);
	t = temps_calcul(SELECTION);
	printf("> Temps mis par le tri Selection %ld coups, nb_swap = %d, nb_compare = %d\n\n", t,nb_swap,nb_compare);
	t = temps_calcul(BUBBLE);
	printf("> Temps mis par le tri Bubble %ld coups, nb_swap = %d, nb_compare = %d\n\n", t, nb_swap,nb_compare);
	t = temps_calcul(INSERTION);
	printf("> Temps mis par le tri Insertion %ld coups,nb_swap = %d, nb_compare = %d\n\n", t, nb_swap,nb_compare);
	t = temps_calcul(QUICK);
	printf("> Temps mis par le tri Quick %ld coups,nb_swap = %d, nb_compare = %d\n\n", t, nb_swap,nb_compare);
	printf("***Fin Test\n\n");*/

	/*perf p = evalue_performance(BASIC,100,500);
	display_performance(p);*/
   FILE *file;
   file = fopen("performances.csv","w");
   int data_size[7] = {100, 200, 500, 1000,2000,5000,10000};
   int iterations_nb[5] = {100, 200, 400, 500, 600};
   size_t j,i;
   perf p;

   fprintf(file,"ALGORITHME,DATA SIZE,ITERATIONS,COUPS HORLOGE,SWAPS NB,COMPARE N\n");
   //BASIC SORT Remplissage
   for(j = 0; j < 3; j++){
   		for(i = 0; i < 1; i++){
   			p = evalue_performance(BASIC, data_size[j], iterations_nb[i]);
   			record_performance(file,p);
   		}

   }
   //BUBBLE SORT Remplissage
   for(j = 0; j < 3; j++){
   		for(i = 0; i < 1; i++){
   			p = evalue_performance(BUBBLE, data_size[j], iterations_nb[i]);
   			record_performance(file,p);
   		}

   }
   //INSERTION SORT Remplissage
   for(j = 0; j < 3; j++){
   		for(i = 0; i < 1; i++){
   			p = evalue_performance(INSERTION, data_size[j], iterations_nb[i]);
   			record_performance(file,p);
   		}

   }
   //QUICK SORT Remplissage
   for(j = 0; j < 3; j++){
   		for(i = 0; i < 1; i++){
   			p = evalue_performance(QUICK, data_size[j], iterations_nb[i]);
   			record_performance(file,p);
   		}

   }
   fclose(file);

   
	return 0;
	
}
