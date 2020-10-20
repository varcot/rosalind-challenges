//Probability is the mathematical study of randomly occurring phenomena. We will model such a phenomenon with a random variable, which is simply a variable that can take a number of different distinct outcomes depending on the result of an underlying random process.
//
//For example, say that we have a bag containing 3 red balls and 2 blue balls. If we let X represent the random variable corresponding to the color of a drawn ball, then the probability of each of the two outcomes is given by Pr(X=red)=35 and Pr(X=blue)=25.
//
//Random variables can be combined to yield new random variables. Returning to the ball example, let Y model the color of a second ball drawn from the bag (without replacing the first ball). The probability of Y being red depends on whether the first ball was red or blue. To represent all outcomes of X and Y, we therefore use a probability tree diagram. This branching diagram represents all possible individual probabilities for X and Y, with outcomes at the endpoints ("leaves") of the tree. The probability of any outcome is given by the product of probabilities along the path from the beginning of the tree; see Figure 2 for an illustrative example.
//
//An event is simply a collection of outcomes. Because outcomes are distinct, the probability of an event can be written as the sum of the probabilities of its constituent outcomes. For our colored ball example, let A be the event "Y is blue." Pr(A) is equal to the sum of the probabilities of two different outcomes: Pr(X=blue and Y=blue)+Pr(X=red and Y=blue), or 310+110=25 (see Figure 2 above).
//
//Given: Three positive integers k, m, and n, representing a population containing k+m+n organisms: k individuals are homozygous dominant for a factor, m are heterozygous, and n are homozygous recessive.
//
//Return: The probability that two randomly selected mating organisms will produce an individual possessing a dominant allele (and thus displaying the dominant phenotype). Assume that any two organisms can mate.
#include <iostream>
#include <fstream>
#include <utility>

float prob_finder(std::pair<char,int>a,std::pair<char,int>b,float total)
{
    float prob;
    float factor = 1.0;
    if (a.first != 'K' && b.first != 'K'){
        if (a.first == 'M'&& b.first == 'M'){
            factor = .75;
        }else if ((a.first == 'M' && b.first == 'N')||(a.first == 'N' && b.first == 'M')){
            factor = .5;
        }else if (a.first == 'N' && b.first == 'N'){
            factor = 0.0;
        }
    }
    if (a.first == b.first){
        prob = factor *((a.second/total)*((b.second-1)/(total-1)));
    }else{
        prob = factor *((a.second/total)*((b.second)/(total-1)));
    }
    return prob;
}

int main()
{
    std::fstream dna_file;
    std::pair <char,int> k ('K',0);
    std::pair <char,int> m ('M',0);
    std::pair <char,int> n ('N',0);
    float total;
    float probsum;
    dna_file.open("rosalind_iprb.txt");
    dna_file >> k.second >> m.second >> n.second;
    std::pair <char,int> group[3] = {k,m,n};
    total = k.second + m.second + n.second;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            probsum += prob_finder(group[i],group[j],total);
        }
    }
    std::cout << probsum << std::endl;
    return 0;
}
