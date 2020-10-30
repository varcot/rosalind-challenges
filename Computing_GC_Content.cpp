//In Rosalind's implementation, a string in FASTA format will be labeled by the ID "Rosalind_xxxx", where "xxxx" denotes
//a four-digit code between 0000 and 9999.
//
//Given: At most 10 DNA strings in FASTA format (of length at most 1 kbp each).
//
//Return: The ID of the string having the highest GC-content, followed by the GC-content of that string. Rosalind allows for
// a default error of 0.001 in all decimal answers unless otherwise stated; please see the note on absolute error below.

#include <iostream>
#include <fstream>
#include <utility>
#include <string>

int main()
{
    float gc_count;
    float total;
    std::string k;
    std::pair <std::string,float> max_pair("",0.0);
    std::pair <std::string,float> storage[10];
    int index = 0;
    std::fstream gc_file;
    gc_file.open("rosalind_gc.txt");
    if (gc_file.is_open())
    {
        while (!gc_file.eof())
        {
            getline(gc_file,k);
            if (k[0] == '>')
            {
                if (index == 0)
                {
                    storage[index] = std::make_pair(k.substr(1),0.0);
                    index++;
                }else
                {
                    storage[index-1].second = gc_count/total;
                    //std::cout << storage[index-1].first << " " << storage[index-1].second << std::endl;
                    if (storage[index-1].second > max_pair.second)
                    {
                        max_pair.first = storage[index-1].first;
                        max_pair.second = storage[index-1].second;
                    }
                    gc_count = 0.0;
                    total = 0.0;
                    storage[index] = std::make_pair(k.substr(1),0.0);
                    index++;
                }
            }else{
                total += k.length();
                for (long long unsigned int i = 0; i < k.length(); i++)
                {
                    if(k[i] == 'C' || k[i] == 'G')
                    {
                        gc_count++;
                    }
                }
            }
        }
        storage[index-1].second = gc_count/total;
        //std::cout << storage[index-1].first << " " << storage[index-1].second << std::endl;
        if (storage[index-1].second > max_pair.second)
        {
            max_pair.first = storage[index-1].first;
            max_pair.second = storage[index-1].second;
        }
        gc_count = 0.0;
        total = 0.0;
        gc_file.close();
    }
    std::cout << "Max pair is: " << max_pair.first << " " << max_pair.second*100.0 << std::endl;
    return 0;
}
