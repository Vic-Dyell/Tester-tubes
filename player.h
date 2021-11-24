#ifndef player_H
#define player_H

#include "boolean.h"
#include "listskill.h"
#include "map.h"

#define Nil NULL

#define Max_length 4

typedef int infotype;

typedef struct {
    boolean isImun;
    boolean isCerminPengganda;
    boolean isSenterPembesar; 
    boolean isSenterPengecil;
} Buff;

typedef struct tPlayer *address1;

typedef struct tPlayer {
	char playerName[50]; // nama
	Listskill skill;  // diambil dari listskill
	Buff playerBuff;  // buff yang dimiliki player 
    int position;
} Player;

typedef struct {
    Player contents [Max_length];
    int Neff;
} ArrayP;

#define Length(P) (P).Neff
#define nextSkill(S) (S)->nextSkill
#define skill(S) (S)->skill
#define BuffImunitas(P) (P).contents[i].playerBuff.isImun
#define BuffCerminPengganda(P) (P).contents[i].playerBuff.isCerminPengganda
#define BuffPembesarHoki(P) (P).contents[i].playerBuff.isSenterPembesar
#define BuffPengecilHoki(P) (P).contents[i].playerBuff.isSenterPengecil


/*** Konstruktor Player ***/
void CreateEmptyPlayer (ArrayP *P);
// I.S. Array of player P telah terdefinisi
// F.S. Sebuah Array of player dengan Neff 0 telah terbentuk

ArrayP inputPlayer (ArrayP P, int i); 
// I.S. Array of player P telah terdefinisi
// F.S. Semua Player di dalam array telah terdefinisi sebagai state awal (tanpa buff apapun, tanpa skill apapun, dan posisi 1)

void PrintSkill (Listskill S);
// I.S. List skill telah terdefinisi
// F.S. Isi dari list skill akan tercetak sesuai dengan formattingnya

void MovePlayer (ArrayP *P, int ndadu, MAP M, int i);
// I.S. Array of player, roll dadu (ndadu), map, serta orang ke-(i) telah terdefinisi
// F.s. Posisi akhir dari player ke-i setelah roll dadu bisa +ndadu atau -ndadu atau tetap

#endif