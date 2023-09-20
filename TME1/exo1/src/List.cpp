//FAUTE : le header List.h n'est pas importé
#include "List.h"

namespace pr {

// ******************* Chainon
Chainon::Chainon (const std::string & data, Chainon * next):data(data),next(next) {};

size_t Chainon::length() {
	size_t len = 1;
	if (next != nullptr) {
		len += next->length();
	}
    //FAUTE: on doit retourner len et pas length, sinon boucle infinie + résultat jamais retourné
	return len;
}

//FAUTE: La signature de Chainon::print est différente de celle du header et donc n'est pas considérée comme implémentée
// Il manque le "const"
void Chainon::print (std::ostream & os) const {
	os << data ;
	if (next != nullptr) {
		os << ", ";
        //FAUTE: On ne doit continuer à afficher les chainons que si il y en a un suivant sinon accès mémoire à un
        // chainon qui n'existe pas => segfault
        next->print(os);
	}
}

// ******************  List
const std::string & List::operator[] (size_t index) const  {
	Chainon * it = tete;
	for (size_t i=0; i < index ; i++) {
		it = it->next;
	}
	return it->data;
}

void List::push_back (const std::string& val) {
	if (tete == nullptr) {
		tete = new Chainon(val);
	} else {
		Chainon * fin = tete;
		while (fin->next) {
			fin = fin->next;
		}
		fin->next = new Chainon(val);
	}
}

void List::push_front (const std::string& val) {
	tete = new Chainon(val,tete);
}

//FAUTE: empty est une méthode de la classe List, il faut le spécifier
bool List::empty() {
	return tete == nullptr;
}

size_t List::size() const {
	if (tete == nullptr) {
		return 0;
	} else {
		return tete->length();
	}
}


// FAUTE: on doit déplacer l'implémentation à l'intérieur du namespace pr
    std::ostream & operator<< (std::ostream & os, const List & vec)
    {
        os << "[";
        if (vec.tete != nullptr) {
            vec.tete->print (os) ;
        }
        os << "]";
        return os;
    }
} // namespace pr
