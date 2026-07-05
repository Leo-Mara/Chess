//Project "Chess", by Leonardo Maragni
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

/*TODO:
-TOGLI IF(1)!!!
-arrocco
-promozione pedone !!!
*/

//Bianchi: ♙♖♘♗♕♔  □ \xE2\x96\xA1
string pezziBianchi[6] = {"♙", "♖", "♘", "♗", "♕", "♔"};

//Neri: ♟♜♞♝♛♚  ■ \xE2\x96\xA0
string pezziNeri[6]    = {"♟", "♜", "♞", "♝", "♛", "♚"};

//Funzioni
void printScacchiera();
void resetGame();
int muoviPezzo(char posDaMuovere[], char posArrivo[]);
int isReachable(int x, int y);

//Strutture
struct pedone{
    string pezzo;
    int x;
    int y;
    int primaMossa=1;
    int move(int xN, int yN, string scacc[][8], int turno){

        if( turno==0 ){
        //TURNO BIANCO======================================================
            if( xN==x && yN==y ){
                printf("\nStessa posizione della partenza.\n\n");
                return -2;
            }

            //Non puoi non andare avanti
            if( yN==y ){
                printf("\nNon puoi posizionare il pedone lì.\n\n");
                return -1;
            }

            //Non può andare più indietro di dov'è
            if( y<yN ){
                printf("\nNon puoi posizionare il pedone lì.\n\n");
                return -1;
            }

            //Se si sposta di più di 1 in verticale da errore
            if( abs(yN-y)>1+primaMossa){
                if(primaMossa)
                    primaMossa=0;
                printf("\nNon puoi posizionare il pedone lì.\n\n");
                return -1;
            }

            if( xN!=x ){
                //Non posso spostarmi di più di 1 in orizzontale.
                if( abs(x-xN)>1 ){
                    printf("\nNon puoi posizionare il pedone lì.\n\n");
                    return -1;
                }
                //Non posso spostarmi in orizzontale se non c'è qualcosa da mangiare.
                if( scacc[yN][xN]=="■" || scacc[yN][xN]=="□" ){
                    printf("\nNon puoi posizionare il pedone lì.\n\n");
                    return -1;
                }
            }

            //Cambio logicamente le coordinate.
            x=xN;
            y=yN;
/*
            if( yN==0 ){
                int scelta;
                do{
                    printf("\nScegli cosa far diventare il tuo pedone tra: nulla(0) ♖(1) ♘(2) ♗(3) ♕(4).\n\n");
                    scanf("%d", &scelta);
                }while( scelta<0 || scelta>4 );

                switch( scelta ){
                    case 0:
                        printf("\nRimani un pedone.\n\n");
                        break;

                    case 1:
                        struct torre t


                        break;

                    case 2:
                        promozionePedoneCavallo(x, y);
                        break;

                    case 3:
                        promozionePedoneAlfiere(x, y);
                        break;

                    case 4:
                        promozionePedoneRegina(x, y);
                        break;

                    case default:
                        printf("\nERRORE!!!\nNon hai scelto nulla.\n\n");
                        break;
                }
            }
*///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            return 0;
        }else{
        //TURNO NERO========================================================
            if( xN==x && yN==y ){
                printf("\nStessa posizione della partenza.\n\n");
                return -2;
            }

            //Non puoi non andare avanti
            if( yN==y ){
                printf("\nNon puoi posizionare il pedone lì.\n\n");
                return -1;
            }

            //Non può andare più indietro di dov'è
            if( y>yN ){
                printf("\nNon puoi posizionare il pedone lì.\n\n");
                return -1;
            }

            //Se si sposta di più di 1 in verticale da errore
            if( abs(yN-y)>1+primaMossa){
                if(primaMossa)
                    primaMossa=0;
                printf("\nNon puoi posizionare il pedone lì.\n\n");
                return -1;
            }

            if( xN!=x ){
                //Non posso spostarmi di più di 1 in orizzontale.
                if( abs(x-xN)>1 ){
                    printf("\nNon puoi posizionare il pedone lì.\n\n");
                    return -1;
                }
                //Non posso spostarmi in orizzontale se non c'è qualcosa da mangiare.
                if( scacc[yN][xN]=="■" || scacc[yN][xN]=="□" ){
                    printf("\nNon puoi posizionare il pedone lì.\n\n");
                    return -1;
                }
            }

            //Cambio logicamente le coordinate.
            x=xN;
            y=yN;

            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

            return 0;
        }

    }

    int moveLogico(int xN, int yN, string scacc[][8], int turno){

        if( turno==0 ){
        //TURNO BIANCO======================================================
            if( xN==x && yN==y ){
                return -2;
            }

            //Non puoi non andare avanti
            if( yN==y ){
                return -1;
            }

            //Non può andare più indietro di dov'è
            if( y<yN ){
                return -1;
            }

            //Se si sposta di più di 1 in verticale da errore
            if( abs(yN-y)>1+primaMossa){
                return -1;
            }

            if( xN!=x ){
                //Non posso spostarmi di più di 1 in orizzontale.
                if( abs(x-xN)>1 ){
                    return -1;
                }
                //Non posso spostarmi in orizzontale se non c'è qualcosa da mangiare.
                if( scacc[yN][xN]=="■" || scacc[yN][xN]=="□" ){
                    return -1;
                }
            }

            return 1;
        }else{
        //TURNO NERO========================================================
            if( xN==x && yN==y ){
                return -2;
            }

            //Non puoi non andare avanti
            if( yN==y ){
                return -1;
            }

            //Non può andare più indietro di dov'è
            if( y>yN ){
                return -1;
            }

            //Se si sposta di più di 1 in verticale da errore
            if( abs(yN-y)>1+primaMossa){
                return -1;
            }

            if( xN!=x ){
                //Non posso spostarmi di più di 1 in orizzontale.
                if( abs(x-xN)>1 ){
                    return -1;
                }
                //Non posso spostarmi in orizzontale se non c'è qualcosa da mangiare.
                if( scacc[yN][xN]=="■" || scacc[yN][xN]=="□" ){
                    return -1;
                }
            }

            return 1;
        }

    }
};

struct torre{
    string pezzo;
    int x;
    int y;

    int mosso=0;

    int move(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            printf("\nStessa posizione della partenza.\n\n");
            return -2;
        }

        //Non è in linea retta x o y
        if( xN!=x && yN!=y ){
            printf("\nNon puoi posizionare la torre lì.\n\n");
            return -1;
        }

        //Trovo gli ostacoli in verticale
        if(xN==x && yN!=y ){
            if( y<yN ){
                for(int i=y+1; i<yN; i++){
                    if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }else{
                for(int i=yN+1; i<y; i++){
                    if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }
        }

        //Trovo gli ostacoli in orizzontale
        if(xN!=x && yN==y ){
            if( x<xN ){
                for(int i=x+1; i<xN; i++){
                    if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }else{
                for(int i=xN+1; i<x; i++){
                    if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }
        }

        //Mangio se trovo un pezzo dell'altro nella pos di arrivo
        if( turno ){
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziNeri[i] ){
                    printf("\nC'è un pezzo nero.\n\n");
                    return -1;
                }
            }
        }else{
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziBianchi[i] ){
                    printf("\nC'è un pezzo bianco.\n\n");
                    return -1;
                }
            }
        }

        //Cambio logicamente le coordinate.
        x=xN;
        y=yN;
        return 0;
    }

    int moveLogico(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            return -2;
        }

        //Non è in linea retta x o y
        if( xN!=x && yN!=y ){
            return -1;
        }

        //Trovo gli ostacoli in verticale
        if(xN==x && yN!=y ){
            if( y<yN ){
                for(int i=y+1; i<yN; i++){
                    if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                        return -1;
                    }
                }
            }else{
                for(int i=yN+1; i<y; i++){
                    if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                        return -1;
                    }
                }
            }
        }

        //Trovo gli ostacoli in orizzontale
        if(xN!=x && yN==y ){
            if( x<xN ){
                for(int i=x+1; i<xN; i++){
                    if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                        return -1;
                    }
                }
            }else{
                for(int i=xN+1; i<x; i++){
                    if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                        return -1;
                    }
                }
            }
        }

        //Mangio se trovo un pezzo dell'altro nella pos di arrivo
        if( turno ){
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziNeri[i] ){
                    return -1;
                }
            }
        }else{
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziBianchi[i] ){
                    return -1;
                }
            }
        }

        return 1;
    }
};

struct cavallo{
    string pezzo;
    int x;
    int y;
    int move(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            printf("\nStessa posizione della partenza.\n\n");
            return -2;
        }

        if( (abs(x-xN)==2 && abs(y-yN)==1) || (abs(x-xN)==1 && abs(y-yN)==2) ){

            //Mangio se trovo un pezzo dell'altro nella pos di arrivo
            if( turno ){
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziNeri[i] ){
                        printf("\nC'è un pezzo nero.\n\n");
                        return -1;
                    }
                }
            }else{
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziBianchi[i] ){
                        printf("\nC'è un pezzo bianco.\n\n");
                        return -1;
                    }
                }
            }

            //Cambio logicamente le coordinate
            x=xN;
            y=yN;
            return 0;
        }

        printf("\nNon puoi posizionare il cavallo lì.\n\n");
        return -1;
    }

    int moveLogico(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            return -2;
        }

        if( (abs(x-xN)==2 && abs(y-yN)==1) || (abs(x-xN)==1 && abs(y-yN)==2) ){

            //Mangio se trovo un pezzo dell'altro nella pos di arrivo
            if( turno ){
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziNeri[i] ){
                        return -1;
                    }
                }
            }else{
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziBianchi[i] ){
                        return -1;
                    }
                }
            }

            return 1;
        }

        return -1;
    }
};

struct alfiere{
    string pezzo;
    int x;
    int y;
    int move(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            printf("\nStessa posizione della partenza.\n\n");
            return -2;
        }

        //Se non si muove diagonalmente
        if( xN==x || yN==y ){
            printf("\nNon puoi posizionare l'alfiere lì.\n\n");
            return -1;
        }

        //Deve essere un triangolo rettangolo
        if( abs(x-xN) != abs(y-yN) ){
            printf("\nNon puoi posizionare l'alfiere lì.\n\n");
            return -1;
        }

        if( x<xN ){
            if( y>yN ){
                //Alto a dx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y-i][x+i]!="□" && scacc[y-i][x+i]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }else{
                //Basso a dx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y+i][x+i]!="□" && scacc[y+i][x+i]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }
        }else{
            if( y>yN ){
                //Alto a sx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y-i][x-i]!="□" && scacc[y-i][x-i]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }else{
                //Basso a sx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y+i][x-i]!="□" && scacc[y+i][x-i]!="■" ){
                        printf("\nC'è un ostacolo.\n\n");
                        return -1;
                    }
                }
            }
        }

        //Mangio se trovo un pezzo dell'altro nella pos di arrivo
        if( turno ){
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziNeri[i] ){
                    printf("\nC'è un pezzo nero.\n\n");
                    return -1;
                }
            }
        }else{
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziBianchi[i] ){
                    printf("\nC'è un pezzo bianco.\n\n");
                    return -1;
                }
            }
        }

        //Cambio logicamente le coordinate.
        x=xN;
        y=yN;
        return 0;
    }

    int moveLogico(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            return -2;
        }

        //Se non si muove diagonalmente
        if( xN==x || yN==y ){
            return -1;
        }

        //Deve essere un triangolo rettangolo
        if( abs(x-xN) != abs(y-yN) ){
            return -1;
        }

        if( x<xN ){
            if( y>yN ){
                //Alto a dx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y-i][x+i]!="□" && scacc[y-i][x+i]!="■" ){
                        return -1;
                    }
                }
            }else{
                //Basso a dx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y+i][x+i]!="□" && scacc[y+i][x+i]!="■" ){
                        return -1;
                    }
                }
            }
        }else{
            if( y>yN ){
                //Alto a sx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y-i][x-i]!="□" && scacc[y-i][x-i]!="■" ){
                        return -1;
                    }
                }
            }else{
                //Basso a sx
                for(int i=1; i<abs(xN-x); i++){
                    if( scacc[y+i][x-i]!="□" && scacc[y+i][x-i]!="■" ){
                        return -1;
                    }
                }
            }
        }

        //Mangio se trovo un pezzo dell'altro nella pos di arrivo
        if( turno ){
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziNeri[i] ){
                    return -1;
                }
            }
        }else{
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziBianchi[i] ){
                    return -1;
                }
            }
        }

        return 1;
    }
};

struct regina{
    string pezzo;
    int x;
    int y;
    int move(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            printf("\nStessa posizione della partenza.\n\n");
            return -2;
        }

        //Stessa x ma y diversa, viceversa (quindi gli assi), deve essere diagonale
        if( (xN==x && yN!=y) || (xN!=x && yN==y) || (abs(x-xN)==abs(y-yN)) ){

            //Trovo gli ostacoli in verticale
            if(xN==x && yN!=y ){
                if( y<yN ){
                    for(int i=y+1; i<yN; i++){
                        if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }else{
                    for(int i=yN+1; i<y; i++){
                        if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }
            }

            //Trovo gli ostacoli in orizzontale
            if(xN!=x && yN==y ){
                if( x<xN ){
                    for(int i=x+1; i<xN; i++){
                        if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }else{
                    for(int i=xN+1; i<x; i++){
                        if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }
            }

            if( x<xN ){
                if( y>yN ){
                    //Alto a dx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y-i][x+i]!="□" && scacc[y-i][x+i]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }else{
                    //Basso a dx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y+i][x+i]!="□" && scacc[y+i][x+i]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }
            }else{
                if( y>yN ){
                    //Alto a sx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y-i][x-i]!="□" && scacc[y-i][x-i]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }else{
                    //Basso a sx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y+i][x-i]!="□" && scacc[y+i][x-i]!="■" ){
                            printf("\nC'è un ostacolo.\n\n");
                            return -1;
                        }
                    }
                }
            }

            //Mangio se trovo un pezzo dell'altro nella pos di arrivo
            if( turno ){
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziNeri[i] ){
                        printf("\nC'è un pezzo nero.\n\n");
                        return -1;
                    }
                }
            }else{
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziBianchi[i] ){
                        printf("\nC'è un pezzo bianco.\n\n");
                        return -1;
                    }
                }
            }

            //Cambio logicamente le coordinate.
            x=xN;
            y=yN;
            return 0;
        }

        printf("\nNon puoi posizionare la regina lì.\n\n");
        return -1;
    }

    int moveLogico(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            return -2;
        }

        //Stessa x ma y diversa, viceversa (quindi gli assi), deve essere diagonale
        if( (xN==x && yN!=y) || (xN!=x && yN==y) || (abs(x-xN)==abs(y-yN)) ){

            //Trovo gli ostacoli in verticale
            if(xN==x && yN!=y ){
                if( y<yN ){
                    for(int i=y+1; i<yN; i++){
                        if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                            return -1;
                        }
                    }
                }else{
                    for(int i=yN+1; i<y; i++){
                        if( scacc[i][xN]!="□" && scacc[i][xN]!="■" ){
                            return -1;
                        }
                    }
                }
            }

            //Trovo gli ostacoli in orizzontale
            if(xN!=x && yN==y ){
                if( x<xN ){
                    for(int i=x+1; i<xN; i++){
                        if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                            return -1;
                        }
                    }
                }else{
                    for(int i=xN+1; i<x; i++){
                        if( scacc[yN][i]!="□" && scacc[yN][i]!="■" ){
                            return -1;
                        }
                    }
                }
            }

            if( x<xN ){
                if( y>yN ){
                    //Alto a dx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y-i][x+i]!="□" && scacc[y-i][x+i]!="■" ){
                            return -1;
                        }
                    }
                }else{
                    //Basso a dx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y+i][x+i]!="□" && scacc[y+i][x+i]!="■" ){
                            return -1;
                        }
                    }
                }
            }else{
                if( y>yN ){
                    //Alto a sx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y-i][x-i]!="□" && scacc[y-i][x-i]!="■" ){
                            return -1;
                        }
                    }
                }else{
                    //Basso a sx
                    for(int i=1; i<abs(xN-x); i++){
                        if( scacc[y+i][x-i]!="□" && scacc[y+i][x-i]!="■" ){
                            return -1;
                        }
                    }
                }
            }

            //Mangio se trovo un pezzo dell'altro nella pos di arrivo
            if( turno ){
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziNeri[i] ){
                        return -1;
                    }
                }
            }else{
                for(int i=0; i<6; i++){
                    //Se trovo un pezzo alleato non faccio nulla
                    if( scacc[yN][xN]==pezziBianchi[i] ){
                        return -1;
                    }
                }
            }

            return 1;
        }

        return -1;
    }
};

struct re{
    string pezzo;
    int x;
    int y;

    int mosso=0;
    int scacco=0;
    int matto=0;

    int move(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            printf("\nStessa posizione della partenza.\n\n");
            return -2;
        }

        if( scacco ){
            if( isReachable(xN, yN)==0 ){
                printf("\nIl tuo re è sotto scacco, non puoi metterlo qui.\n\n");
                return -1;
            }
        }

        //Se è più lontano di 1 passo è sbagliato
        if( abs(x-xN)>1 || abs(y-yN)>1 ){
            printf("\nNon puoi posizionare il re lì.\n\n");
            return -1;
        }

        //Mangio se trovo un pezzo dell'altro nella pos di arrivo
        if( turno ){
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziNeri[i] ){
                    printf("\nC'è un pezzo nero.\n\n");
                    return -1;
                }
            }
        }else{
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziBianchi[i] ){
                    printf("\nC'è un pezzo bianco.\n\n");
                    return -1;
                }
            }
        }

        //Cambio logicamente le coordinate.
        x=xN;
        y=yN;

        return 0;
    }

    int moveLogico(int xN, int yN, string scacc[][8], int turno){
        if( xN==x && yN==y ){
            return -2;
        }

        //Se è più lontano di 1 passo è sbagliato
        if( abs(x-xN)>1 || abs(y-yN)>1 ){
            return -1;
        }

        //Mangio se trovo un pezzo dell'altro nella pos di arrivo
        if( turno ){
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziNeri[i] ){
                    return -1;
                }
            }
        }else{
            for(int i=0; i<6; i++){
                //Se trovo un pezzo alleato non faccio nulla
                if( scacc[yN][xN]==pezziBianchi[i] ){
                    return -1;
                }
            }
        }

        return 1;
    }
};

struct scacchiera{

    int turno=0; //0=bianco, 1=nero

//Pezzi bianchi
    struct pedone Pb1, Pb2, Pb3, Pb4, Pb5, Pb6, Pb7, Pb8; //Pedoni bianchi
    struct torre Tb1, Tb2; //Torri bianche
    struct cavallo Cb1, Cb2; //Cavalli bianchi
    struct alfiere Ab1, Ab2; //Alfieri bianchi
    struct regina Qb; //Regina bianca
    struct re Kb; //Re bianco

//Pezzi neri
    struct pedone Pn1, Pn2, Pn3, Pn4, Pn5, Pn6, Pn7, Pn8; //Pedoni neri
    struct torre Tn1, Tn2; //Torri nere
    struct cavallo Cn1, Cn2; //Cavalli neri
    struct alfiere An1, An2; //Alfieri neri
    struct regina Qn; //Regine nera
    struct re Kn; //Re nero

    string scacc[8][8]={
        {"□", "■", "□", "■", "□", "■", "□", "■"},
        {"■", "□", "■", "□", "■", "□", "■", "□"},
        {"□", "■", "□", "■", "□", "■", "□", "■"},
        {"■", "□", "■", "□", "■", "□", "■", "□"},
        {"□", "■", "□", "■", "□", "■", "□", "■"},
        {"■", "□", "■", "□", "■", "□", "■", "□"},
        {"□", "■", "□", "■", "□", "■", "□", "■"},
        {"■", "□", "■", "□", "■", "□", "■", "□"}
    };

    void move(int x, int y){
        if( (y+x)%2==0){
                scacc[y][x]="□";
            }else{
                scacc[y][x]="■";
            }
    }
};

struct scacchiera s;

int main(){

    SetConsoleOutputCP(CP_UTF8);

//Inizializzazione coordinate di ogni pezzo.
if(1){
//Pedoni
    s.Pb1.x=0, s.Pb2.x=1, s.Pb3.x=2, s.Pb4.x=3, s.Pb5.x=4, s.Pb6.x=5, s.Pb7.x=6, s.Pb8.x=7;
    s.Pb1.y=6, s.Pb2.y=6, s.Pb3.y=6, s.Pb4.y=6, s.Pb5.y=6, s.Pb6.y=6, s.Pb7.y=6, s.Pb8.y=6;

    s.Pn1.x=0, s.Pn2.x=1, s.Pn3.x=2, s.Pn4.x=3, s.Pn5.x=4, s.Pn6.x=5, s.Pn7.x=6, s.Pn8.x=7;
    s.Pn1.y=1, s.Pn2.y=1, s.Pn3.y=1, s.Pn4.y=1, s.Pn5.y=1, s.Pn6.y=1, s.Pn7.y=1, s.Pn8.y=1;

    s.Pb1.pezzo="♙", s.Pb2.pezzo="♙", s.Pb3.pezzo="♙", s.Pb4.pezzo="♙", s.Pb5.pezzo="♙", s.Pb6.pezzo="♙", s.Pb7.pezzo="♙", s.Pb8.pezzo="♙";
    s.Pn1.pezzo="♟", s.Pn2.pezzo="♟", s.Pn3.pezzo="♟", s.Pn4.pezzo="♟", s.Pn5.pezzo="♟", s.Pn6.pezzo="♟", s.Pn7.pezzo="♟", s.Pn8.pezzo="♟";

//Torri
    s.Tb1.x=0, s.Tb2.x=7;
    s.Tb1.y=7, s.Tb2.y=7;

    s.Tn1.x=0, s.Tn2.x=7;
    s.Tn1.y=0, s.Tn2.y=0;

    s.Tb1.pezzo="♖", s.Tb2.pezzo="♖";
    s.Tn1.pezzo="♜", s.Tn2.pezzo="♜";

//Cavalli
    s.Cb1.x=1, s.Cb2.x=6;
    s.Cb1.y=7, s.Cb2.y=7;

    s.Cn1.x=1, s.Cn2.x=6;
    s.Cn1.y=0, s.Cn2.y=0;

    s.Cb1.pezzo="♘", s.Cb2.pezzo="♘";
    s.Cn1.pezzo="♞", s.Cn2.pezzo="♞";

//Alfieri
    s.Ab1.x=2, s.Ab2.x=5;
    s.Ab1.y=7, s.Ab2.y=7;

    s.An1.x=2, s.An2.x=5;
    s.An1.y=0, s.An1.y=0;

    s.Ab1.pezzo="♗", s.Ab2.pezzo="♗";
    s.An1.pezzo="♝", s.An2.pezzo="♝";

//Regine e Re
    s.Qb.x=3, s.Qn.x=3;
    s.Kb.x=4, s.Kn.x=4;

    s.Kb.y=7, s.Qb.y=7;
    s.Kn.y=0, s.Qn.y=0;

    s.Qb.pezzo="♕";
    s.Qn.pezzo="♛";
    s.Kb.pezzo="♔";
    s.Kn.pezzo="♚";
}

//============================================================================================

    resetGame();
    printf("Per selezionare una casella mettere in input la lettera (maiuscola) e il numero. (Es. A4, C2)\nAltri formati non saranno ammessi.\n");
    printScacchiera();

    char daMuovere[3], arrivo[3];
    int risposta, vuota=0, nTurni=1, cont=0;

    while(1){
        // Stampo di chi è il turno
        printf("Il turno %d e' del ", nTurni);
        if( s.turno )
            printf("NERO.\n\n");
        else
            printf("BIANCO.\n\n");

        do{

            do{
                cout<<"Che pezzo vuoi muovere? ";
                scanf("%2s", daMuovere);

                vuota=0;

                if( daMuovere[0]>='a' && daMuovere[0]<='h' )
                    daMuovere[0]-=32;

                if( s.scacc[daMuovere[1]-'1'][daMuovere[0]-'A']=="□"  || s.scacc[daMuovere[1]-'1'][daMuovere[0]-'A']=="■" ){
                    printf("\nNella cella selezionata non è presente nessun pezzo.\n\n");
                    vuota=1;
                }
            }while( (daMuovere[0]<'A' || daMuovere[0]>'H') || (daMuovere[1]<'1' || daMuovere[1]>'8') || vuota );


            do{
                cout<<"Dove lo vuoi spostare? ";
                scanf("%2s", arrivo);
                if( arrivo[0]>='a' && arrivo[0]<='h' )
                    arrivo[0]-=32;

            }while( (arrivo[0]<'A' || arrivo[0]>'H') || (arrivo[1]<'1' || arrivo[1]>'8') );

            risposta = muoviPezzo(daMuovere, arrivo);

            s.Kn.scacco=isReachable(s.Kn.x, s.Kn.y);
            s.Kb.scacco=isReachable(s.Kb.x, s.Kb.y);

            if( s.Kb.scacco )
                printf("\nIl re bianco è sotto scacco!!\n\n");

            if( s.Kn.scacco )
                printf("\nIl re nero è sotto scacco!!\n\n");

        }while( risposta!=0 );

        if( s.Kb.scacco ){
            cont=0;
            // Calcolo lo scacco matto bianco
            for(int i=s.Kb.y-1; i<=s.Kb.y+1; i++){
                for(int j=s.Kb.x-1; j<=s.Kb.x+1; j++){
                    if( ( i<0 || i>7 ) || ( j<0 || j>7 ) ){
                        cont++;
                        continue;
                    }
                    if( s.scacc[i][j]!="□" && s.scacc[i][j]!="■" ){
                        cont++;
                        continue;
                    }
                    cont+=isReachable(j, i);
                }
            }
            if( cont==9 )
                s.Kb.matto=1;
        }

        if( s.Kn.scacco ){
            cont=0;
            // Calcolo lo scacco matto nero
            for(int i=s.Kn.y-1; i<=s.Kn.y+1; i++){
                for(int j=s.Kn.x-1; j<=s.Kn.x+1; j++){
                    if( ( i<0 || i>7 ) || ( j<0 || j>7 ) ){
                        cont++;
                        continue;
                    }
                    if( s.scacc[i][j]!="□" && s.scacc[i][j]!="■" ){
                        cont++;
                        continue;
                    }
                    cont+=isReachable(j, i);
                }
            }
            if( cont==9 )
                s.Kn.matto=1;
        }

        // Sposto graficamente il pezzo.
        s.scacc[arrivo[1]-'1'][arrivo[0]-'A'] = s.scacc[daMuovere[1]-'1'][daMuovere[0]-'A'];

        // Casella vuota nella posizione precedente.
        s.move(daMuovere[0]-'A', daMuovere[1]-'1');

        printScacchiera();

        if( s.Kb.matto ){
            printf("Scacco matto sul bianco.\n\nVince il NERO.\n");
            return 0;
        }

        if( s.Kn.matto ){
            printf("Scacco matto sul nero.\n\nVince il BIANCO.\n");
            return 0;
        }

        s.turno=1-s.turno;
        nTurni++;
    }

//============================================================================================

    return 0;
}

void printScacchiera(){
    printf("\n   A B C D E F G H\n");
    printf("   ---------------\n");
    for(int i=0; i<8; i++){
        cout<<i+1<<"| ";
        for(int j=0; j<8; j++){
            cout<<s.scacc[i][j]<<" ";
        }
        printf("\n");
    }
    printf("\n");
}

void resetGame(){
    int f=1;
    for(int i=0; i<8; i++){
        f=1-f;
        for(int j=0; j<8; j++){
            if( (j+f)%2==0){
                s.scacc[i][j]="□";
            }else{
                s.scacc[i][j]="■";
            }
        }
    }
    for(int i=0; i<8; i++){
        s.scacc[1][i]="♟";
        s.scacc[6][i]="♙";
    }
    for(int i=0; i<8; i=i+7){
        s.scacc[0][i]="♜";
        s.scacc[7][i]="♖";
    }
    for(int i=1; i<8; i=i+5){
        s.scacc[0][i]="♞";
        s.scacc[7][i]="♘";
    }
    for(int i=2; i<8; i=i+3){
        s.scacc[0][i]="♝";
        s.scacc[7][i]="♗";
    }
    s.scacc[0][3]="♛";
    s.scacc[7][3]="♕";
    s.scacc[0][4]="♚";
    s.scacc[7][4]="♔";
}

int muoviPezzo(char posDaMuovere[], char posArrivo[]){
    //Converto la stringa in variabili usabili come coordinate nella matrice.
    int y=posDaMuovere[1]-'1';
    int x=posDaMuovere[0]-'A';
    int yN=posArrivo[1]-'1';
    int xN=posArrivo[0]-'A';

    //Variabile che tiene i responso della funzione move.
    int risposta;



        //Controllo le coordinate per capire quale pezzo voglio muovere, e poi lo muovo.
        if(s.turno){
            if( s.Pn1.x==x && s.Pn1.y==y ){
                risposta=s.Pn1.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pn2.x==x && s.Pn2.y==y ){
                risposta=s.Pn2.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pn3.x==x && s.Pn3.y==y ){
                risposta=s.Pn3.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pn4.x==x && s.Pn4.y==y ){
                risposta=s.Pn4.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pn5.x==x && s.Pn5.y==y ){
                risposta=s.Pn5.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pn6.x==x && s.Pn6.y==y ){
                risposta=s.Pn6.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pn7.x==x && s.Pn7.y==y ){
                risposta=s.Pn7.move(xN, yN, s.scacc, s.turno);

            }else if( s.Cn1.x==x && s.Cn1.y==y ){
                risposta=s.Cn1.move(xN, yN, s.scacc, s.turno);

            }else if( s.Cn2.x==x && s.Cn2.y==y ){
                risposta=s.Cn2.move(xN, yN, s.scacc, s.turno);

            }else if( s.Tn1.x==x && s.Tn1.y==y ){
                risposta=s.Tn1.move(xN, yN, s.scacc, s.turno);

            }else if( s.Tn2.x==x && s.Tn2.y==y ){
                risposta=s.Tn2.move(xN, yN, s.scacc, s.turno);

            }else if( s.An1.x==x && s.An1.y==y ){
                risposta=s.An1.move(xN, yN, s.scacc, s.turno);

            }else if( s.An2.x==x && s.An2.y==y ){
                risposta=s.An2.move(xN, yN, s.scacc, s.turno);

            }else if( s.Qn.x==x && s.Qn.y==y ){
                risposta=s.Qn.move(xN, yN, s.scacc, s.turno);

            }else if( s.Kn.x==x && s.Kn.y==y ){
                risposta=s.Kn.move(xN, yN, s.scacc, s.turno);

            }else{
                printf("\nNon hai selezionato nulla.\n\n");
                return -1;
            }
        }else{
            if( s.Pb1.x==x && s.Pb1.y==y ){
                risposta=s.Pb1.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pb2.x==x && s.Pb2.y==y ){
                risposta=s.Pb2.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pb3.x==x && s.Pb3.y==y ){
                risposta=s.Pb3.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pb4.x==x && s.Pb4.y==y ){
               risposta= s.Pb4.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pb5.x==x && s.Pb5.y==y ){
                risposta=s.Pb5.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pb6.x==x && s.Pb6.y==y ){
                risposta=s.Pb6.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pb7.x==x && s.Pb7.y==y ){
                risposta=s.Pb7.move(xN, yN, s.scacc, s.turno);

            }else if( s.Pb8.x==x && s.Pb8.y==y ){
                risposta=s.Pb8.move(xN, yN, s.scacc, s.turno);

            }else if( s.Cb1.x==x && s.Cb1.y==y ){
                risposta=s.Cb1.move(xN, yN, s.scacc, s.turno);

            }else if( s.Cb2.x==x && s.Cb2.y==y ){
                risposta=s.Cb2.move(xN, yN, s.scacc, s.turno);

            }else if( s.Tb1.x==x && s.Tb1.y==y ){
                risposta=s.Tb1.move(xN, yN, s.scacc, s.turno);

            }else if( s.Tb2.x==x && s.Tb2.y==y ){
                risposta=s.Tb2.move(xN, yN, s.scacc, s.turno);

            }else if( s.Ab1.x==x && s.Ab1.y==y ){
                risposta=s.Ab1.move(xN, yN, s.scacc, s.turno);

            }else if( s.Ab2.x==x && s.Ab2.y==y ){
                risposta=s.Ab2.move(xN, yN, s.scacc, s.turno);

            }else if( s.Qb.x==x && s.Qb.y==y ){
                risposta=s.Qb.move(xN, yN, s.scacc, s.turno);

            }else if( s.Kb.x==x && s.Kb.y==y ){
                risposta=s.Kb.move(xN, yN, s.scacc, s.turno);

            }else{
                printf("\nNon hai selezionato nulla.\n\n");
                return -1;
            }
        }

    return risposta;
}

int isReachable(int x, int y){
    if( s.turno ){
        //Pedoni
        if( s.Pn1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pn2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pn3.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pn4.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pn5.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pn6.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pn7.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pn8.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;


        //Torri
        if( s.Tn1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Tn2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        //Alfieri
        if( s.An1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.An2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        //Cavalli
        if( s.Cn1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Cn2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        //Regina
        if( s.Qn.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        //Re
        if( s.Kn.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

    }else{
        //Pedoni
        if( s.Pb1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pb2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pb3.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pb4.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pb5.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pb6.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pb7.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Pb8.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;


        //Torri
        if( s.Tb1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Tb2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        //Alfieri
        if( s.Ab1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Ab2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;


        //Cavalli
        if( s.Cb1.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        if( s.Cb2.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;


        //Regina
        if( s.Qb.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;

        //Re
        if( s.Kb.moveLogico(x, y, s.scacc, s.turno)==1 )
            return 1;
    }

    return 0;
}
