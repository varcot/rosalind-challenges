//Given two strings s and t of equal length, the Hamming distance between s and t, denoted dH(s,t), is the number of corresponding symbols that differ in s and t. See Figure 2.
//
//Given: Two DNA strings s and t of equal length (not exceeding 1 kbp).
//
//Return: The Hamming distance dH(s,t).
#include <iostream>
#include <fstream>

int main()
{
    std::fstream dna_file;
    std::string dna1;
    std::string dna2;
    dna_file.open("rosalind_hamm.txt");
    dna_file >> dna1 >> dna2;
    int hamming = 0;
    //std::string dna1 = "GAGCCTACTAACGGGAT";
    //std::string dna2 = "CATCGTAATGACGGCCT";
    for (long long unsigned int i = 0; i < dna1.length(); i++){
        if (dna1[i] != dna2[i]){
            hamming++;
        }
    }
    std::cout << hamming << std::endl;
    return 0;
}
