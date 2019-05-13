#ifndef H_CRYP
#define H_CRYP
void encode_cesar(char* chaine, short decalage);
void decode_cesair(char* chaine, short decalage);

typedef struct cle{
	char* majs;
	char* mins;
	char* nums;
} cle;

cle* encode_mono(char* chaine);
void decode_mono(char* chaine, cle* cle_chiffre);
// char* encode_viginere(char* chaine);
char* encode_viginere(char* chaine, int k);
void decode_viginere(char* chaine, char* ma_cle);
void encode_enigma(char* chaine, size_t nbre_anneaux);
char* decode_enigma(char* chaine, size_t nbre_anneaux_interne);
short is_in(char c, char* chars, size_t taille);
cle* genere_cle();
void shuffle(char* chaine);
#endif