#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <cctype>
//#define tMax 256

using namespace std;
using namespace chrono;

void karpRabin(string pattern, const char inputText[], int primeInput);
int pow(int x, int n);
const char* rightLine(string file_path, string start_string, string end_string);
const int MAX = 1000000;

//Horner's rule a = coefficient, x = variable, n = degree
int pow(int x, int n, int prime) 
{
    int result = 1;
    for (int i = 0; i < n; i++) 
    {
        result = (result * x) % prime;
    }
    return result;
}

void karpRabin(string pattern, const char inputText[], int primeInput)
{
    auto start = high_resolution_clock::now();
    int pLen = pattern.size();
    int tLen = strlen(inputText);
    int pHash = 0;
    int tHash = 0;
    int count = 0;

    // compute pHash and tHash for the first window
    if (pLen == 1)
    {
        pHash = toupper(pattern[0]) % primeInput;
        tHash = toupper(inputText[0]) % primeInput;
        }
    else
    {
        for (int i = 0; i < pLen; i++)
        {
            pHash = (pHash * 256 + toupper(pattern[i])) % primeInput;
            tHash = (tHash * 256 + toupper(inputText[i])) % primeInput;
        }
    }


    // iterate over the rest of the text, one window at a time
    for (int i = 0; i <= tLen - pLen; i++)
    {
        // check if the hash value of the current window matches the hash value of the pattern
        if(pHash == tHash)
        {
            bool match = true;
            for (int j = 0; j < pLen; j++)
            {
                if (toupper(inputText[i+j]) != toupper(pattern[j]))
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                // check if the match is not a false positive
                if ((i == 0 || !isalnum(inputText[i-1])) && !isalnum(inputText[i+pLen]))
                {
                    //cout << "Pattern found at index " << i << endl;
                    count++;
                }
            }
        }

        // compute tHash for the next window
        if (i < tLen - pLen)
        {
            tHash = ((tHash - toupper(inputText[i]) * pow(256, pLen-1, primeInput)) * 256 + toupper(inputText[i+pLen])) % primeInput;
            if (tHash < 0)
            {
                tHash += primeInput;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto durationR = duration_cast<microseconds>(stop - start);

    cout << "Karp Rabin:" << endl;
    cout << "Number of occurrences in text is: " << count << endl;
    cout << "Time: " << durationR.count() << " microseconds" << endl << endl;
}

const char* rightLine(string file_path, string start_string, string end_string)
{
    char* content = new char[MAX];
    memset(content, 0, MAX);

    bool found_start_string = false;

    ifstream file(file_path);
    if (!file) {
        return "";
    }

    string line;
    while (getline(file, line)) {
        if (found_start_string) {
            if (line.find(end_string) != string::npos) {
                return content;
            } else {
                strcat(content, (line + "\n").c_str());
            }
        } else if (line.find(start_string) != string::npos) {
            found_start_string = true;
        }
    }

    return "";
}


int main()
{
    bool run = true;
    string filename = "test.txt";
    string pattern;
    ifstream infile;
    int flen;
    char in;
    while(run)
    {
            infile.open("test.txt", ios::in | ios::binary);
            if(infile && run == true)
            {
                const char* result = rightLine(filename, "IX. THE ADVENTURE OF THE ENGINEER'S THUMB", "X. THE ADVENTURE OF THE NOBLE BACHELOR");
                const char* text = rightLine(filename, "*** START OF THIS PROJECT GUTENBERG EBOOK THE ADVENTURES OF SHERLOCK HOLMES ***", "END OF THIS PROJECT GUTENBERG EBOOK THE ADVENTURES OF SHERLOCK HOLMES");
            //cout  << text;
                //cout << text;
                // infile.seekg(0, infile.end);
                // flen = infile.tellg();
                // infile.seekg(0,infile.beg);

                // //char text[flen];
                // infile.read(text, flen);

                infile.close();
                //cout << text;

                cout << "File Read Successfully" << endl << endl;

                cout << "Enter a pattern: ";
                cin >> pattern;

                int prime = 17;

                karpRabin(pattern, text, prime);
                cout << "THE ADVENTURE OF THE ENGINEER'S THUMB" << endl;
                karpRabin(pattern, result, prime);

                run = false;
            }
    }  
    return 0;
}