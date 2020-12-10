//Given: Six nonnegative integers, each of which does not exceed 20,000. The integers correspond to the number of couples
// in a population possessing each genotype pairing for a given factor. In order, the six given integers represent the
// number of couples having the following genotypes:
//
//AA-AA
//AA-Aa
//AA-aa
//Aa-Aa
//Aa-aa
//aa-aa
//
//Return: The expected number of offspring displaying the dominant phenotype in the next generation, under the assumption
// that every couple has exactly two offspring.

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    int arrsize = 6;
    //float total = 0.0;
    //float num = 2.0;
    float seq[arrsize];
    //float weights[arrsize] = {1.0, 1.0, 1.0, .75, .5, 0.0};
    std::string temp;
    std::fstream num_seq;                    //Our handy fstream object
    num_seq.open("rosalind_iev.txt");
    if (num_seq.is_open())
    {
        for (int i = 0; i < arrsize; i++)
        {
            num_seq >> temp;
            seq[i] = std::stoi(temp);
        }
    }
//    for (int i = 0; i < arrsize; i++)
//    {
//        std::cout << seq[i]*num*weights[i] << std::endl;
//        total += seq[i]*num*weights[i];
//        std::cout << total << std::endl;
//    }
    std::cout <<std::fixed << std::setprecision(1) << (2.0 * (seq[0]+seq[1]+seq[2]) + 1.5 * (seq[3]) + seq[4]) << std::endl;
    //std::cout << std::setprecision(1) << total << std::endl;
    return 0;
}
