/*
  Part A asks user for a cin sentences. The program then splits up the sentence into words and search to see if they are in the files. if they are in the given word file. As long as the sentence follows a rule it will return the rule
  otherwise it will return as  illegal sentence.
  
  
  TESTING:
  Rule 1:
  	people is people - correct
  	map has world - correct
  	people has art - correct
  Rule 2:
  	two know every person - correct
  	computer want important theory  - correct
  Rule 3:
  	i has problem  - correct
  	i provide power - correct
  Rule 4:
  	i has large art - correct
  	i choose large data - correct
  Rule 5: 
  	i is is - correct
  	who become i - correct
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool noun(string w1); // defining boolean
bool noun3(string w3);
bool noun4(string w4);
bool pronoun(string w1);
bool pronoun3(string w3);
bool verb(string w2);
bool adjective(string w3);
 
int main() {
	string sent;
	string w1, w2, w3, w4, w5;
	int p1, p2, p3, p4;
	
	cout << "Please enter a sentence" << endl; //asks for sentence
	getline(cin, sent); //store
	cout << "sentence is: "<< sent << endl; //repeat sentence
	
	
//loops for finding word pos	
	
	while ((sent[p1] != ' ') && (p1 < sent.length()))   //this starts to set w1 string to all letters up to untill p1 hits a space
	{
			w1 += sent[p1];
			p1++;
	}
	cout <<"word 1 is: " << w1 << endl;
	p2 = p1 + 1; //add one to skip space
	if (p1 < sent.length()){
		while ((sent[p2] != ' ') && (p2 < sent.length())) //loop to set string w2 to all letters up till space
		{
				w2 += sent[p2];
				p2++;
		}
	cout <<"word 2 is: " << w2 << endl;
	}
	p3 = p2 + 1; //add one to skip space
	if (p2 < sent.length()){
		while ((sent[p3] != ' ') && (p3 < sent.length())) //loop to set string w3 to all letters up till space
		{
				w3 += sent[p3];
				p3++;
		}
	cout <<"word 3 is: " << w3 << endl;
	}
	p4 = p3 + 1; //add one to skip space
	if (p3 < sent.length()){
  		while ((sent[p4] != ' ') && (p4 < sent.length())) //loop to set string w4 to all letters up till space and only couts "word 4" if there is word 4
		{
			w4 += sent[p4];
			p4++;
    	}
	cout <<"word 4 is: " << w4 << endl;
	}

// defining sentence rules
	
	if((noun(w1) == true) && (verb(w2) == true) && (noun3(w3) == true) && (w4.empty()))  //rule 1 noun/verb/noun
	{
		cout << "Your sentence is a legal sentence by rule 1" << endl;	
	}	
	else if((noun(w1) == true) && (verb(w2) == true) && (adjective(w3) == true) && (noun4(w4) == true) && (w5.empty())) //rule 2 noun/verb/adjective/noun
	{
		cout << "Your sentence is a legal sentence by rule 2" << endl;	
	}
	else if((pronoun(w1) == true) && (verb(w2) == true) &&  (noun3(w3) == true) && (w4.empty()))  //rule 3 pronoun/verb/noun
	{
		cout << "Your sentence is a legal sentence by rule 3" << endl;	
	}
	else if((pronoun(w1) == true) && (verb(w2) == true) && (adjective(w3) == true) && (noun4(w4) == true) && (w5.empty())) //rule 4 pronoun/verb/adjective/noun
	{
		cout << "Your sentence is a legal sentence by rule 4" << endl;	
	}
	else if((pronoun(w1) == true) && (verb(w2) == true) && (pronoun3(w3) == true) && (w4.empty())) //rule 5 pronoun/verb/pronoun
	{
		cout << "Your sentence is a legal sentence by rule 5" << endl;	
	}
	else 
	{
		cout << "Your sentence is not a legal sentence." << endl; // if sentence doesnt fit rule it is illegal
	}


}

bool noun(string w1)  // boolean to check for noun in word 1
{
	bool valid = false;
	string checknoun;
	ifstream nounfile;
	nounfile.open("nouns");
	while (nounfile >> checknoun)
	{
		if (checknoun == w1)
		{
			valid = true;
		}
	}
	nounfile.close();
	return valid;
}

bool noun3(string w3) // boolean to check for noun in word 3
{
	bool valid = false;
	string checknoun;
	ifstream nounfile;
	nounfile.open("nouns");
	while (nounfile >> checknoun)
	{
		if (checknoun == w3)
		{
			valid = true;
		}
	}
	nounfile.close();
	return valid;
}

bool noun4(string w4) // boolean to check for noun in word 4
{
	bool valid = false;
	string checknoun;
	ifstream nounfile;
	nounfile.open("nouns");
	while (nounfile >> checknoun)
	{
		if (checknoun == w4)
		{
			valid = true;
		}
	}
	nounfile.close();
	return valid;
}

bool pronoun(string w1) // boolean to check for pronoun in word 1
{
	bool valid = false;
	string checkpronoun;
	ifstream pronounfile;
	pronounfile.open("pronouns");
	while (pronounfile >> checkpronoun)
	{
		if (checkpronoun == w1)
		{
			valid = true;
		}
	}
	pronounfile.close();
	return valid;
}

bool pronoun3(string w3) // boolean to check for pronoun in word 3
{
	bool valid = false;
	string checkpronoun;
	ifstream pronounfile;
	pronounfile.open("pronouns");
	while (pronounfile >> checkpronoun)
	{
		if (checkpronoun == w3)
		{
			valid = true;
		}
	}
	pronounfile.close();
	return valid;
}

bool verb(string w2) // boolean to check for verb in word 2
{
	bool valid = false;
	string checkverb;
	ifstream verbfile;
	verbfile.open("verbs");
	while (verbfile >> checkverb)
	{
		if (checkverb == w2)
		{
			valid = true;
		}
	}
	verbfile.close();
	return valid;
}

bool adjective(string w3) // boolean to check for adjective in word 3
{
	bool valid = false;
	string checkadjective;
	ifstream adjectivefile;
	adjectivefile.open("adjectives");
	while (adjectivefile >> checkadjective)
	{
		if (checkadjective == w3)
		{
			valid = true;
		}
	}
	adjectivefile.close();
	return valid;
}

