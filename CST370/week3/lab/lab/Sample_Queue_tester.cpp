/*---------------------------------------------------------------------
 Driver program to test the Queue class.
 ----------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
using namespace std;

#include "Queue.h"

void processText(string txt, Queue & q);

int main()
{
    
    const string FULL_PATH = "/Users/Captain/Documents/development/workspace/school-work/CST370/week3/lab/lab/";
    const string FILE_IN = "sample.txt";
    string finalText = "", line;
    Queue notesStorage;
    ifstream inputFile;
    
    inputFile.open(FULL_PATH + FILE_IN, ios::in);
    
    if(!inputFile.is_open())
    {
        cerr << "Error opening file " + FILE_IN << endl;
        exit(1);
    }
    
    while ( getline(inputFile, line) )
    {
        finalText += line + "\n";
    }
    
    inputFile.close();
    
    processText(finalText, notesStorage);
    
    if(notesStorage.empty())
    {
        cout << "No special notes in text\n";
    }else
    {
        cout << "Special notes from text:\n";
        notesStorage.display(cout);
    }
}


void processText(string txt, Queue & q)
{
    const char OPENING_DELIMITOR = '{';
    const char CLOSING_DELIMITOR = '}';
    
    string note = "";
    bool openingFound = false;
    
    for(char c : txt)
    {
        
        if(c == OPENING_DELIMITOR)
        {
            openingFound = true;
        }
        else if(openingFound && c == CLOSING_DELIMITOR)
        {
            openingFound = false;
            q.enqueue(note);
            note = "";
        }
        else if(openingFound)
        {
            note += c;
        }
    }
}


