//A string is simply an ordered collection of symbols selected from some alphabet and formed into a word; the length of a string is the number of symbols that it contains.
//
//An example of a length 21 DNA string (whose alphabet contains the symbols 'A', 'C', 'G', and 'T') is "ATGCTTCAGAAAGGTCTTACG."
//
//Given: A DNA string s of length at most 1000 nt.
//
//Return: Four integers (separated by spaces) counting the respective number of times that the symbols 'A', 'C', 'G', and 'T' occur in s.
#include <iostream>
#include <fstream>

int main()
{
    int num_adenine = 0;
    int num_cytosine = 0;
    int num_guanine = 0;
    int num_thymine = 0;
    std::fstream dna_file;
    std::string dna;
    dna_file.open("rosalind_dna.txt");
    dna_file >> dna;
    for (long long unsigned int i=0; i<dna.length(); i++){
        switch (dna[i]){
            case 'A':
                num_adenine += 1;
            h    break;
            case 'C':
                num_cytosine += 1;
                break;
            case 'G':
                num_guanine += 1;
                break;
            case 'T':
                num_thymine += 1;
                break;
        }
    }
    std::cout << num_adenine << " " << num_cytosine << " " << num_guanine << " " << num_thymine << std::endl;
    return 0;
}
