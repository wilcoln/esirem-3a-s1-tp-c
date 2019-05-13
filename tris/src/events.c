/********
 * Name : events.c
 * Author: Wilfried Bounsi & Ulrich Fonkoue TD2 TP3
 * Description: contient les différentes fonctions demandées lors du TP et autres fonctions utilitaires
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "events.h"

//======================== Constantes et variables externes ===============================//
const char MONTHS[12][10] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"};
extern compare_nb,swap_nb;
extern clock_t coups_nb;


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


//===================== Fonctions principales ===================================

/**
 * Name: genere_dates
 * @param : un enter {n} et un cas {cas}
 * Description: Génère n dates et renvoie un pointeur correspondant au tableau contenant ces dernières 
 * 				- si cas = RANDOM, les dates sont générées aléatoirement
 * 				- si cas = BEST, les dates sont générées dans l'ordre croissant
 * 				- si cas = WORST, les dates sont générées dans l'ordre décroissant
 */ 
date* generate_dates(int n, Case cas){
	srand(time(NULL));
	int index_month;
	date* dates;
	dates = malloc(n*sizeof(date));
	int i;
	switch(cas){
		case RANDOM:
			for(i = 0; i < n; i++){
				dates[i].day =  1 + rand()%30;
				index_month = rand()%11;
				strcpy(dates[i].month, MONTHS[index_month]);
				dates[i].month[strlen(MONTHS[index_month])] = '\0';
				dates[i].year = 1999 + rand()%101;
			}
		break;
		case BEST:
			for(i = 0; i < n; i++){
				dates[i].day =  1 + rand()%30;
				index_month = rand()%11;
				strcpy(dates[i].month, MONTHS[index_month]);
				dates[i].month[strlen(MONTHS[index_month])] = '\0';
				dates[i].year = 1999 + i;
			}
		break;
		case WORST:
			for(i = 0; i < n; i++){
				dates[i].day =  1 + rand()%30;
				index_month = rand()%11;
				strcpy(dates[i].month, MONTHS[index_month]);
				dates[i].month[strlen(MONTHS[index_month])] = '\0';
				dates[i].year = (1999 + n) - i;
			}
		break;
	}	
	return dates;		
}

/**
 * Name : create_events
 * @params : un entier {n} et un tableau d'évènements {events[]} préalablement alloué
 * Description: remplis le tableau events[] avec n évènements créés avec des dates aléatoires 
 */
// void create_events(int n, event events[]){
// 	int i;
// 	char date_str[9];
// 	date* dates = generate_dates(n); // Création des dates aléatoires
// 	for(i = 0; i < n; i++){
// 		events[i].date_of_event = dates[i];
// 		stringify(dates[i],date_str);
// 		strcpy(events[i].description,"Event-");
// 		strcat(events[i].description, date_str);
// 	}
// }

/**
 * Name : create_events (moidifié)
 * @params : un entier {n}, un tableau d'évènements {events[]} préalablement alloué et un cas {cas}
 * Description: remplis le tableau events[] avec n évènements créés avec des dates générés avec  un ordre dépendant du cas.
 */
void create_events(int n, event events[], Case cas){
	int i;
	char date_str[9];
	date* dates = generate_dates(n, cas); // Création des dates aléatoires, pour cas = RANDOM
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
	compare_nb++; // On incrémente le nombre global de comparaison
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
 * Description : renvoie l'indice du plus petit élément du sous tableau events[i:].
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

/**
 * Name : selection_sort
 * @params : un tableau d'évènements {events[]} de taille {n}
 * Description : tri le tableau selon le principe du tri par selection.
 */ 
void selection_sort(event events[], int n){
	int i,j,min_index;
	for(i = 0; i < n ; i++){
		min_index = min_array(events, n, i);
		if(min_index != i)
			swap_events(events,min_index,i);
	}
}

/**
 * Name : basic_sort
 * @params : un tableau d'évènements {events[]} de taille {n}
 * Description : tri le tableau selon le principe du tri basic, qui n'est en fait que le tri par selection.
 */ 
void basic_sort(event events[], int n){
	int i,j,min_index;
	for(i = 0; i < n ; i++){
		min_index = min_array(events, n, i);
		if(min_index != i)
			swap_events(events,min_index,i);
	}
}

/**
 * Name : bubble_sort
 * @params : un tableau d'évènements {events[]} de taille {n}
 * Description : tri le tableau selon le principe du tri bulle.
 */ 
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

/**
 * Name : insertion_sort
 * @params : un tableau d'évènements {events[]} de taille {n}
 * Description : tri le tableau selon le principe du tri insertion.
 */ 
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

/**
 * Name : partition
 * @params : un tableau d'évènements {events[]} un indice de début {a} et un indice de fin {b}
 * @return : renvoie l'indice pivot du sous tableau events[a:b]
 * Description : l'indice pivot est un indice du tableau pour lequel
 * 				 - les éléments d'indice précédents sont plus petit (au sens large)
 * 				 - les éléments d'indice suivants sont plus grands (au sens large)
 */
int partition(event events[], int a, int b){
	/* int pivot = a; */
	int i;
	event tmp;
	/* for(i = a + 1; i <= b; i++){
		if(compare_events(events[pivot],events[i]) == 1){
			tmp = events[i];
			events[i] = events[pivot+1];
			events[pivot+1] = events[pivot];
			events[pivot] = tmp;
			pivot++;
		}
	} */
	tmp = events[b];
	int pivot = a-1;
	for(i = a; i < b; i++){
		if(compare_events(tmp,events[i]) == 1){
			pivot++;
			swap_events(events, pivot, i);
		}
	}
	pivot++;
	swap_events(events,pivot,b);
	return pivot;
}

/**
 * Name : quick_sort
 * @params : un tableau d'évènements {events[]} un indice de début {a} et un indice de fin {b}
 * Description : tri le sous tableau events[a:b] par le principe du tri rapide.
 */
void quick_sort(event events[], int a, int b){
	if(b > a){
		int pivot = partition(events,a,b);
		quick_sort(events,a, pivot - 1);
		quick_sort(events,pivot + 1, b);
	}
}

/**
 * Name : merge
 * @params : un tableau d'évènements {events[]} un indice de début {a}, un indice intermédiare {c} et un indice de fin {b}
 * Description : fusionne les sous tableaux events[a:c] et events[c+1:b], sous réserve qu'ils soient déjà triés.
 */
void merge(event events[], int a, int c, int b){
	 int t1 = c-a+1;
	 int t2 = b-c;
	 int k = a, i = 0, j = 0;
	event sub1[t1];
	event sub2[t2];
	for(i = a; i <= c; i++ )
		sub1[i-a] = events[i];
	for(i = c+1; i<=b; i++)
		sub2[i-c-1] = events[i];
	i=0;
	for(k = a; k<= b; k++){
		if( i >  t1 - 1 ){
			events[k] = sub2[j];
			j++;
		}else if(j > t2 - 1){
			events[k] = sub1[i];
			i++;
		}else if( compare_events(sub1[i],sub2[j]) == 1){
			events[k] = sub2[j];
			j++;
		}else{
			events[k] = sub1[i];
			i++;
		}
	}
}

/**
 * Name : merge_sort
 * @params : un tableau d'évènements {events[]} un indice de début {a} et un indice de fin {b}
 * Description : tri le sous tableau events[a:b] par le principe du tri fusion.
 */
void merge_sort(event events[], int a , int b){
	if(b > a){
		int mil = (a+b)/2;
		merge_sort(events, a , mil);
		merge_sort(events, mil + 1, b);
		merge(events, a, mil, b);
	}
}


/**
 * Name : evalue_performance
 * @params : - un type de tri {sort} pouvant être BASIC, SELECTION, BUBBLE, INSERTION, QUICK ou MERGE
 * 			 -  une taille de donnée {data_size}
 * 			 -  un nombre d'itération {itérations_nb}
 * 			 -  un cas {cas}, pouvant être RANDOM, BEST ou WORST
 * @return : renvoie la performance du tri sort sur un tableau de taille data_size,
 * 			 après itérations_nb nombre d'itérations.
 * Description: les tableaux sont générés pour correspondre au cas passé en paramètre
 *           
 */
Perf evaluate_performance(Sort sort, int data_size, int iterations_nb, Case cas){
	clock_t t1,t2, t_i; double ecart_type = 0;
	char sort_name[128];
	size_t i;
	//Initialisation des compteurs
	compare_nb = 0; swap_nb=0;
	switch(sort){
		case BASIC:
			strcpy(sort_name,"BASIC SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events, cas);
				t_i = clock();
				basic_sort(events,data_size);
				t_i = clock() - t_i;
				ecart_type +=t_i*t_i;
			};
			t2 = clock();
			break;
		case SELECTION:
			strcpy(sort_name,"SELECTION SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events, cas);
				t_i = clock();
				basic_sort(events,data_size);
				t_i = clock() - t_i;
				ecart_type +=t_i*t_i;
			}
			t2 = clock();
			break;
		case BUBBLE:
			strcpy(sort_name,"BUBBLESORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events, cas);
				t_i = clock();
				bubble_sort(events,data_size);	
				t_i = clock() - t_i;
				ecart_type +=t_i*t_i;
			}
			t2 = clock();
			break;
		case INSERTION:
			strcpy(sort_name,"INSERTION SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events, cas);
				t_i = clock();
				insertion_sort(events,data_size);
				t_i = clock() - t_i;
				ecart_type +=t_i*t_i;
			}
			t2 = clock();
			break;
		case QUICK:
			strcpy(sort_name,"QUICK SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events, cas);
				t_i = clock();
				quick_sort(events,0,data_size-1);
				t_i = clock() - t_i;
				ecart_type +=t_i*t_i;
			}
			t2 = clock();
			break;

		case MERGE:
			strcpy(sort_name,"MERGE SORT");
			t1 = clock();
			for(i=0;i<iterations_nb;i++){
				event events[data_size];
				create_events(data_size,events, cas);
				t_i = clock();
				merge_sort(events,0,data_size-1);
				t_i = clock() - t_i;
				ecart_type +=t_i*t_i;
			}
			t2 = clock();
			break;
			
	}
	Perf new_perf;
	new_perf.data_size = data_size;
	new_perf.iterations_nb = iterations_nb;
	new_perf.coups_nb  = (t2-t1)/iterations_nb;
	new_perf.swap_nb = swap_nb;
	new_perf.compare_nb = compare_nb;
	// Calcul de l'écart type
	ecart_type /= iterations_nb;
	ecart_type -= new_perf.coups_nb;
	ecart_type = sqrt(ecart_type);
	new_perf.ecart_type = ecart_type;
	strcpy(new_perf.sort_name, sort_name);
	return new_perf;
	
}

/**
 * Name : display_performance
 * @params : une performance {Perf}
 * Description: Affiche la performance dans le terminal.        
 */
void display_performance(Perf p){
	printf("Affichage Perf ...\n");
	printf("> Performance du tri %s avec une taille %d et un nb d'itération %d \n\t %ld coups, %lf ecart_type, nb_swap = %d, nb_compare = %d\n\n", p.sort_name,  p.data_size, p.iterations_nb, p.coups_nb, p.ecart_type, p.swap_nb,p.compare_nb);
	printf("Fin Perf\n");
}

/**
 * Name : record_perforamnce
 * @params : Un pointeur vers un fichier {file} et une performance {Perf}
 * Description: Enregistre la performance Perf dans le fichier pointé par file.        
 */
void record_performance(FILE* file,Perf p){
   if(file == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   fprintf(file,"%s,%d,%d,%ld,%lf,%d,%d\n",p.sort_name,p.data_size,p.iterations_nb,p.coups_nb, p.ecart_type, p.swap_nb,p.compare_nb);
}

