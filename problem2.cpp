//An RNA string is a string formed from the alphabet containing 'A', 'C', 'G', and 'U'.
//
//Given a DNA string t corresponding to a coding strand, its transcribed RNA string u is formed by replacing all occurrences of 'T' in t with 'U' in u.
//
//Given: A DNA string t having length at most 1000 nt.
//
//Return: The transcribed RNA string of t.
#include <iostream>
#include <fstream>

int main()
{
    std::fstream dna_file;
    std::string dna;
    dna_file.open("rosalind_rna.txt");
    dna_file >> dna;
    //std::string dna = "GATGGAACTTGACTACGTAAATT";
    //std::string rna;
    for (long long unsigned int i=0; i<dna.length(); i++){
        if (dna[i] == 'T'){
            dna[i] = 'U';
        }
    }
    std::cout << dna << std::endl;

    return 0;
}
