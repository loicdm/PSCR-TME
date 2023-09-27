#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>

int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("WarAndPeace.txt");


	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	// prochain mot lu
	string word;
    vector<pair<string,int>> word_list;

	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
        bool found = false;
        for (pair<string,int>& unique_word: word_list) {
            if (unique_word.first==word) {
                found = true;
                unique_word.second++;
                break;
            }
        }
        if (!found) {
            pair<string,int> word_pair;
            word_pair.first = word;
            word_pair.second = 1;
            word_list.emplace_back(word_pair);
            // word est maintenant "tout propre"
            if (word_list.size() % 100 == 0)
                // on affiche un mot "propre" sur 100
                cout << word_list.size() << ": "<< word << endl;
        }


	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << word_list.size() << " unique words." << endl;
    size_t war_occ = 0;
    size_t peace_occ = 0;
    size_t toto_occ = 0;
    for (pair<string,int>& unique_word: word_list) {
        if (unique_word.first=="war") {
            war_occ=unique_word.second;
        } else
        if (unique_word.first=="peace") {
            peace_occ=unique_word.second;
        } else
        if (unique_word.first=="toto") {
            toto_occ=unique_word.second;
        }
    }
    cout << "Found a total of " << war_occ << " occurrences of word war" << endl;
    cout << "Found a total of " << peace_occ << " occurrences of word peace." << endl;
    cout << "Found a total of " << toto_occ << " occurrences of word toto." << endl;
    return 0;
}


