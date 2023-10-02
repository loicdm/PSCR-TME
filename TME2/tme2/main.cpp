#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <unordered_map>

int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("WarAndPeace.txt");


	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	// prochain mot lu
	string word;
    unordered_map<string, int> word_map(256);
    //vector<pair<string,int>> word_list;

	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
        // word est maintenant "tout propre"
        auto word_count = word_map.find(word);
        if (word_count!= word_map.end()) {
            (word_count->second)++;
            if (word_map.size() % 100 == 0)
                // on affiche un mot "propre" sur 100
                cout << word_map.size() << ": "<< word << endl;
        } else if (word_count == nullptr){
            word_map[word]=1;

        }
	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;

   // std::vector<pair<string,int>> word_list = vector<pair<string,int>>


	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";


    cout << "Found a total of " << word_map.size() << " unique words." << endl;

    auto query_list = {"war", "peace", "toto"};

    for (auto query: query_list) {
        auto result = word_map.find(query);
        cout << "Found a total of " << (result != nullptr ? result->second : 0) << " occurrences of word " << query << endl;
    }
    return 0;
}


