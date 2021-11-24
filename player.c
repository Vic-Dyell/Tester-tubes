/* File : pemain.c */

#include "player.h"
#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

/*** Konstruktor Player ***/
void CreateEmptyPlayer (ArrayP *P)
{
    /* ALGORITMA */
    (*P).Neff = Nil;
}

ArrayP inputPlayer (ArrayP P, int i) 
{
    Listskill S;
    CreateEmptySkill(&S);
    char namaPlayer[50];
    printf("Masukkan nama: ");
    scanf("%s", &namaPlayer);
    P.contents[i].playerName[50] = namaPlayer;
    BuffCerminPengganda(P) = false;
    BuffImunitas(P) = false;
    BuffPembesarHoki(P) = false;
    BuffPengecilHoki(P) = false;
    P.contents[i].skill = S;
    P.contents[i].position = 1;

    return P;
}

void PrintSkill (Listskill S)
{   
    printskill(S);
}

void MovePlayer (ArrayP *P, int ndadu, MAP M, int i) 
{
    int currPosition;
    int x;

    currPosition = (*P).contents[i].position;
    

    if (((currPosition + ndadu) <= M.nEffM) && ((currPosition - ndadu) > 0)) {
        if (M.contents[currPosition + ndadu] == "#") {
            if (M.contents[currPosition - ndadu] == "#") {
                
                printf("1. Maju");
                printf("2. Mundur");
                printf("Pilih perintah yang kamu inginkan : ");
                scanf("%d", &x);

                if (x == 1) {
                    currPosition = currPosition + ndadu;
                    M.contents[currPosition] = "*";
                } else {
                    currPosition = currPosition - ndadu;
                    M.contents[currPosition] = "*";
                }
            } else {
                currPosition = currPosition + ndadu;
                M.contents[currPosition] = "*";
            }
        } else {
            if (M.contents[currPosition - ndadu] == "#") {
                printf("Kamu tidak bisa kemana-mana.");

            } else {
                currPosition = currPosition - ndadu;
                M.contents[currPosition] = "*";
            } 
        }
        
    } else {
        printf("Kamu tidak bisa kemana-mana.");
    }
    return currPosition; 
}