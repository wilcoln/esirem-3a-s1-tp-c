#include <stdio.h>

typedef struct date{
	int day;
	char month[10];
	int year;
} date;

typedef struct event{
	char description[128];
	date date_of_event;
} event;
typedef enum Tri {BASIC,SELECTION,BUBBLE,INSERTION,QUICK} Tri;



date* remplissage_dates(int n, date* dates);
void stringify(date d, char date_str[]);
int index_of_month(char* month);
void create_events(int n, event events[]);
void display_events(int n, event events[]);
void display_event(event e);
int compare_dates(date d1, date d2);
int compare_events(event e1, event e2);
void swap_events(event events[], int n, int i);
void basic_sort(event events[], int n);
void bubble_sort(event events[], int n);
void insertion_sort(event events[], int n);
int partition(event events[], int a, int b);
void quick_sort(event events[], int a, int b);


// Evaluation des performances

clock_t temps_calcul(Tri tri, int iterations_nb, int data_size);

typedef struct perf
{
	char algo[128];
	int data_size;
	clock_t coups_nb;
	int swap_nb;
	int compare_nb;
	int iterations_nb;

} perf;

void display_performance(perf p);
perf evalue_performance(Tri tri, int data_size, int iterations_nb);
void record_performance(FILE* file, perf p);
