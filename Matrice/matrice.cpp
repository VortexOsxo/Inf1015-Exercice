#include <iostream>
#include <utility>

class Matrice {
public:
	Matrice(int hauteur=3, int largeur=3) {
		hauteur_ = hauteur;
		largeur_ = largeur;
		données_ = new double [largeur*hauteur];

		for (int i = 0; i < largeur_*hauteur_; i++) {
			données_[i] = 0.0;
		}
	}

	std::pair<int, int> taille() const {
		return {largeur_, hauteur_};
	}

	void afficherMatrice() const {
		for (int i = 0; i < hauteur_; i ++) {
			for (int j = 0; j < largeur_; j ++) {
				std::cout << données_[i*largeur_ + j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	double& accède(int i, int j) { 
		//retourne une référence à la valeur à cet emplacement
		//ce qui nous permets de modifier directement où avec une variable qui contient la référence
		return accèdeInterne(i, j);
	}

	const double& accède(int i, int j) const { 
		//version appelé lorsque la matrice est une constante. Besoin de définir deux fois si on veut une 
		//où on peut modifier et une qu'on peut appeler si la matrice est const et donc qui doit aussi être const
		//voir vidéo Chap 4 Exemple à la fin
		return accèdeInterne(i, j);
	}



	~Matrice() {
		delete[] données_;
	}

private:
	double& accèdeInterne(int i, int j) const {
		return données_[i * largeur_ + j];
	}

	int hauteur_;
	int largeur_;
	double* données_;
};


int main(int argc, char* argv[])
{
	Matrice mat(3,3);
	mat.accède(2,2) = 100;
	mat.afficherMatrice();
	auto [largeur, hauteur] = mat.taille();
	std::cout << "La talle de la matrice est: " << largeur << " x " << hauteur << std::endl;
	return 0;
}
