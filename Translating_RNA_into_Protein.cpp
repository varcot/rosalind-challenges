//Given: An RNA string s corresponding to a strand of mRNA (of length at most 10 kbp).
//
//Return: The protein string encoded by s.

#include <iostream>
#include <fstream>
#include <unordered_map>

int main()
{
    //'B' is char representation of a stop codon
    std::unordered_map<std::string,char> codon_table{
        {"UUU",'F'},{"UUC",'F'},{"UUA",'L'},{"UUG",'L'},{"UCU",'S'},{"UCC",'S'},{"UCA",'S'},{"UCG",'S'},
        {"UAU",'Y'},{"UAC",'Y'},{"UAA",' '},{"UAG",' '},{"UGU",'C'},{"UGC",'C'},{"UGA",' '},{"UGG",'W'},
        {"CUU",'L'},{"CUC",'L'},{"CUA",'L'},{"CUG",'L'},{"CCU",'P'},{"CCC",'P'},{"CCA",'P'},{"CCG",'P'},
        {"CAU",'H'},{"CAC",'H'},{"CAA",'Q'},{"CAG",'Q'},{"CGU",'R'},{"CGC",'R'},{"CGA",'R'},{"CGG",'R'},
        {"AUU",'I'},{"AUC",'I'},{"AUA",'I'},{"AUG",'M'},{"ACU",'T'},{"ACC",'T'},{"ACA",'T'},{"ACG",'T'},
        {"AAU",'N'},{"AAC",'N'},{"AAA",'K'},{"AAG",'K'},{"AGU",'S'},{"AGC",'S'},{"AGA",'R'},{"AGG",'R'},
        {"GUU",'V'},{"GUC",'V'},{"GUA",'V'},{"GUG",'V'},{"GCU",'A'},{"GCC",'A'},{"GCA",'A'},{"GCG",'A'},
        {"GAU",'D'},{"GAC",'D'},{"GAA",'E'},{"GAG",'E'},{"GGU",'G'},{"GGC",'G'},{"GGA",'G'},{"GGG",'G'},
    };
    std::fstream rna_file;
    rna_file.open("rosalind_prot.txt");
    //std::string rna = "AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA";
    std::string rna;
    rna_file >> rna;
    std::string prot_string = "";
    std::string accum = "";
    for (long long unsigned int i = 0; i < rna.length(); i += 3)
    {
        accum = rna.substr(i,3);
        prot_string += codon_table[accum];
    }
    std::cout << prot_string << std::endl;
    return 0;
}
