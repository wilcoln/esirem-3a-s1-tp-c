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

void remplissage_dates(int n);
void stringify(date d, char date_str[]);
int index_of_month(char* month);
void create_events(int n, event events[]);
void display_events(int n, event events[]);
void display_event(event e);
int compare_dates(date d1, date d2);
int compare_events(event e1, event e2);
void swap_events(event events[], int index1, int index2);
void basic_sort(event events[], int n);
void insertion_sort(event events[], int n);
int partition(event events[], int a, int b);
void quick_sort(event events[], int a, int b);
