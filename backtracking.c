#include <stdio.h>
#include <stdlib.h>

//fonction pour trier les pièces dans l'ordre decroissant
int compare_desc(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

void afficherSolution(int* solution,int taille){

    printf("Les pieces utilisées: ");

    for(int i=0; i<taille; i++){
        printf("%d$ ", solution[i]);
    }

    printf("\n");
}


void backtrack(int montant, int* pieces, int taille , int index , int* solution,int tailleSolution, int*  meilleurSolution, int* minPieces){

    // Si le montant est égal à 0

    if(montant == 0){

        if(tailleSolution< *minPieces){
            *minPieces = tailleSolution;
            for(int i=0; i<tailleSolution; i++){
                meilleurSolution[i] = solution[i];
            }
        }

        return;
    }

    if(montant < 0 || index >= taille){
        return;
    }

    for(int i=index;i<taille;i++){
        if(pieces[i] <= montant){
            solution[tailleSolution] = pieces[i]; //inclure la piece actuelle dans la solution
            backtrack(montant-pieces[i],pieces,taille,i,solution,tailleSolution+1,meilleurSolution,minPieces);
        }
    }
}

int main(void){

    int pieces[] = {1,2,5,10,20,50};
    int taille = sizeof(pieces)/sizeof(pieces[0]);

    //tri des pièces dans l'ordre decroissant

    qsort(pieces,taille,sizeof(int),compare_desc);

    int montant;
    printf("Entrez le montant a rendre: ");
    scanf("%d",&montant);

    int solution[100];
    int meilleureSolution[100];
    int minPieces = 100;

    backtrack(montant,pieces,taille,0,solution,0,meilleureSolution,&minPieces);

    if(minPieces!= 100){
        afficherSolution(meilleureSolution,minPieces);
        printf("Le nombre minimal de pieces utilisées: %d\n",minPieces);
    }else{
        printf("Impossible de rendre le montant avec les pieces disponibles.\n");
    }


    return 0;
}