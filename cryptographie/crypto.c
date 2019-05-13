#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "crypto.h"

//Pour viginère
char NUMBERS[]="0123456789";
char MAJUSCULES[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char MINUSCULES[]="abcdefghijklmnopqrstuvwxyz";

// Pour enigma
char ANNEAU_1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ANNEAU_2[] = "GWQRUEYNOJAKZLSBIVCXDHFMPT";
char ANNEAU_3[] = "OAZIJLDUYMFVKRTQBEHSPGWXCN";

void shuffle(char *chaine){
    size_t n = strlen(chaine), j;
    int a; char t ;
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          j = i + rand() / (RAND_MAX / (n - i) + 1);
           t = chaine[j];
          chaine[j] = chaine[i];
          chaine[i] = t;
        }
    }
}
char dec1(char a , char b , char x,short dec){
	if(x + dec <= b)
		return x + dec;
	else 
		return  x + dec - b + a - 1;
}
char dec2(char a, char b, char x, short dec){
	if(x - dec >=a )
		return x - dec;
	else 
		return  x - dec + b - a + 1;
}

void encode_cesar(char* chaine, short decalage){
	int i = 0;
	int taille = strlen(chaine);
	for(i = 0; i < taille - 1; i++){
		if(chaine[i] > 47 && chaine[i] < 58)
			chaine[i] = dec1(48,57, chaine[i],decalage);
		if(chaine[i]  > 64 && chaine[i] < 91 )
			chaine[i] = dec1(65,90, chaine[i],decalage);
		if(chaine[i]  > 96 && chaine[i] < 123 )
			chaine[i] = dec1(97,122, chaine[i],decalage);
	}
}
void decode_cesar(char* chaine, short decalage){
	int i = 0;
	int taille = strlen(chaine);
	for(i = 0; i < taille - 1; i++){
		if(chaine[i] > 47 && chaine[i] < 58)
			chaine[i] = dec2(48,57, chaine[i],decalage);
		if(chaine[i]  > 64 && chaine[i] < 91 )
			chaine[i] = dec2(65,90, chaine[i],decalage);
		if(chaine[i]  > 96 && chaine[i] < 123 )
			chaine[i] = dec2(97,122, chaine[i],decalage);
	}
}

cle* encode_mono(char* chaine){
	 int i;
	 int taille = strlen(chaine);
	 cle *ma_cle = genere_cle();
	 for(i = 0; i < taille - 1; i++){
		if(chaine[i] > 47 && chaine[i] < 58)
			chaine[i] = ma_cle->nums[chaine[i] - 48];
		if(chaine[i]  > 64 && chaine[i] < 91 )
			chaine[i] = ma_cle->majs[chaine[i] - 65];
		if(chaine[i]  > 96 && chaine[i] < 123 )
			chaine[i] = ma_cle->mins[chaine[i] - 97];
	}
	return ma_cle;
}
void decode_mono(char* chaine, cle* ma_cle){
	int i;
	size_t taille = strlen(chaine);
	for(i = 0; i < taille - 1; i++){
		if(chaine[i] > 47 && chaine[i] < 58){
			char *ptr = strchr(ma_cle->nums, chaine[i]);
			int indice = ptr - ma_cle->nums;
			chaine[i] = NUMBERS[indice];
		}
		if(chaine[i]  > 64 && chaine[i] < 91 ){
			char *ptr = strchr(ma_cle->majs, chaine[i]);
			int indice = ptr - ma_cle->majs;
			chaine[i] = MAJUSCULES[indice];
		}
		if(chaine[i]  > 96 && chaine[i] < 123 ){
			char *ptr = strchr(ma_cle->mins, chaine[i]);
			int indice = ptr - ma_cle->mins;
			chaine[i] = MINUSCULES[indice];
		}
	}
	
}
cle* genere_cle(){;
	int i;
	 cle *ma_cle = malloc(sizeof(cle));
	 ma_cle->majs = calloc(26*sizeof(char),0);
	 ma_cle->mins = calloc(26*sizeof(char),0);
	 ma_cle->nums = calloc(10*sizeof(char),0);
	for(i = 0; i < 10; i++){
	 	ma_cle->nums[i] = NUMBERS[i];
	 }
	 // Clé des lettres majs
	 for(i = 0; i < 26; i++){
	 	ma_cle->majs[i] = MAJUSCULES[i];
	 }
	 // Clé des lettres majs
	 for(i = 0; i < 26; i++){
	 	ma_cle->mins[i] = MINUSCULES[i];
	 }

	 shuffle(ma_cle->majs);

	 shuffle(ma_cle->mins);
	 shuffle(ma_cle->nums);
	 return ma_cle;
}

char* encode_viginere(char* chaine, int k){
	size_t taille = strlen(chaine);
	//int k = 1 + rand()%(taille + 1);
	int i;
	char *ma_cle = (char*)malloc(k*sizeof(char));
	for(i = 0; i < k; i++){
		ma_cle[i] = (char)(abs(rand()%10));
	}
	for(i = 0; i < taille; i++){
		if(chaine[i] > 47 && chaine[i] < 58)
			chaine[i] = dec1(48,57, chaine[i],ma_cle[i%k]);
		if(chaine[i]  > 64 && chaine[i] < 91)
			chaine[i] = dec1(65,90, chaine[i],ma_cle[i%k]);
		if(chaine[i]  > 96 && chaine[i] < 123 )
			chaine[i] = dec1(97,122, chaine[i],ma_cle[i%k]);
	}
	return ma_cle;

}
void decode_viginere(char* chaine, char* ma_cle){
	size_t i;
	size_t k = strlen(ma_cle);
	size_t taille = strlen(chaine);
	for(i = 0; i < taille; i++){
		if(chaine[i] > 47 && chaine[i] < 58)
			chaine[i] = dec2(48,57, chaine[i],ma_cle[i%k]);
		if(chaine[i]  > 64 && chaine[i] < 91)
			chaine[i] = dec2(65,90, chaine[i],ma_cle[i%k]);
		if(chaine[i]  > 96 && chaine[i] < 123 )
			chaine[i] = dec2(97,122, chaine[i],ma_cle[i%k]);
	}
}

void encode_enigma(char* chaine, size_t nbre_anneaux_interne){
	int n = strlen(chaine),i;
	if(nbre_anneaux_interne == 1){
		for(i = 0; i< n ;i++){
			if(chaine[i]  > 64 && chaine[i] < 91)
				chaine[i] = ANNEAU_2[dec1(0,25,(chaine[i] - 65),i%26)];
		}
	}
	else if(nbre_anneaux_interne == 2){
		for(i = 0; i< n ;i++){
			if(chaine[i]  > 64 && chaine[i] < 91){
				chaine[i] = ANNEAU_3[dec1(0,25,dec1(0,25,(chaine[i] - 65),i%26), (i/26)%26)];
			}
		}
	}
}
char* decode_enigma(char* chaine, size_t nbre_anneaux_interne){
	int n = strlen(chaine),i;
	if(nbre_anneaux_interne == 1){
		for(i = 0; i< n ;i++){
			if(chaine[i]  > 64 && chaine[i] < 91){
				char *ptr = strchr(ANNEAU_2, chaine[i]);
				int indice = ptr - ANNEAU_2;
				chaine[i] = ANNEAU_1[dec2(0,25,indice,i%26)];
			}
		}
	}
	else if(nbre_anneaux_interne == 2){
		for(i = 0; i< n ;i++){
			if(chaine[i]  > 64 && chaine[i] < 91){
				char *ptr = strchr(ANNEAU_3, chaine[i]);
				int indice = ptr - ANNEAU_3;
				chaine[i] = ANNEAU_1[dec2(0,25,dec2(0,25,indice,(i/26)%26),i%26)];
			}
		}
	}
}
