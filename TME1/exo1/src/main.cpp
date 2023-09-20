#include "List.h"
#include <string>
#include <iostream>
#include <cstring>

int main () {

	std::string abc = "abc";
	char * str = new char [3];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	size_t i = 0;

	if (! strcmp (str, abc.c_str())) {
        //FAUTE: oubli de mettre mettre le carctère de fin de ligne
		std::cout << "Equal !" << std::endl;
	}

	pr::List list;
	list.push_front(abc);
	list.push_front(abc);

	std::cout << "Liste : " << list << std::endl;
	std::cout << "Taille : " << list.size() << std::endl;

	// Affiche à l'envers
    // FAUTE: on doit remplacer >= par > dans le for car list.size()  renvoit un size_t qui est forcemment >=0 donc la
    // condition de boucle est toujours vraie (boucle infinie) de plus en faisaint -- sur un size_t égal à 0 on
    // va reboucler sur la valeur max: 18446744073709551615 et donc accéder un une zone mémoire non définie => segfault
    // Cependant on veut quand même afficher l'élément d'indice 0 donc on va remplacer list.size()-1 par list.size()
    // et utiliser i-1 dans le corps de la boucle
	for (i= list.size() ; i > 0 ; i--) {
		std::cout << "elt " << i-1 << ": " << list[i-1] << std::endl;
	}

    //FAUTE: On ne doit pas libérer les éléments de la chaine un par un, on a fait un new char[]
    // on fait juste une delete[]
	// liberer les char de la chaine
	delete[] str;

}
