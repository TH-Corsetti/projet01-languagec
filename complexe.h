#ifndef COMPLEX_H
#define COMPLEX_H

// Type utilisateur complexe_t
/** À COMPLÉTER **/
struct complexe {
  float reelle;
  float imaginaire;
};

typedef struct complexe complexe_t;

// Fonctions reelle et imaginaire
/**
 * reelle
 * Renvoie la partie réelle d'un complexe en argument
 * 
 * Paramètres :
 *   z       [in] Complexe dont l'on veut la partie réelle
 *
 * Post-conditions : le résultat est un réel
 */


float reelle (complexe_t z);

/**
 * imaginaire
 * Renvoie la partie imaginaire d'un complexe en argument
 * 
 * Paramètres :
 *   z       [in] Complexe dont l'on veut la partie imaginaire
 *
 * Post-conditions : le résultat est un réel
 */

float imaginaire (complexe_t z);

// Procédures set_reelle, set_imaginaire et init
/**
 * set_reelle
 * Modifie la partie réelle du complexe donné en second argument par le réel donné
 * en second argument
 *
 * Paramètres :
 *   z       [in/out] Complexe modifié
 *   a           [in] Réel qui devient la partie réelle de z
 *
 * Post-conditions : reelle(z) = a
 */

void set_reelle (complexe_t* z, float a);

/**
 * set_imaginaire
 * Modifie la partie imaginaire du complexe donné en second argument par le réel donné
 * en second argument
 *
 * Paramètres :
 *   z       [in/out] Complexe modifié
 *   a           [in] Réel qui devient la partie imaginaire de z
 *
 * Post-conditions : imaginaire(z) = a
 */

void set_imaginaire(complexe_t* z, float a);

/**
 * init
 * Initialise le complexe donné en premier argument par les réels donnés
 * en second et troisième arguments
 *
 * Paramètres :
 *   z          [out] Complexe initialisé
 *   a           [in] Réel qui devient la partie réelle de z
 *   b           [in] Réel qui devient la partie imaginaire de z
 *
 * Post-conditions : imaginaire(z) = b et reele(z) = a
 */

void init(complexe_t* z, float a, float b);

// Procédure copie
/**
 * copie
 * Copie les composantes du complexe donné en second argument dans celles du premier
 * argument
 *
 * Paramètres :
 *   resultat       [out] Complexe dans lequel copier les composantes
 *   autre          [in]  Complexe à copier
 *
 * Pré-conditions : resultat non null
 * Post-conditions : resultat et autre ont les mêmes composantes
 */
 
void copie(complexe_t* resultat, complexe_t autre);

// Algèbre des nombres complexes
/**
 * conjugue
 * Calcule le conjugué du nombre complexe op et le sotocke dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut le conjugué
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : reelle(*resultat) = reelle(op), complexe(*resultat) = - complexe(op)
 */
void conjugue(complexe_t* resultat, complexe_t op);

/**
 * ajouter
 * Réalise l'addition des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche + droite
 */
 
void ajouter(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * soustraire
 * Réalise la soustraction des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche - droite
 */
 
void soustraire(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * multiplier
 * Réalise le produit des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche * droite
 */
 
void multiplier(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * echelle
 * Calcule la mise à l'échelle d'un nombre complexe avec le nombre réel donné (multiplication
 * de op par le facteur réel facteur).
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe à mettre à l'échelle
 *   facteur        [in]  Nombre réel à multiplier
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = op * facteur
 */
 
void echelle(complexe_t* resultat, complexe_t op, double facteur);

/**
 * puissance
 * Calcule la puissance entière du complexe donné et stocke le résultat dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut la puissance
 *   exposant       [in]  Exposant de la puissance
 *
 * Pré-conditions : resultat non-null, exposant >= 0
 * Post-conditions : *resultat = op * op * ... * op
 *                                 { n fois }
 */
 
void puissance(complexe_t* resultat, complexe_t op, int exposant);

// Module et argument
/**
 * module_carre
 * Calcule le carré du module d'un complexe
 *
 * Paramètres :
 *   z       [in] Complexe dont l'on veut calculer le carré du module
 *
 * Post-conditions : module_carre(z) >= 0, et si z est non nul : module_carre(z) > 0
 *
 */

float module_carre (complexe_t z);

/**
 * module
 * Calcule le module d'un complexe
 *
 * Paramètres :
 *   z       [in] Complexe dont l'on veut calculer le module
 *
 * Post-conditions : module(z) >= 0, et si z est non nul : module(z) > 0
 *
 */

float module(complexe_t z);

/**
 * argument
 * Calcule l'argument d'un complexe
 *
 * Paramètres :
 *   z       [in] Complexe dont l'on veut calculer l'argument
 *
 * Pré-conditions : z est non nul
 * Post-conditions : argument(z) est compris entre -pi et pi
 *
 */

float argument(complexe_t);


#endif // COMPLEXE_H



