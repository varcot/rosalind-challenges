//Given: Positive integers n≤40 and k≤5.
//
//Return: The total number of rabbit pairs that will be present after n months, if we begin with 1 pair and in each generation,
// every pair of reproduction-age rabbits produces a litter of k rabbit pairs (instead of only 1 pair).

#include <iostream>
#include <fstream>

int main()
{
    int n;
    int k;
    std::fstream rabbit_file;
    rabbit_file.open("rosalind_fib.txt");
    rabbit_file >> n >> k;
    int a = 1;
    int b = 1;
    int next;
    n -= 2;
    while (n > 0){
        next = a + (b*k);
        b = a;
        a = next;
        n--;
    }
    std::cout << next << std::endl;
    return 0;
}
