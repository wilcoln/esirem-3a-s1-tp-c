#include <stdio.h>
#include <time.h>
#include "events.h"

#define N 10

const iterations_nb = 10;

int main(){
	remplissage_dates(N);
	event events[N];
	create_events(N,events);
	display_events(N,events);

	quick_sort(events,0, N-1);
	printf(" On tri le tableau par tri rapide\n");
	display_events(N,events);
	
}
