#include "complexe.h"
#include <math.h>           // Pour certaines fonctions trigo notamment

// Implantations de reelle et imaginaire

double reelle (complexe_t z){
  return (double) z.reelle;
}


double imaginaire (complexe_t z){
  return (double) z.imaginaire;
  };

// Implantations de set_reelle et set_imaginaire

void set_reelle (complexe_t *z, double a){
   (*z).reelle = a;
}


void set_imaginaire (complexe_t *z, double a){
   (*z).imaginaire = a;
}


void init (complexe_t *z, double a, double b){
    set_reelle (z, a);
    set_imaginaire (z, b);
}

// Implantation de copie

void copie (complexe_t *resultat, complexe_t autre) {
     (*resultat).reelle = autre.reelle;
     (*resultat).imaginaire = autre.imaginaire;
}

// Implantations des fonctions algébriques sur les complexes

void conjugue (complexe_t *resultat, complexe_t op)
{
  (*resultat).imaginaire = - op.imaginaire;
  (*resultat).reelle = op.reelle;
}


void ajouter (complexe_t *resultat, complexe_t gauche, complexe_t droite){
  (*resultat).reelle = gauche.reelle + droite.reelle;
  (*resultat).imaginaire = gauche.imaginaire + droite.imaginaire;
}


void soustraire (complexe_t *resultat, complexe_t gauche, complexe_t droite){
  (*resultat).reelle = gauche.reelle - droite.reelle;
  (*resultat).imaginaire = gauche.imaginaire - droite.imaginaire;
}


void multiplier (complexe_t *resultat, complexe_t gauche, complexe_t droite){
  (*resultat).reelle = gauche.reelle*droite.reelle - gauche.imaginaire*droite.imaginaire;
  (*resultat).imaginaire = gauche.reelle*droite.imaginaire + gauche.imaginaire*droite.reelle;
}


void echelle (complexe_t *resultat, complexe_t op, double facteur) {
  (*resultat).reelle = op.reelle * facteur;
  (*resultat).imaginaire = op.imaginaire * facteur;
}


void puissance (complexe_t *resultat, complexe_t op, int exposant){
  if (exposant == 0) {
    init(resultat,1,0);
  } else {
    copie(resultat,op);
    for (int i=1;i<exposant;i++) {
      multiplier(resultat, *resultat, op);
    }  
  } 
}

// Implantations du module et de l'argument

double module_carre (complexe_t z) {
  double module_carre = pow (module (z), 2);
  return module_carre;
}

double module (complexe_t z) {
  double module = sqrt (pow (z.reelle, 2) + pow (z.imaginaire, 2));
  return module;
}


double argument (complexe_t z) {
  return 2 * atan(imaginaire(z)/(reelle(z) + module(z)));
}
