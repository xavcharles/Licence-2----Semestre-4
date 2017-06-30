#include <stdio.h>

#include "ArbreBinaire.h"

#define max(a,b) ((a)>(b)?(a):(b))

static int nbComp ;

/* Manipulation d'arbres binaires */

Noeud_t arbre1 (void) {
   Noeud_t debut, gauche, droite;
   debut = CreerNoeud(12);
   gauche = CreerNoeud(9);
   droite = CreerNoeud(8);
   AjouterFilsGauche(debut,gauche);
   AjouterFilsDroit(debut,droite);
   return debut;
}

Noeud_t arbre2 (void) {
   Noeud_t debut, first, second, third;
   debut = CreerNoeud(12);
   first = CreerNoeud(9);
   second = CreerNoeud(5);
   third = CreerNoeud(7);
   AjouterFilsGauche(debut,first);
   AjouterFilsDroit(first,second);
   AjouterFilsGauche(second,third);
   return debut;
}

Noeud_t arbre3 (void) {
   Noeud_t debut, left, leftL, leftR, right, rightR, rightRL,rightRR;
   debut = CreerNoeud(12);
   left = CreerNoeud(9);
   leftL = CreerNoeud(1);
   leftR = CreerNoeud(5);
   right = CreerNoeud(8);
   rightR = CreerNoeud(4);
   rightRL = CreerNoeud(7);
   rightRR = CreerNoeud(6);
   AjouterFilsGauche(debut,left);
   AjouterFilsGauche(left,leftL);
   AjouterFilsDroit(left,leftR);
   AjouterFilsDroit(debut,right);
   AjouterFilsDroit(right, rightR);
   AjouterFilsDroit(rightR,rightRR);
   AjouterFilsGauche(rightR, rightRL);
   return debut;
}



void imprimer (Noeud_t a) {
   if(!EstVide(a)){
      imprimer(FilsGauche(a));
      printf("%d ", ValeurDuNoeud(a));
      imprimer(FilsDroit(a));
   }  
}

int taille (Noeud_t a) {
   if(EstVide(a)) return 0 ;
   return 1 + taille(FilsGauche(a)) + taille(FilsDroit(a));
}

int hauteur (Noeud_t a) {
   if(EstVide(a)) return -1;
   return 1 + max(hauteur(FilsGauche(a)),hauteur(FilsDroit(a))) ;
}

int nbFeuilles(Noeud_t a) {
   if(EstVide(a)) return 0 ;
   if(EstFeuille(a)) return 1;
   return nbFeuilles(FilsGauche(a)) + nbFeuilles(FilsDroit(a));
}


/* Comptage d'arbres */
/*
int nbArbres(int n) {
   int k, res;
   if(n==0)return 1;
   for(res = 0,k=0;k<n;k++)
      res = res + (nbArbres(k) * nbArbres(n-k-1));
   return res;
}*/
    
int nbArbres(int n) {
   int res, k, i, tab[n] ;
   for(tab[0] = 1,k=1;k<=n;k++) {
      res = 0;
      for(i=0;i<k;i++)
         res += (tab[i] * tab[k-i-1]);
      tab[k] = res;
   }
   return tab[n];
}

/* Manipulation d'arbres binaires de recherche */

Noeud_t abr1 (void) {
   Noeud_t monArbre, fg ;

   monArbre = CreerNoeud(6) ;
   AjouterFilsGauche(monArbre, CreerNoeud(4));
   fg = FilsGauche(monArbre);
   AjouterFilsGauche(fg, CreerNoeud(2));
   AjouterFilsDroit(monArbre, CreerNoeud(7));
   AjouterFilsDroit(fg, CreerNoeud(5));
   fg = FilsGauche(fg);
   AjouterFilsGauche(fg, CreerNoeud(1));
   return monArbre;
}

Noeud_t ajouter (value_t v, Noeud_t a) {
   Noeud_t tmp ;
   if(EstVide(a)) 
      return CreerNoeud(v);
   else{
      if(v <= ValeurDuNoeud(a)){
         tmp = ajouter(v, FilsGauche(a));
         RemplacerFilsGauche(a,tmp);
         return a;
      }else{
         tmp = ajouter(v, FilsDroit(a));
         RemplacerFilsDroit(a, tmp);
         return a;
      }
   }
}
    
Noeud_t abr2 (void) {
   Noeud_t monArbre;
   monArbre = ajouter(5, NULL);
   ajouter(4,monArbre);
   ajouter(2,monArbre);
   ajouter(7,monArbre);
   ajouter(6,monArbre);
   ajouter(1,monArbre);
   return monArbre;
}

Noeud_t abr3 (void) {
   Noeud_t monArbre;
   monArbre = ajouter(7, NULL);
   ajouter(1,monArbre);
   ajouter(4,monArbre);
   ajouter(5,monArbre);
   ajouter(6,monArbre);
   ajouter(2,monArbre);
   return monArbre;
}

int appartient (value_t v, Noeud_t a) {
   if(EstVide(a)) return 0;
   if(v == ValeurDuNoeud(a)) {nbComp++;return 1;}
   nbComp += 2;
   if(v <= ValeurDuNoeud(a))
      return appartient(v, FilsGauche(a));
   else
      return appartient(v, FilsDroit(a));
}

int valeur_minimale (Noeud_t abr) {
   if(EstVide(FilsGauche(abr)))
	return ValeurDuNoeud(abr);
   return valeur_minimale(FilsGauche(abr));
}

int valeur_maximale (Noeud_t abr) {
   if(EstVide(FilsDroit(abr)))
	return ValeurDuNoeud(abr);
   return valeur_maximale(FilsDroit(abr));
}

/* Entier mysterieux */

Noeud_t construitArbreEntierMysterieux (value_t i, value_t j) { 
   Noeud_t tmp = NULL;
   int add ;
   if(j >= i){
      add = i+((j-i)/2);
      tmp = CreerNoeud(add);
      AjouterFilsGauche(tmp,construitArbreEntierMysterieux(i,add-1));
      AjouterFilsDroit(tmp,construitArbreEntierMysterieux(add+1,j));
   }
   return tmp;
}

void jouer (int n) {
   int currentnb, symbol;
   Noeud_t arbre;
   arbre = construitArbreEntierMysterieux(1,n);
   currentnb = ValeurDuNoeud(arbre);
   printf("%d ? \n", currentnb);
   while((symbol = getchar()) != '='){
      if(symbol == '-'){
         if(FilsGauche(arbre)) {
            printf("Plus petit !\n");
            currentnb = ValeurDuNoeud(arbre = FilsGauche(arbre));
         }else {
            printf("Ce nombre doit être celui que vous recherchez, sinon, vous avez fait une erreur quelque part.\n");
            printf("%d ? \n", currentnb);
            continue;
         }
      }else if(symbol == '+'){
         if(FilsDroit(arbre)) {
            printf("Plus grand !\n");
            currentnb = ValeurDuNoeud(arbre = FilsDroit(arbre));
         }else {
            printf("Ce nombre doit être celui que vous recherchez, sinon, vous avez fait une erreur quelque part.\n");
            printf("%d ? \n", currentnb);
            continue;
         }
      } else continue;
      printf("%d ? \n", currentnb);
   }
   printf("Trouvé, le nombre est bien %d !\n", currentnb);
}

/* Tests sur les arbres binaires */

void testArbreBinaire(Noeud_t a) {
   imprimer(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
}

/* Tests sur les arbres binaires de recherche */
void testABR (Noeud_t a) {
   int i;
   imprimer(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
   printf("Valeurs présentes dans l'arbre : ");
   for (i = 1; i <= 10; i++) {
      if (appartient(i,a)) {
         printf("%d ",i);
      }
   }
   /* ajouté par moi*/
   printf("\n");
   nbComp = 0;
   printf("0 appartient-il à l'arbre ? %d\n",appartient(0,a));
   printf("Nombre de comparaisons pour 0 appartient à l'arbre : %d\n", nbComp);
   printf("Valeur minimale de l'arbre %d\n", valeur_minimale(a));
   printf("Valeur maximale de l'arbre %d\n", valeur_maximale(a));
   /* fin ajout*/
   printf("\n");
}
  
/* Programme principal */
int main (int argc, char **argv) {

   int i;
   
   testArbreBinaire(arbre1());
   testArbreBinaire(arbre2());
   testArbreBinaire(arbre3());

   for (i = 0; i <= 19; i++) {
      printf("Le nombre d'arbres à %d noeuds est %d\n",i,(nbArbres(i)));
   }
  
   testABR(abr1());
   testABR(abr2());
   testABR(abr3());

   printf("Arbre mysterieux entre 12 et 24:\n");
   imprimer(construitArbreEntierMysterieux(12,24));
   printf("\n");
  
   jouer(100);

   return 0;
   
}
