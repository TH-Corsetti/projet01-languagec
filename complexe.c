#include "complexe.h"
#include <math.h>           // Pour certaines fonctions trigo notamment

// Implantations de reelle et imaginaire
/** FONCTION reelle À IMPLANTER **/
float reelle (complexe_t z){
  return z.reelle;
}

/** FONCTION imaginaire À IMPLANTER **/
float imaginaire (complexe_t z){
  return z.imaginaire;
  };

// Implantations de set_reelle et set_imaginaire
/** PROCÉDURE set_reelle À IMPLANTER **/
void set_reelle (complexe_t *z, float a){
   (*z).reelle = a;
}

/** PROCÉDURE set_imaginaire À IMPLANTER **/
void set_imaginaire (complexe_t *z, float a){
   (*z).imaginaire = a;
}

/** PROCÉDURE init À IMPLANTER **/
void init (complexe_t *z, float a, float b){
    set_reelle (z, a);
    set_imaginaire (z, b);
}

// Implantation de copie
/** PROCÉDURE copie À IMPLANTER */
void copie (complexe_t *resultat, complexe_t autre) {
     (*resultat).reelle = autre.reelle;
     (*resultat).imaginaire = autre.imaginaire;
}

// Implantations des fonctions algébriques sur les complexes
/** PROCÉDURE conjugue À IMPLANTER **/
void conjugue (complexe_t *resultat, complexe_t op)
{
  (*resultat).imaginaire = - op.imaginaire;
  (*resultat).reelle = op.reelle;
}

/** PROCÉDURE ajouter À IMPLANTER **/
void ajouter (complexe_t *resultat, complexe_t gauche, complexe_t droite){
  (*resultat).reelle = gauche.reelle + droite.reelle;
  (*resultat).imaginaire = gauche.imaginaire + droite.imaginaire;
}

/** PROCÉDURE soustraire À IMPLANTER **/
void soustraire (complexe_t *resultat, complexe_t gauche, complexe_t droite){
  (*resultat).reelle = gauche.reelle - droite.reelle;
  (*resultat).imaginaire = gauche.imaginaire - droite.imaginaire;
}

/** PROCÉDURE multiplier À IMPLANTER **/
void multiplier (complexe_t *resultat, complexe_t gauche, complexe_t droite){
  (*resultat).reelle = gauche.reelle*droite.reelle - gauche.imaginaire*droite.imaginaire;
  (*resultat).imaginaire = gauche.reelle*droite.imaginaire - gauche.imaginaire*droite.reelle;
}

/** PROCÉDURE echelle À IMPLANTER **/
void echelle (complexe_t *resultat, complexe_t op, double facteur) {
  (*resultat).reelle = op.reelle * facteur;
  (*resultat).imaginaire = op.imaginaire * facteur;
}

/** PROCÉDURE puissance À IMPLANTER **/
void puissance (complexe_t *resultat, complexe_t op, int exposant){
  float module_op = module(op);
  float angle = argument (op) * exposant;
  float module = pow (module_op, exposant);
  (*resultat).reelle = module * cos (angle);
  (*resultat).imaginaire = module * sin(angle);
}

// Implantations du module et de l'argument
/** FONCTION module_carre À IMPLANTER **/
float module_carre (complexe_t z) {
  float module_carre = pow (module (z), 2);
  return module_carre;
}
/** FONCTION module À IMPLANTER **/
float module (complexe_t z) {
  float module = sqrt (pow (z.reelle, 2) + pow (z.imaginaire, 2));
  return module;
}

/** FONCTION argument À IMPLANTER **/
float argument (complexe_t z) {
  float theta;
  if (z.reelle != 0) {
      theta = atanf (z.imaginaire / z.reelle);
    }
  else {
      theta = 0;
    }
  return theta;
}
