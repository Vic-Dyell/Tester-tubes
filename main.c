#include "mesin_kata.h"
#include "listskill.h"
#include "boolean.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <time.h>
#include <math.h>

int main() {
    /*Deklarasi Variable*/
    int o, k;
    char arr [100];
    char input[100] = "map.txt";
    MAP M;
    Portal Pt;
    /*ALGORITMA*/
    createEmptyMap(&M);
    STARTKATA(input);
    M.nEffM = KataToInt(CKata);
    ADVKATA();
    for (o=1; o<M.nEffM+1;o++){
        M.contents[o] = CKata.TabKata[o];
    }
    ADVKATA();
    int maksdadu;
    maksdadu = KataToInt(CKata);
    ADVKATA();
    int toto = KataToInt(CKata);
    Pt = setPortal(Pt, toto);
    for(k=0;k<Pt.Neff;k++){
        ADVKATA();
        int temp = KataToInt(CKata);
        ADVKATA();
        int nportal = KataToInt(CKata);
        Pt.contents[temp+1] = nportal;
    }
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
        boolean udahroll = false;
        boolean endturn = false;
        time_t t;
        srand((unsigned) (time(&t)));
        r = rskill(t);
        nambahskill(&P.contents[urutan].skill, r);
        while (endturn == false) {
            char cmd[10]; 
            int dadu;
            printf("Masukkan command (dengan semua huruf kapital): ");
            scanf("%s", cmd);

            // COMMAND


            if (strcmp(cmd, "ROLL")==0 && udahroll==false){
                time_t tdadu;
                srand((unsigned) (time(&tdadu)));
                dadu = roll(tdadu, maksdadu); 
                if (P.contents[urutan].playerBuff.isSenterPembesar==true){
                    if (dadu < floor(maksdadu/2)){ 
                        dadu = maksdadu - dadu;
                    }
                }
                else if (P.contents[urutan].playerBuff.isSenterPengecil==true){
                    if (dadu > floor(maksdadu/2)){
                        dadu = abs(dadu - maksdadu);
                    }
                }
                printf("Anda mendapatkan dadu bernilai : %d\n", dadu);
                udahroll = true;
                MovePlayer(&P, dadu, M, urutan, Pt);
            }
            
            else if (strcmp(cmd, "INSPECT")==0){
                ;
            }

            else if (strcmp(cmd, "MAP")==0){
                int penunjukorang;
                for (penunjukorang=1; penunjukorang<=npemain; penunjukorang++){
                    printf("%s    : ", P.contents[penunjukorang].playerName);
                    displayMap(M, P.contents[penunjukorang].position);
                }
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
                        if (lihatisi(P.contents[urutan].skill, x)==1 && P.contents[urutan].playerBuff.isImun==false){
                            P.contents[urutan].playerBuff.isImun = true; // P di sini list player
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Pintu Ga Kemana-Mana.\n");
                            buangskill(&P.contents[urutan].skill, x);
                            // efek bisa menolak teleport
                        }
                        else if (lihatisi(P.contents[urutan].skill, x)==1 && P.contents[urutan].playerBuff.isImun==true){
                            printf("Anda telah memiliki buff imunitas teleport\n");
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==2 && P.contents[urutan].playerBuff.isCerminPengganda==false){
                            P.contents[urutan].playerBuff.isCerminPengganda = true;
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Cermin Pengganda.\n");
                            buangskill(&P.contents[urutan].skill, x);
                            // efek nya mengcopy skill ke InsertLast(L)
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==2 && P.contents[urutan].playerBuff.isCerminPengganda==true){
                            printf("Anda telah memiliki buff cermin pengganda\n");
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==3 && P.contents[urutan].playerBuff.isSenterPembesar==false && P.contents[urutan].playerBuff.isSenterPengecil==false){
                            P.contents[urutan].playerBuff.isSenterPembesar = true;
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Senter Pembesar Hoki.\n");
                            buangskill(&P.contents[urutan].skill, x);
                            // efek nya ke dadu
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==3 && (P.contents[urutan].playerBuff.isSenterPembesar==true || P.contents[urutan].playerBuff.isSenterPengecil==true)){
                            if (P.contents[urutan].playerBuff.isSenterPembesar==true){
                                printf("Anda telah memiliki buff senter pembesar hoki\n");
                            }
                            else if (P.contents[urutan].playerBuff.isSenterPengecil==true){
                                printf("Anda telah memiliki buff senter pengecil hoki\n");
                            }
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==4 && P.contents[urutan].playerBuff.isSenterPembesar==false && P.contents[urutan].playerBuff.isSenterPengecil==false){
                            P.contents[urutan].playerBuff.isSenterPengecil = true;
                            printf("%s ", P.contents[urutan].playerName);
                            printf("memakai skill Senter Pengecil Hoki\n");
                            buangskill(&P.contents[urutan].skill, x);
                            P.contents[urutan].playerBuff.isSenterPengecil = true;
                            // efek nya ke dadu
                        }
                        else if (lihatisi(P.contents[urutan].skill,x)==4 && (P.contents[urutan].playerBuff.isSenterPembesar==true || P.contents[urutan].playerBuff.isSenterPengecil==true)){
                            if (P.contents[urutan].playerBuff.isSenterPembesar==true){
                                printf("Anda telah memiliki buff senter pembesar hoki\n");
                            }
                            else if (P.contents[urutan].playerBuff.isSenterPengecil==true){
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

            else if (strcmp(cmd, "ENDTURN")==0 && udahroll==true){
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