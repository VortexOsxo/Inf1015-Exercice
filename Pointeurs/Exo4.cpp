#include <iostream>

struct A {
    int x, y;
};
struct B {
    A* valeurs;
    int nValeurs;
};

void afficherA(const A& a){
    std::cout << "x: " << a.x << " y: " << a.y << std::endl;
}

void incrémenterA(A& a){
    a.x ++;
    a.y ++;
}

void afficherB(const B& b) {
    for (int i = 0; i < b.nValeurs; i ++) {
        afficherA(b.valeurs[i]);
    }
}

int main() {
    A a = {3,4};
    afficherA(a);
    A* b = &a;
    afficherA(*b); //on ajoute le * pour avoir un type A comme demand. par la fonction
    *b = {5,6};
    afficherA(a); //a est bien modifié lorsqu'on modifie b puisque b pointe vers a
    incrémenterA(*b);
    afficherA(a); // même logique
    std::cout << "partie allocation dynamique c" << std::endl;

    A* c = new A(*b);
    incrémenterA(*b);
    afficherA(*b);
    afficherA(*c); // Valeur différente puisque l'allocation de mémoire avec new créer un nouvel espace différent

    B d = { new A[2]{ *b, *c }, 2 };
    afficherB(d);
    
    B e = d; // shallow copie
    e.valeurs[1].x = 9;
    afficherB(d); // La copie a copié le pointeur et non la valeur pointé, donc 'e' pointe vers le même tableau que 'd'.
}