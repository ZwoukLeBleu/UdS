// * ==================== Q 1.1 ====================
/*
Une pile cest comme un stack (pancakes)
*/

// * ==================== Q 1.2 ====================
/*
class Pile {
public:
	Pile(int cap);
	~Pile();
	bool inserer(int val);
private:
	int capacite;
	int taille;
	int *data;
};

DEBUT
	FONCTION inserer(val) :
		SI taille == capacite ALORS:
			double_capacite()
		data[taille] := val
		taille := taille + 1 
	
	FONCTION double_capacite():
		capacite *= 2
		int* temp = nouveau int[capacite]
		POUR i a taille-1:
			temp[i] := data[i]
		retourne vrai

FIN

*/

// TODO: ==================== Q 1.3 ====================
/*
*/




// * ==================== Q 2.1 ====================
/*
deep copy = copy qui copie individuellement chaque items et les replaces dans les bons pointeurs au lieu de juste p_a = p_b
*/


// ? ==================== Q 2.2 ====================
/*
car lorsque = est utiliser, on re-ecrit sur les donnees deja ecrite de la variable. 
Une valeur ed retour assure que lon renvoie une valeur pour que le compilateur puisse lassigner 
*/


// * ==================== Q 2.3 ====================
/*

*/


// ? ==================== Q 2.4 ====================
/*
class Date
{
public:
    bool operator>=(Dat& d)
	friend ostream& operator<<(ostream& os, Date& d)
private:
    int jour;
    int mois;
    int annee;
};

	bool operator>=(Dat& d){
		cest de la marde leur affaire faque allez chier
	}

	ostream& operator<<(ostream& os, Date& d){
		os << d.jour << - << d.mois << - << d.annee;
		return os;
	}


*/


// * ==================== Q 3.1 ====================
/*
	qujand on ne sais pas quel type pourrais etre associer avec la classe (stack ou queue)
*/


// * ==================== Q 3.@ ====================
/*
template < class T >
class Tableau
{
	T * tab; // Le tableau ou sont stockes les elements
	int tailleTab; // Nombre d'elements dans tableau
public:
	void ImprimeTableau(); // Affiche le tableau a l'ecran
};

void Tableau<T>::ImprimeTableau(){
	for (int i=0; i< tailltab; i++){
		cout << tab[i];
	}
}

*/


// * ==================== Q 3.3 ====================
/*

	<< lui la
*/


// * ==================== Q 3.4 ====================
/*
class Transmission {
public:
	void monterVitesse();
	void descendreVitesse();
};
class Voiture {
public:
	virtual void changementVitesse(int direction);
};


classe Char : public Voiture {
public:
	void changerVitesse(int direction);

private: 
	Transmission t;
}

void Char::changerVitesse(int direction){
	if (direction > 0){ t.monterVitesse();}
	else { t.descendreVitesse(); }
	return;

}
*/

