//Given: Two DNA strings s and t (each of length at most 1 kbp).
//
//Return: All locations of t as a substring of s.

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string s;
    std::string t;
    std::fstream dna_file;
    dna_file.open("rosalind_subs.txt");
    dna_file >> s >> t;
    //std:: cout << s << std::endl;
    //std:: cout << "This is t: " << t << std::endl;
    std::string locations = "";
    for (long long unsigned int i = 0; i < s.length(); i++)
    {
        if (s.substr(i,t.length()) == t)
        {
            locations += std::to_string(i+1);
            locations += " ";
        }
    }
    std::cout << locations << std::endl;
    return 0;
}
