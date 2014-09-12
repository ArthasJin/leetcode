#include <iostream>
#include <unordered_map>

bool isIsomorphic(std::string first, std::string second) {
    if (first.length() != second.length()) {
        return false;
    }

    // One map to keep track of the characters in the
    // first string to the second string, another to keep
    // track of the characters in the second string to the first
    std::unordered_map<char, char> iso1;
    std::unordered_map<char, char> iso2;

    for (int i = 0; i < first.length(); i++) {
        char c1 = first[i];
        char c2 = second[i];

        // If the character already exists in the map,
        // check to make sure it's mapping to the same
        // character
        if (iso1.find(c1) != std::map::end) {
            if (iso1.at(c1) != c2) {
                return false;
            }
        } else {
            iso1.insert(std::pair<char, char>(c1, c2));
        }
        if (iso2.find(c2) != std::map::end) {
            if (iso2.at(c2) != c1) {
                return false;
            }
        } else {
            iso2.insert(std::pair<char, char>(c2, c1));
        }
    }
    return true;
}

