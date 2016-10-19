#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define joueur1 0
#define joueur2 1
#define CORVETTE 1
#define DESTROYER 3
#define CROISEUR 4
#define PORTEAVION 6
#define MAP_H 18
#define MAP_W 24



void Color(int couleurDuTexte,int couleurDeFond){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void affichemap(int map[18][24][2],int joueur){
    int i=0;
    int j=0;

    for (i=0;i<18;i++){
        for(j=0;j<24;j++){
            if (map[i][j][joueur] == 0){
                Color(9,9);
            }
                printf("%2d",map[i][j][joueur]);
                Color(7,0);
        }
    printf("\n");
    }

}

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

void placementbateaux(int map[18][24][2], int joueur,int taillebateau){
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    int t = 0;

    t = doRand (0,1);
    x = doRand(0,17-taillebateau);
    y = doRand(0,23-taillebateau);

     if (t== 0){for (i=0;i<taillebateau;i++){
                if(map[x+i][y][joueur]==0 && map[x+i][y][joueur]<18 && map[x+i][y][joueur]>=0){
                map[x+i][y][joueur]=taillebateau;
                }
            }
        }
     if (t== 1){
        for (j=0;j<taillebateau;j++){
                if(map[x][y+j][joueur]==0 && map[x][y+j][joueur]<18 && map[x][y+j][joueur]>=0){
                map[x][y+j][joueur]=taillebateau;
                }
            }
        }
}
void placementbateauxjoueur(int map[18][24][2], int joueur,int taillebateau, int x, int y){

    int i = 0;
    int saisi;

     for (i=0;i<taillebateau;i++){
         if (map[x+i][y][joueur]==0 && map[x+i][y][joueur]<18 && map[x+i][y][joueur]>=0){
         map[x+i][y][joueur]=taillebateau;
            }
        }
}

void conditionposition(){


}
void iaVsia (){

    int map[18][24][2]={0};

    Color(7,0);
    printf("\n");
    placementbateaux(map,joueur1,CORVETTE);
    placementbateaux(map,joueur1,DESTROYER);
    placementbateaux(map,joueur1,DESTROYER);
    placementbateaux(map,joueur1,CROISEUR);
    placementbateaux(map,joueur1,CROISEUR);
    placementbateaux(map,joueur1,PORTEAVION);
    printf("\n");
    printf("MAP JOUEUR 1\n");
    placementbateaux(map,joueur2,CORVETTE);
    placementbateaux(map,joueur2,DESTROYER);
    placementbateaux(map,joueur2,DESTROYER);
    placementbateaux(map,joueur2,CROISEUR);
    placementbateaux(map,joueur2,CROISEUR);
    placementbateaux(map,joueur2,PORTEAVION);
    affichemap(map,joueur1);
    printf("\n");
    printf("MAP JOUEUR 2\n");
    affichemap(map,joueur2);
}

void positionbateau (int identifiant){
    int bateau = 6;
    int x,y;
    int position;
    int map[18][24][2];
    int joueur, taillebateau;

    do {
        printf (" 1: CORVETTE ");
        printf (" 2: DESTROYER ");
        printf (" 3: CROISEUR ");
        printf (" 4: PORTE-AVIONS\n");
        printf ("\n");
        printf ("Choisir le bateau a placer \n");
        scanf ("%d", &identifiant);
        fflush (stdin);
        printf ("\n");
            while(1>identifiant || identifiant>5){
                printf ("saisir un chiffre valable\n");
                scanf ("%d", &identifiant);
                fflush (stdin);
            }
            printf ("saisir X \n");
            scanf("%d", &x);

            while (0>x ||x>25){
                printf ("saisir un chiffre valable \n");
                scanf ("%d", &x);
                fflush (stdin);
            }
            printf ("\n");
            placementbateauxjoueur( map[18][24][2], joueur, taillebateau, x, y);
            affichemap( map[18][24][2],joueur);


            printf ("entrez ca position en Y \n");
            scanf ("%d", &y);
            while (0>y || y>18){
                printf ("saisir un chiffre valable \n");
                scanf ("%d", &y);
                fflush (stdin);
            }

            printf ("\n");
            placementbateauxjoueur( map[18][24][2], joueur, taillebateau, x, y);
            affichemap( map[18][24][2],joueur);

            printf ("pour les placer horizontalement tape 0, pour le placer verticalement tape 1 \n");
            scanf ("%d", &position);
            while (position>1 || position<0){
            printf ("saisir un chiffre valide \n");
            scanf ("%d", &position);
            fflush (stdin);}
            printf ("\n");
            placementbateauxjoueur( map[18][24][2], joueur, taillebateau, x, y);
            affichemap( map[18][24][2],joueur);

            bateau --;

        } while (bateau != 0);
    }

void joueurVSia (){
    int x,y, position,i,j;
    int identifiant;
    int bateau = 6;
    int player;
    int item;
    int corvette = 1;
    int croiseur = 2;
    int porte_avion = 2;
    int destroyer = 1;
    int map[18][24][2];
    int joueur;
    int taillebateau;

    affichemap(map[18][24][2], joueur);

    /* printf ("\n");
     printf ("Vous disposez de:\n %d corvette de taille 1 \n %d destroyer de taille 3\n %d croiseur de taille 4\n %d porte-avion de taille 6 \nVous pouvez les placer horizontalement ou verticalement \n", corvette, destroyer, porte_avion, croiseur);
    printf ("\n");
    printf ("vous disposez d'un plateau de 24 (X = 24) par 18 (Y = 18) \n");
    printf ("\n");
     switch (identifiant){
        case 1:corvette --;
            if (corvette = 0){
                printf ("Choisir un autre bateau");
            }
        case 2:croiseur --;
        if (croiseur = 0){
                printf ("Choisir un autre bateau");
            }
        case 3:porte_avion --;
        if (porte_avion = 0){
                printf ("Choisir un autre bateau");
            }
        case 4:destroyer --;
        if (destroyer = 0){
                printf ("Choisir un autre bateau");
            }
     }
     positionbateau (identifiant);
     placementbateauxjoueur( map[18][24][2], joueur, taillebateau, x, y); */

}
int main()
{
    int i,j;
    int saisi;
    int identifiant, position, X, Y;

    printf (" MENU\n");
    printf ("\n");
    printf (" 1 IA vs IA \n");
    printf (" 2 Joueur vs Joueur \n");
    printf (" 3 Joueur vs IA \n");
    printf (" 4 Charger une partie \n");
    printf (" 5 sauvegarder \n");
    printf ("\n");
    printf ("Veuillez choisir votre mode de jeux\n");
    scanf ("%d", &saisi);
    fflush(stdin);
    printf ("\n");


                    switch (saisi){
                    case 0:
                        break;
                    case 1: iaVsia ();
                        break;
                    case 2:
                        break;
                    case 3: joueurVSia ();
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    }
    return 0;

}
