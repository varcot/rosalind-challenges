//Given: A collection of at most 10 DNA strings of equal length (at most 1 kbp) in FASTA format.
//
//Return: A consensus string and profile matrix for the collection.
//(If several possible consensus strings exist, then you may return any one of them.)

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <utility>

int main()
{
    int index;                   //A variable that tracks which position in the DNA string we're at, needed thanks to FASTA
    int maxnuc = -1;                   //The variable to hold the largest amount of nucleotides at a given position
    char nucs[4] = {'A','C','G','T'};    //A reference table for each nucleotide, order is important
    char nuc_choice;                   //This will hold the char value corresponding to a nucleotide
    char lencalc = '0';         //A boolean value masquerading as a char; indicates whether strlen has been found
    int strlen = 0;             //variable to hold length of the dna strings
    std::string finstring;      //This will hold the consensus string
    //This map allows a quick association with a char value (nucleotide) and an integer indicating a matrix position
    std::unordered_map<char,int> lookup{{'A',0},{'C',1},{'G',2},{'T',3}};
    int profile[4][1000] = {{0},{0},{0},{0}};    //The 2-d array that represents the profile matrix that is built up
    std::string s;                               //A variable used to read lines from a file
    std::fstream dna_strings;                    //Our handy fstream object
    dna_strings.open("rosalind_cons.txt");
    if (dna_strings.is_open())
    {
        while (!dna_strings.eof())
        {
            getline(dna_strings,s);
            if (s[0] == '>')          //Needed for FASTA format handling, indicates start of new string
            {
                index = 0;            //The '>' means we're in a new DNA string so reset index
                if (strlen > 0)
                {
                    lencalc = '1';    //If we've already counted the string length, no need to do it again, set this to true
                }
            }else{
                for (long long unsigned int i = 0; i < s.length(); i++)
                {
                    //Takes the char value('A','C','G','T') at s[i] and passes that value to the unordered map "lookup"
                    //This gives an integer value that can provide the first value for accessing the 2-d profile matrix
                    //The second index comes from the "index" variable that has been incrementing for the duration
                    //of the dna string. The first index indicates the char, the second tells the position in the string
                    //This index is then incremented
                    profile[lookup[s[i]]][index] += 1;
                    index++;                             //increment index for each char in string
                    if (lencalc == '0')
                    {
                        strlen++;    //This is only done while we're calculating string length for the first time
                    }
                }
            }
        }
    }
    //The following nested for-loop finds the consensus string that will be used for output
    for (int i = 0; i < strlen; i++)
    {
        maxnuc = -1;                     //Re-intialize
        for (int j = 0; j < 4; j++)
        {
            if (profile[j][i] > maxnuc)
            {
                maxnuc = profile[j][i];    //The new largest value
                nuc_choice = nucs[j];      //Crucial to know which nucleotide the largest value belongs to
            }
        }
        finstring += nuc_choice;           //Add the lucky nucleotide to the string
    }
    std::cout << finstring << std::endl;   //output the consensus string

    //Now this nested for loop just outputs the profile matrix
    for (int i = 0; i < 4; i++)
    {
        std::cout << nucs[i] << ": ";
        for (int j = 0; j < strlen; j++)
        {
            std::cout << profile[i][j] << " ";
        }
        std::cout << " " << std::endl;
    }
    return 0;
}
