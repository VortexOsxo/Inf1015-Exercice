// Par Francois-R.Boyer@PolyMtl.ca

#include <iostream>
using namespace std;

// - La fonction 'f' prend un pointeur de int comme seul paramètre et ne retourne rien:
void f(int* p) {
	// - Met 6 dans le int pointé par le paramètre.
	*p = 6;
	// - Alloue dynamiquement un nouveau int et conserver le pointeur dans le paramètre, et met 7 dans ce int.
	p = new int(7);
}

// - La fonction 'g' est une copie de la fonction 'f' mais prend une référence à un pointeur de int comme seul paramètre (au lieu de directement un pointeur) et ne retourne rien.  Et on change les valeurs 6 et 7 dans la fonction par 9 et 10.
void g(int*& p) {
	*p = 9;
	p = new int(10);
}

int main()
{
	// - Alloue dynamiquement un int et conserve le pointeur 'x'.
	int* x = new int; 
	// - Met la valeur 3 dans le int pointé par 'x'.
	*x = 3; 
	// - Affiche le int pointé par 'x'. (Affiche 3)
	cout << *x << endl; 
	// - Copie le pointeur dans un autre pointeur 'y'.
	int* y = x;
	// - Affiche le int pointé par 'y'. (Affiche 3) Pourquoi?
	cout << *y << endl;  // 'y' pointe au même endroit que 'x', la valeur pointée est donc nécessairement la même.
	// - Met la valeur 4 dans le int pointé par 'y'.
	*y = 4;
	// - Affiche encore le int pointé par 'x'. (Affiche 4) Pourquoi?
	cout << *x << endl;  // Même raison que ci-dessus.
	// - Copie le int pointé par 'x' dans une nouvelle mémoire allouée dynamiquement et conserve le pointeur 'z'.
	int* z = new int(*x);
	// - Met la valeur 5 dans le int pointé par 'x'.
	*x = 5;
	// - Affiche les int pointés par 'x' et 'z'. (Affiche 5 et 4) Pourquoi?
	cout << *x << " " << *z << endl;  // 'x' et 'z' ne pointent pas au même endroit, on a copié la valeur dans un nouvel endroit.
	// - Le main passe le pointeur 'x' à la fonction 'f'.
	f(x);
	// - Affiche le int pointé par 'x' et 'y' (après que la fonction 'f' ait terminé). (Affiche 6 et 6) Pourquoi?
	cout << *x << " " << *y << endl; // L'affectation de la valeur pointée par le paramètre change la valeur pointée 'x' et 'y' car il pointe au même endroit; par contre le paramètre lui-même est une copie du pointeur donc changer la valeur du pointeur en paramètre n'a pas d'impact sur les valeurs de 'x' et 'y'.
	// - Le main définit une variable 'a' de type int qui vaut 8.
	int a = 8;
	// - Passe la variable 'a' à la fonction 'f'.
	f(&a);
	// - Affiche le contenu de 'a'. (Affiche 6)
	cout << a << endl;
	// - Le main passe le pointeur 'x' à la fonction 'g'.
	g(x);
	// - Affiche le int pointé par 'x' et 'y'. (Affiche 10 et 9) Pourquoi?
	cout << *x << " " << *y << endl; // Cette fois le pointeur est passé par référence, donc la modification du paramètre modifie le pointeur 'x' qui ne point alors plus au même endroit que 'y'.
	// - Tente de passer la variable 'a' à la fonction 'g'.  Pourquoi il y a un problème?
	//g(&a); // Ne peut pas avoir une référence non const à un résultat d'expression (chap.2 diapo.8).
	// - Fait une variable qui pointe vers 'a' pour la passer à la fonction 'g'. (prend 2 lignes)
	int* w = &a;
	g(w);
	// - Affiche le contenu de 'a' et le int pointé par la variable qui pointait vers 'a'.  (Affiche 9 et 10)
	cout << a << " " << *w << endl;
}