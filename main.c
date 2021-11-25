#include "mesin_kata.h"
#include "listskill.h"
#include "boolean.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <time.h>

int main() {
    int npemain;
    int i;
    // Player P;

    printf("SELAMAT DATANG DIPERMAINAN MOBITANGGA\n");
    printf("Silahkan masukkan jumlah pemain: ");
    scanf("%d", &npemain);

    // MSUKIN KE LIST OF PLAYER
    ArrayP P;
    CreateEmptyPlayer(&P);
    P.Neff = npemain;
    for(i=1;i<=npemain;i++){
        P = inputPlayer(P, i);
    }
    printf("MULAI\n");
    // MENU
    boolean endgame;
    endgame = false;
    int urutan = 1;
    while (endgame == false){
        int r;
        boolean endturn = false;
        time_t t;
        srand((unsigned) (time(&t)));
        r = rskill(t);
        nambahskill(&P.contents[urutan].skill, r);
        while (endturn == false) {
            char cmd[10];
            printf("Masukkan command (dengan semua huruf kapital): ");
            scanf("%s", cmd);
            if (strcmp(cmd, "ROLL")==0){
                ;
            }
            else if (strcmp(cmd, "INSPECT")==0){
                ;
            }
            else if (strcmp(cmd, "MAP")==0){
                ;
            }
            else if (strcmp(cmd, "UNDO")==0){
                ;
            }
            else if (strcmp(cmd, "SKILL")==0){
                int x; 
                int tukar;
                printskill(P.contents[urutan].skill); // L di sini listskill per player
                if(!IsEmpty(P.contents[urutan].skill)){
                    printf("Masukkan skill: ");
                    scanf("%d", &x);
                    if (x<0){
                        buangskill(&P.contents[urutan].skill, x);
                        printf("Skill Anda telah berhasil dibuang\n");
                    }
                    else if (x>0){ // pakai skill
                        if (lihatisi(P.contents[urutan].skill, x)==1 && BuffImunitas(P)==false){
                            BuffImunitas(P) = true; // P di sini list player
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Pintu Ga Kemana-Mana.\n");
                            buangskill(&P.contents[urutan].skill, x);
                            // efek bisa menolak teleport
                        }
                        else if (lihatisi(P.contents[urutan].skill, x)==1 && BuffImunitas(P)==true){
                            printf("Anda telah memiliki buff imunitas teleport\n");
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==2 && BuffCerminPengganda(P)==false){
                            BuffCerminPengganda(P) = true;
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Cermin Pengganda.\n");
                            buangskill(&P.contents[urutan].skill, x);
                            // efek nya mengcopy skill ke InsertLast(L)
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==2 && BuffCerminPengganda(P)==true){
                            printf("Anda telah memiliki buff cermin pengganda\n");
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==3 && BuffPembesarHoki(P)==false && BuffPengecilHoki(P)==false){
                            BuffPembesarHoki(P) = true;
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Senter Pembesar Hoki.\n");
                            buangskill(&P.contents[urutan].skill, x);
                            // efek nya ke dadu
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==3 && (BuffPembesarHoki(P)==true || BuffPengecilHoki(P)==true)){
                            if (BuffPembesarHoki(P)==true){
                                printf("Anda telah memiliki buff senter pembesar hoki\n");
                            }
                            else if (BuffPengecilHoki(P)==true){
                                printf("Anda telah memiliki buff senter pengecil hoki\n");
                            }
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==4 && BuffPembesarHoki(P)==false && BuffPengecilHoki(P)==false){
                            BuffPengecilHoki(P) = true;
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Senter Pengecil Hoki\n");
                            buangskill(&P.contents[urutan].skill, x);
                            BuffPengecilHoki(P) = true;
                            // efek nya ke dadu
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==4 && (BuffPembesarHoki(P)==true || BuffPengecilHoki(P)==true)){
                            if (BuffPembesarHoki(P)==true){
                                printf("Anda telah memiliki buff senter pembesar hoki\n");
                            }
                            else if (BuffPengecilHoki(P)==true){
                                printf("Anda telah memiliki buff senter pengecil hoki\n");
                            }
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==5){
                            printf("memakai skill Penukar Posisi\n");
                            buangskill(&P.contents[urutan].skill, x);
                            // buat fungsi print nama ada siapa aja
                            printf("%d Masukkan nomor berapa yang ingin Anda tukar :", &tukar);
                            // buat fungsi penukar posisi yaitu dengan menukar nama dari list player
                        }
                        // kalo 0 langsung skip
                    }
                }
            } 
            else if (strcmp(cmd, "ENDTURN")==0){
                endturn = true;
                urutan = urutan + 1;
                if (urutan>npemain){ // SUDAH HABIS 1 RONDE
                    urutan = (urutan % npemain);
                }
            } 
            else{
                printf("Masukkan command yang sesuai!\n");
            }
        }
    } printf("SELESAI");
}