//In DNA strings, symbols 'A' and 'T' are complements of each other, as are 'C' and 'G'.
//
//The reverse complement of a DNA string s is the string sc formed by reversing the symbols of s, then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC").
//
//Given: A DNA string s of length at most 1000 bp.
//
//Return: The reverse complement sc of s.
#include <iostream>
#include <fstream>
#include <map>

char findComp(char nt)
{
   std::map<char,char> comps;
   comps['A']='T';
   comps['T']='A';
   comps['C']='G';
   comps['G']='C';
   return comps[nt];
}

void reverseStr(std::string& str)
{
    int n = str.length();
    for (int i = 0; i<(n/2); i++){
        std::swap(str[i],str[n-i-1]);
        str[i] = findComp(str[i]);
        str[n-i-1] = findComp(str[n-i-1]);
    }
}

int main()
{
    std::fstream dna_file;
    std::string dna;
    dna_file.open("rosalind_revc.txt");
    dna_file >> dna;
    //reverseStr(dna);
    std::map<char,char> comps;
    comps['A']='T';
    comps['T']='A';
    comps['C']='G';
    comps['G']='C';
    //std::string dna = "AAAACCCGGT";
    int n = dna.length();
    for (int i = 0; i<(n/2); i++){
        std::swap(dna[i],dna[n-i-1]);
        dna[i] = comps[dna[i]];
        dna[n-i-1] = comps[dna[n-i-1]];
    }
    std::cout << dna << std::endl;
    return 0;
}
