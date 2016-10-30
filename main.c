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
#define TOUCHE 7
#define WATER_SHOOT 9
#define MAP_PLAYERS 2




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
    int s=0;
    int k=0;

    t = doRand (0,1);
    x = doRand(0,17-taillebateau);
    y = doRand(0,23-taillebateau);

    /* placement du bateau à l'interieur de la carte à la verticale */
    if (t== 0){
            for (i=0;i<taillebateau;i++){
                if(map[x+i][y][joueur]==0 && map[x+i][y][joueur]<18 && map[x+i][y][joueur]>=0){
                map[x+i][y][joueur]=taillebateau;
                }
            }
    }

    /* placement du bateau à l'interieur de la carte à l'horizontale*/
    if (t== 1){
        for (j=0;j<taillebateau;j++){
                if(map[x][y+j][joueur]==0 && map[x][y+j][joueur]<18 && map[x][y+j][joueur]>=0){
                map[x][y+j][joueur]=taillebateau;
                }
        }
    }
}

void placementbateauxjoueur(int map[18][24][2], int joueur,int taillebateau){

    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    int t = 0;
    int s=0;
    int k=0;



    /* placement du bateau à l'interieur de la carte à la verticale */
    if (t== 0 /*&& s== taillebateau */){
            for (i=0;i<taillebateau;i++){
                if(map[x+i][y][joueur]==0 && map[x+i][y][joueur]<18 && map[x+i][y][joueur]>=0){
                map[x+i][y][joueur]=taillebateau;
                }
            }
    }

    /* placement du bateau à l'interieur de la carte à l'horizontale*/
    if (t== 1 /*&& s== taillebateau */){
        for (j=0;j<taillebateau;j++){
                if(map[x][y+j][joueur]==0 && map[x][y+j][joueur]<18 && map[x][y+j][joueur]>=0){
                map[x][y+j][joueur]=taillebateau;
                }
        }
    }
}

void positionbateau (int identifiant){
    int bateau = 6;
    int x,y,t;
    int position;

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
        /* bateau choisi */
            while(1>identifiant || identifiant>5){
                printf ("saisir un chiffre valable\n");
                scanf ("%d", &identifiant);
                fflush (stdin);
            }
            /* placement du bateau en X */
            printf ("saisir X \n");
            scanf("%d", &x);
            while (0>x ||x>25){
                printf ("saisir un chiffre valable \n");
                scanf ("%d", &x);
            }
            fflush (stdin);
            printf ("\n");

            /* placement du bateau en y */
            printf ("entrez ca position en Y \n");
            scanf ("%d", &y);
            while (0>y || y>18){
                printf ("saisir un chiffre valable \n");
                scanf ("%d", &y);
            }
            fflush (stdin);
            printf ("\n");

            /* placement du bateau à l'horizontale et à la verticale */
            printf ("pour les placer horizontalement tape 0, pour le placer verticalement tape 1 \n");
            scanf ("%d", &t);
            while (t>1 || t<0){
            printf ("saisir un chiffre valide \n");
            scanf ("%d", &t);
            fflush (stdin);}
            printf ("\n");

            bateau --;

    }while (bateau != 0);
}

void attaque (int map [18][24][2], int joueur){

    int t,x,y, i, j;
    int gagner=0;
    int tir = 0;
    int taillebateau;

    /* placement du tir en aléatoire*/
    t = doRand (0,1);
    x = doRand(0,17);
    y = doRand(0,23);

}

void iaVsia (){

    int map[18][24][2]={0};
    int joueur;

    Color(7,0);
    printf("\n");
    placementbateaux(map,joueur1,CORVETTE);
    placementbateaux(map,joueur1,DESTROYER);
    placementbateaux(map,joueur1,DESTROYER);
    placementbateaux(map,joueur1,CROISEUR);
    placementbateaux(map,joueur1,CROISEUR);
    placementbateaux(map,joueur1,PORTEAVION);
    printf("\n");
    /*affiche la position des bateau du ia1*/
    printf("MAP JOUEUR 1\n");
    placementbateaux(map,joueur2,CORVETTE);
    placementbateaux(map,joueur2,DESTROYER);
    placementbateaux(map,joueur2,DESTROYER);
    placementbateaux(map,joueur2,CROISEUR);
    placementbateaux(map,joueur2,CROISEUR);
    placementbateaux(map,joueur2,PORTEAVION);
    affichemap(map,joueur1);
    printf("\n");
    /*affiche la position des bateaux du ia2*/
    printf("MAP JOUEUR 2\n");
    affichemap(map,joueur2);
    fflush (stdin);
    getchar ();


}

void positionbateaujoueur (int identifiant){
    int bateau = 6;
    int x,y;
    int position;
    int map[18][24][2];
    int joueur, taillebateau;

    /* sauvegarde emplacement bateau joueur */
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
            placementbateauxjoueur( map[18][24][2], joueur, taillebateau);
            affichemap( map[18][24][2],joueur);


            printf ("entrez ca position en Y \n");
            scanf ("%d", &y);
            while (0>y || y>18){
                printf ("saisir un chiffre valable \n");
                scanf ("%d", &y);
                fflush (stdin);
            }

            printf ("\n");
            placementbateauxjoueur( map[18][24][2], joueur, taillebateau);
            affichemap( map[18][24][2],joueur);

            printf ("pour les placer horizontalement tape 0, pour le placer verticalement tape 1 \n");
            scanf ("%d", &position);
            while (position>1 || position<0){
            printf ("saisir un chiffre valide \n");
            scanf ("%d", &position);
            fflush (stdin);}
            printf ("\n");
            placementbateauxjoueur( map[18][24][2], joueur, taillebateau);
            affichemap( map[18][24][2],joueur);

            bateau --;

        } while (bateau != 0);
}

void joueurVSjoueur (){

    int x, y, position,i,j;
    int identifiant;
    int bateau = 6;
    int player;
    int joueur;
    int corvette = 1;
    int croiseur = 2;
    int porte_avion = 2;
    int destroyer = 1;
    int taillebateau;
    int map [MAP_W][MAP_H][MAP_PLAYERS];

      for (i=0; i<MAP_H; i++){
        for (j=0; j<MAP_W; j++){
                    printf ("0 ");
        }printf ("\n");
     }printf ("\n");
     printf ("Vous disposez de:\n %d corvette de taille 1 \n %d destroyer de taille 3\n %d croiseur de taille 4\n %d porte-avion de taille 6 \nVous pouvez les placer horizontalement ou verticalement \n", corvette, destroyer, porte_avion, croiseur);
    printf ("\n");
    printf ("vous disposez d'un plateau de 24 (X = 24) par 18 (Y = 18) \n");
    printf ("\n");
    positionbateau (identifiant);

    /* décompte jusqu'a 0 pour le placement des bateaux */
     switch (identifiant){
        case 1:corvette --;
        placementbateaux(map,joueur1,CORVETTE);
        break;
        case 2:croiseur --;
        placementbateauxjoueur( map[MAP_H][MAP_W][MAP_PLAYERS], joueur, taillebateau);
        break;
        case 3:porte_avion --;
        placementbateauxjoueur(map[MAP_H][MAP_W][MAP_PLAYERS], joueur, taillebateau);
        break;
        case 4:destroyer --;
        placementbateauxjoueur( map[MAP_H][MAP_W][MAP_PLAYERS], joueur, taillebateau);
        break;
    }

    positionbateaujoueur (identifiant);
    getchar();
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
    int joueur;
    int taillebateau;

    /*affichemap(map[18][24][2], joueur);*/
    int map [MAP_W][MAP_H][MAP_PLAYERS];

      for (i=0; i<MAP_H; i++){
        for (j=0; j<MAP_W; j++){
                    printf ("0 ");
        }printf ("\n");
     }printf ("\n");
    printf ("Vous disposez de:\n %d corvette de taille 1 \n %d destroyer de taille 3\n %d croiseur de taille 4\n %d porte-avion de taille 6 \nVous pouvez les placer horizontalement ou verticalement \n", corvette, destroyer, porte_avion, croiseur);
    printf ("\n");
    printf ("vous disposez d'un plateau de 24 (X = 24) par 18 (Y = 18) \n");
    printf ("\n");
    positionbateau (identifiant);

    /* placement bateau joueur */
     switch (identifiant){
        case 1:
        placementbateauxjoueur(map[MAP_H][MAP_W][MAP_PLAYERS], joueur, taillebateau);
        affichemap(map[18][24][2], joueur);
        corvette --;
        break;
        case 2:croiseur --;
        placementbateauxjoueur( map[MAP_H][MAP_W][MAP_PLAYERS], joueur, taillebateau);
        affichemap(map[18][24][2], joueur);
        break;
        case 3:porte_avion --;
        placementbateauxjoueur(map[MAP_H][MAP_W][MAP_PLAYERS], joueur, taillebateau);
        affichemap(map[18][24][2], joueur);
        break;
        case 4:destroyer --;
        placementbateauxjoueur( map[MAP_H][MAP_W][MAP_PLAYERS], joueur, taillebateau);
        affichemap(map[18][24][2], joueur);
        break;
    }

    /*placement beateau IA */
    placementbateauxjoueur(map,joueur1,CORVETTE);
    placementbateauxjoueur(map,joueur1,DESTROYER);
    placementbateauxjoueur(map,joueur1,DESTROYER);
    placementbateauxjoueur(map,joueur1,CROISEUR);
    placementbateauxjoueur(map,joueur1,CROISEUR);
    placementbateauxjoueur(map,joueur1,PORTEAVION);
    printf("\n");
    /*affiche la position des bateau du ia1*/
    printf("MAP IA1\n");
    affichemap(map,joueur1);
    printf("\n");
    fflush (stdin);
}

int main()
{
    FILE* fichier = NULL;
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
                    case 2: joueurVSjoueur();
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
