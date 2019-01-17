#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "events.h"

//======================== Constantes et variables externes ===============================//
const char MONTHS[12][10] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"};
extern compare_nb,swap_nb;
extern clock_t coups_nb;
//======================== Fin Constantes et variables externes ============================//




//======================== Fonctions utilitaires ===========================================//

/**
 * Name : index_of_month
 * @params : un mois {month} sous forme de chaine de caractères
 * @return : un entier correspondant à l'indice du mois dans le tableau MONTHS[12][]
 */
int index_of_month(char* month){
	int i = 0;
	while(strcmp(MONTHS[i], month) !=0 && i < 12){
		i++;
	}
	return i;
}

/**
 * Name : numbify
 * @params : une date {d} 
 * @return : un nombre correspondant à l'écriture yyyyymmdd de la date d
 */
int numbify(date d){
	return d.year*10000 + (index_of_month(d.month) + 1)*100 + d.day;
}

/**
 * Name : 
 * @params: une date {d} et une chaine de caractères {date_str}
 * Description: écrit dans date_str la chaine de caractère correspondant à la date sous forme yyyyymmdd
 */ 
void stringify(date d, char date_str[]){
	sprintf(date_str, "%d",numbify(d));
}
//======================== Fin Fonctions utilitaires =======================================//

/**
 * Name: genere_dates
 * @param : un enter {n}
 * Description: Génère aléatoirement n dates et renvoie un pointeur correspondant au tableau contenant ces dernières  
 */ 
date* generate_dates(int n){
	srand(time(NULL));
	int index_month;
	date* dates;
	dates = malloc(n*sizeof(date));
	int i;
	for(i = 0; i < n; i++){
		dates[i].day =  1 + rand()%30;
		index_month = rand()%11;
		strcpy(dates[i].month, MONTHS[index_month]);
		dates[i].month[strlen(MONTHS[index_month])] = '\0';
		dates[i].year = 1999 + rand()%101;
	}
	return dates;
		
}


/**
 * Name : create_events
 * @params : un entier {n} et un tableau d'évènements {events[]} préalablement alloué
 * Description: remplis le tableau events[] avec n évènements créés avec des dates aléatoires 
 */ 
void create_events(int n, event events[]){
	int i;
	char date_str[9];
	date* dates = generate_dates(n); // Création des dates aléatoires
	for(i = 0; i < n; i++){
		events[i].date_of_event = dates[i];
		stringify(dates[i],date_str);
		strcpy(events[i].description,"Event-");
		strcat(events[i].description, date_str);
	}
}

/**
 * Name : display_events
 * @params : un entier {n} et un tableau d'évènements {events[]}
 * Description : Affiche les n premiers évènements contenu dans le tableau events[]
 */ 
void display_events(int n, event events[]){
	int i;
	for(i = 0; i < n; i++){
		printf("%s\n",events[i].description);
	}
}

//Renvoie  1 si d1 > d2, 0 si d1 = d2 et -1 si d1 >
/**
 * Name : compare_dates
 * @params : deux dates {d1} et {d2}
 * @return : -1 si d1 est antérieur à d2, 0  si d1 = d2 et 1 si d1 est postérieur à d2
 */ 
int compare_dates(date d1, date d2){
	int nbd1 = numbify(d1);
	int nbd2 = numbify(d2);
	if( nbd1 > nbd2 ) 
		return 1;
	else if (nbd1 < nbd2)
		return -1;
	else 
		return 0;
}

/**
 * Name : compare_events
 * @params : deux évènements {e1} et {e2}
 * Description: utilise compare_dates pour comparer e1 et e2
 * @return : -1 si e1 est antérieur à e2, 0  si e1 a la même date que e2 et 1 si e1 est postérieur à e2
 */ 
int compare_events(event e1, event e2){
	// On incrémente le nombre global de comparaison
	compare_nb++;

	return compare_dates(e1.date_of_event, e2.date_of_event);
}


/**
 * Name : swap_events
 * @params : un tableau d'évènements {events[]} et deux indices du {index1} et {index2} du tableau
 * Description : échange les positions dans le tableau events[] des évènements se trouvant aux indices index1 et index2
 */ 
void swap_events(event events[], int index1, int index2){
	event tmp = events[index1];
	events[index1] = events[index2];
	events[index2] = tmp;

	// On incrémente le nombre global d'échanges
	swap_nb++;
}

/**
 * Name : min_array
 * @params : un tableau d'évènements {events[]} de taille {n} et  un entier {i}
 * Description : renvoie l'indice du plus petit élément du sous tableau commençant à l'indice i.
 */ 
int min_array(event events[], int n, int i){
	int j,min_index=i;
	for(j = i+1; j < n; j++){
		if(compare_events(events[min_index], events[j]) == 1 ){
			min_index = j;
		}
	}
	return min_index;
}


void selection_sort(event events[], int n){
	int i,j,min_index;
	for(i = 0; i < n ; i++){
		min_index = min_array(events, n, i);
		if(min_index != i)
			swap_events(events,min_index,i);
	}
}

void basic_sort(event events[], int n){
	selection_sort(events, n);
}

void bubble_sort(event events[], int n){
	short int permut = 1;
	int i = 0;
	while(permut){
		permut = 0;
		for(i=1; i< n; i++){
			if(compare_events(events[i-1], events[i]) == 1 ){
				swap_events(events, i-1,i);
				permut = 1;
			}
		}
	}
	
}


void insertion_sort(event events[], int n){
	int i,j,min_index;
	event val;
	for(i = 1; i < n ; i++){
		val = events[i];
		j = i - 1;
		while(j > -1 && compare_events(events[j], val) == 1){
			events[j+1] = events[j];
			j--;
		}
		events[j+1] = val;
	}
}


int partition(event events[], int a, int b){
	int pivot = a;
	int i;
	event tmp;
	for(i = a + 1; i <= b; i++){
		if(compare_events(events[pivot],events[i]) == 1){
			tmp = events[i];
			events[i] = events[pivot+1];
			events[pivot+1] = events[pivot];
			events[pivot] = tmp;
			pivot++;
		}
	}
	return pivot;
}
void quick_sort(event events[], int a, int b){
	if(b > a){
		int pivot = partition(events,a,b);
		quick_sort(events,a, pivot - 1);
		quick_sort(events,pivot + 1, b);
	}
}

//Evaluation des performances
perf evalue_performance(Tri tri, int data_size, int iterations_nb){
	clock_t t1,t2,t_i; double ecart_type = 0;
	char algo[128];
	size_t i;
	//Initialisation des compteurs
	compare_nb = 0; swap_nb=0;
	switch(tri){
		case BASIC:
			strcpy(algo,"BASIC SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events);
				basic_sort(events,data_size);
				t_i = clock();
				ecart_type += t_i*t_i;

			}
			t2 = clock();
			break;
		case SELECTION:
			strcpy(algo,"SELECTION SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events);
				basic_sort(events,data_size);	
			}
			t2 = clock();
			break;
		case BUBBLE:
			strcpy(algo,"BUBBLESORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events);
				bubble_sort(events,data_size);	
			}
			t2 = clock();
			break;
		case INSERTION:
			strcpy(algo,"INSERTION SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events);
				insertion_sort(events,data_size);	
			}
			t2 = clock();
			break;
		case QUICK:
			strcpy(algo,"QUICK SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events);
				quick_sort(events,0,data_size-1);	
			}
			t2 = clock();
			break;
			
	}
	perf new_perf;
	new_perf.data_size = data_size;
	new_perf.iterations_nb = iterations_nb;
	new_perf.coups_nb  = (t2-t1)/iterations_nb;
	new_perf.swap_nb = swap_nb;
	new_perf.compare_nb = compare_nb;
	strcpy(new_perf.algo, algo);
	return new_perf;
	
}
void display_performance(perf p){
	printf("Affichage perf ...\n");
	printf("> Temps mis par le tri %s avec une taille %d et un nb d'itération %d \n\t %ld coups, nb_swap = %d, nb_compare = %d\n\n", p.algo,  p.data_size, p.iterations_nb, p.coups_nb, p.swap_nb,p.compare_nb);
	printf("Fin perf\n");
}
void record_performance(FILE* file,perf p){
   if(file == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   //fprintf(file,"%s,%d,%d,%ld,%d,%d\n",p.algo,p.data_size,p.iterations_nb,p.coups_nb,p.swap_nb,p.compare_nb);
   fprintf("%d,%d,%ld,%d,%d\n",p.data_size,p.iterations_nb,p.coups_nb,p.swap_nb,p.compare_nb);
}

