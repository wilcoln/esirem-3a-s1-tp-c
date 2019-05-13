#include <stdio.h>
#include <string.h>
#include "crypto.h"
int main(){
	char chaine[] = "BAC BAC BAC BAC BAC BAC WILFRIED WILCOLN BAC BAC BON BON BON BOUNSI DJATCHEU I HAVE NO BODY TO CALL MY OWN";
	//char chaine[] = "Hello World 1 2 3 5! Mon nom est wilfried et vous ferez ce que je dis";
	char chaine2[] = "Hello World 1 2 3 5!";
	//Codage de césar
	//printf("Entrez un phrase\n");
	//scanf("%s", chaine);
	srand(time(NULL));
	encode_cesar(chaine, 3);
	printf("=> encode cesar : %s\n", chaine);

	//Decodage de césar
	decode_cesar(chaine, 3);
	printf("=> decode cesar : %s\n", chaine);

	//Codage mono
	cle* ma_cle1 = encode_mono(chaine);
	printf("=> codage mono : %s\n", chaine);

	//Decodage de césar
	decode_mono(chaine, ma_cle1);
	printf("=> decode mono : %s\n", chaine);

	char* ma_cle = encode_viginere(chaine2, 4);
	printf("=> encode viginere : %ld %s \n", strlen(chaine2),chaine2);
	
	decode_viginere(chaine2, ma_cle);
	printf("=> decode viginere : %s\n", chaine2);

	//Codage enigma
	encode_enigma(chaine, 2);
	printf("=> encode enigma : %s \n",chaine);
	//Décodage enignma
	decode_enigma(chaine, 2);
	printf("=> decode enigma : %s \n",chaine);
}
