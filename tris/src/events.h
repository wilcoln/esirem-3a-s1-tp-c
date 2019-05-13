/********
 * Name : events.h
 * Author: Wilfried Bounsi & Ulrich Fonkoue TD2 TP3
 * Description: contient:
 * 				- les différentes définition de types de données principales et utilitaires 
 * 				- les différents prototypes de nos fonctions
 */
#include <stdio.h>

//================ Définition des types prédéfinis =====================

/**
 * Définition de la structure date 
 */
typedef struct date{
	int day;
	char month[10];
	int year;
} date;

/**
 * Définition de la structure event
 */
typedef struct event{
	char description[128];
	date date_of_event;
} event;

/**
 * Définition du type énuméré Sort
 * Utilité: permettra d'identifier le type de tri utilisé
 */ 
typedef enum Sort {BASIC,SELECTION,BUBBLE,INSERTION,QUICK, MERGE} Sort;

/**
 * Définition du type énuméré Case
 * Utilité: permettra de préciser si la performance a été mesurée
 * 			- soit dans un cas aléatoire
 * 			- soit dans le meilleur des cas
 * 			- soit dans le pire des cas
 */ 
typedef enum Case {RANDOM, BEST, WORST} Case;

/** 
 * Définition de la structure Perf
 * Utilité: permettra d'enregistrer la performance d'un tri sur un instance de problème.
 */
typedef struct Perf{
	char sort_name[128]; // le nom du tri dont on a mesuré la performance
	int data_size; // la taille des données sur lesquelles la mesure s'est effectuée
	int iterations_nb; // le nombre d'itérations effectuées
	clock_t coups_nb; // le nombre moyens de coups d'horloge effectués par itération (temps moyen)
	double ecart_type; // l'écart type du temps effectué par itération
	int swap_nb; // le nombre de permutations effectuées
	int compare_nb;  // le nombre de comparaisons

} Perf;
 


//================ Liste des prototypes de fonctions ====================//
int numbify(date d);
void stringify(date d, char date_str[]);
int index_of_month(char* month);

date* generate_dates(int n, Case cas);
void create_events(int n, event events[], Case cas);
void display_events(int n, event events[]);
void display_event(event e);

int compare_dates(date d1, date d2);
int compare_events(event e1, event e2);
void swap_events(event events[], int n, int i);
int min_array(event events[], int n, int i);

// Fonctions de tri
void selection_sort(event events[], int n);
void basic_sort(event events[], int n);
void bubble_sort(event events[], int n);
void insertion_sort(event events[], int n);
void quick_sort(event events[], int a, int b);
void merge_sort(event events[], int a, int b);


// Evaluation des performances
void display_performance(Perf p);
Perf evaluate_performance(Sort sort, int data_size, int iterations_nb, Case cas);
void record_performance(FILE* file, Perf p);
