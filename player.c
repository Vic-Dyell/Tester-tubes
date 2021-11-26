/* File : pemain.c */

#include "player.h"
#include <stdio.h>
#include <stdlib.h>

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
    scanf("%s", namaPlayer);
    P.contents[i].playerName[50] = namaPlayer;
    P.contents[i].playerBuff.isCerminPengganda = false;
    P.contents[i].playerBuff.isImun = false;
    P.contents[i].playerBuff.isSenterPembesar = false;
    P.contents[i].playerBuff.isSenterPengecil = false;
    P.contents[i].skill = S;
    P.contents[i].position = 1;

    return P;
}

void PrintSkill (Listskill S)
{   
    printskill(S);
}

int MovePlayer (ArrayP *P, int ndadu, MAP M, int i, Portal ptl) 
{
    int currPosition;
    int x;
    char pakaiImun;

    currPosition = P->contents[i].position;
    

    if ((currPosition + ndadu) <= M.nEffM) {
        if (M.contents[currPosition + ndadu] == "#" && (M.contents[currPosition - ndadu] == "#" || currPosition - ndadu < 0)) {
            printf("Anda tidak bisa kemana-mana");
        } 
        else if (M.contents[currPosition + ndadu] == "#" && M.contents[currPosition - ndadu] != "#" && currPosition - ndadu > 0) { // hanya bisa mundur
            printf("Anda hanya bisa melangkah mundur\n");
            currPosition = currPosition - ndadu;
            if (ptl.contents[currPosition] != -1){
                if (P->contents[i].playerBuff.isImun == true) {
                    printf("Apakah Anda ingin menggunakana buff Imunitas Teleport? (Y/N)");
                    scanf("%s", &pakaiImun);
                    if (pakaiImun == "Y") {
                        return currPosition;
                    } 
                }    
                else { //pakaiImun = N
                    currPosition = ptl.contents[currPosition];
                    return currPosition;
                }
            } 
            return currPosition;   
        }
        else if (M.contents[currPosition + ndadu] != "#" && (M.contents[currPosition - ndadu] == "#" || currPosition - ndadu < 0)){  // hanya bisa maju4
            printf("Anda hanya bisa melangkah maju\n");
            currPosition = currPosition + ndadu;
            if (ptl.contents[currPosition] != -1){
                if (P->contents[i].playerBuff.isImun == true) {
                    printf("Apakah Anda ingin menggunakana buff Imunitas Teleport? (Y/N)");
                    scanf("%s", &pakaiImun);
                    if (pakaiImun == "Y") {
                        return currPosition;
                    } 
                }    
                else { //pakaiImun = N
                    currPosition = ptl.contents[currPosition];
                    return currPosition;
                }    
            } 
            return currPosition; 
        }    
        else if (M.contents[currPosition + ndadu] != "#" && M.contents[currPosition - ndadu] != "#" && currPosition - ndadu > 0){ //bisa maju dan mundur
            printf("1. Maju\n");
            printf("2. Mundur\n");
            printf("Pilih perintah yang Anda inginkan : ");
            scanf("%d", &x);

            if (x == 1) {
                printf("Anda hanya bisa melangkah maju\n");
                currPosition = currPosition + ndadu;
                if (ptl.contents[currPosition] != -1){
                    if (P->contents[i].playerBuff.isImun == true) {
                        printf("Apakah Anda ingin menggunakana buff Imunitas Teleport? (Y/N)");
                        scanf("%s", &pakaiImun);
                        if (pakaiImun == "Y") {
                            return currPosition;
                        } 
                    }    
                    else { //pakaiImun = N
                        currPosition = ptl.contents[currPosition];
                        return currPosition;
                    }    
                } 
                return currPosition;
            } 
           
            else {
                printf("Anda hanya bisa melangkah mundur\n");
                currPosition = currPosition - ndadu;
                if (ptl.contents[currPosition] != -1){
                    if (P->contents[i].playerBuff.isImun == true) {
                        printf("Apakah Anda ingin menggunakana buff Imunitas Teleport? (Y/N)");
                        scanf("%s", &pakaiImun);
                        if (pakaiImun == "Y") {
                            return currPosition;
                        } 
                    }    
                    else { //pakaiImun = N
                        currPosition = ptl.contents[currPosition];
                        return currPosition;
                    }
                } 
                return currPosition;
            }
        } 
    } 
    else {
        printf("Kamu tidak bisa kemana-mana.");
        return currPosition; 
    }     
}    
