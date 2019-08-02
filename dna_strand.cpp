#include <iostream>

// program to read in and test validity of DNA sequence
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;
string read_data (string&);
bool isvaliddna ( string&);
void print_occurs(  string &, string &);

ofstream outputfile("DNAoutput.txt");

int main()
{
    string DNAsequence;
    string motif;
    read_data(DNAsequence);
    isvaliddna(DNAsequence);

    cout << "Enter the motif to be searched in DNA sequence: ";

    cin >> motif;
    outputfile<< "The DNA motif you entered is: "<<motif<<endl;

    if (isvaliddna(DNAsequence))
             print_occurs(DNAsequence,motif);
    else
        outputfile<< "Your DNA sequence is invalid";

    outputfile.close();
    return 0;
}
/**
Input: lines of 65 characters
Process: the functions reads in each line and concatenation each line to the last
Output: the DNA sequence is formed from the linked characters
**/


string read_data(string&DNA)
{
     fstream myinfile;
     myinfile.open("DNA Input.txt");
     if (!myinfile) {
        cout << "file does not exist! Program will exit.";
        exit(1);
    }
    string line;
    while(getline(myinfile,line)&& !line.empty())
         DNA += line;

    cout << " DNA Sequence: " <<DNA;
    outputfile<< " DNA Sequence: " <<DNA;
    outputfile<<endl;
      myinfile.close();
 return DNA;
}

/**
Input:The DNA sequence after concatenating
Process:The function test if the sequence is a valid DNA sequence
Output:The DNA sequence should be validated and continue
**/
bool isvaliddna( string& sequence)
{
     for (int i=0; i<sequence.length();i++)
         if (sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'T' && sequence[i] != 'N')
               return false;
     else
        return true;
}

/**
Input:The  DNA sequence and motif
Process:the sequence is searched for the motif
Output:the position and number of motifs present is printed
**/
void print_occurs(string& sequence,string& motif)
{
        string::size_type index;
        int motifPresent=0;
        index=sequence.find(motif);
       outputfile << "The motif is located at position(s): ";
       if(index==string::npos)
             outputfile << "The motif was not found";

    while (index !=string::npos){
            outputfile << index<< " ";
     index=sequence.find(motif,index+1);
     motifPresent++;
    }
         outputfile<<endl;
     outputfile << "The number of copies for the motifs in the sequence is: " << motifPresent<<endl;

    return;
}