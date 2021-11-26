/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#ifndef listskill_H
#define listskill_H

#include "boolean.h"
#include <time.h>

#define Nil NULL

/* Definisi Type Data */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
	address prev;
} ElmtList;
typedef struct {
	address First;
	address Last;
} Listskill;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (Listskill L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptySkill (Listskill *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (Listskill L, infotype X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (Listskill *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (Listskill *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (Listskill *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (Listskill *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelAfter (Listskill *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (Listskill *L, address *Pdel, address Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int rskill (time_t t);
// fungsi ini digunakan untuk mendapatkan skill di setiap awal gilirannya

int NbElmt (Listskill L);
// Menghitung banyaknya anggota pada list

void DelI (Listskill *L, int n);
// Menghapus elemen ke-n pada list

void nambahskill (Listskill *L, int r);
// Menambahkan skill sesuai dengan randomize

void buangskill (Listskill *L, int x);
// Menghapus/memakai skill pada elemen ke x

void printskill (Listskill L);
// Mencetak skill apa saja yang dimiliki

int lihatisi (Listskill L, infotype X);
// Melihat isi node ke X

#endif