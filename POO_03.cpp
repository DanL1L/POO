#include <iostream>
#include <string.h>
#include <string>
#include <cstring> 
#include <sstream>
#include <string>
using namespace std;
class Text
{
private:
	string *textArray;
	string text;
	int sentence = 0;
	int vowel = 0;
	int letter = 0;

public:
    Text() 
    {
	    sentence = 0;
		vowel = 0;
		letter = 0;
		text = " ";
    }

    int getSentence() { return sentence; }
    int getVowel() { return vowel; }
	int getLetter() { return letter; }
	string getText() { return text; }
 
	Text(const string& text)
	{
		this->text = text;
	}

public: int countSentences(string text)
	{
		for (int i = 0; i <= text.length(); i++)
		{

			if (text[i] == L'.' || text[i] == L'?' || text[i] == L'!')
			{
				sentence++;
			}
		}
		return sentence;
	}

public: int countWords(string text)
	{
		int count = 1;
		for (int i = 0; i < text.length() - 1; i++)
		{
			if (text[i] == ' ' && text[i + 1] != ' ')
			{
				count++;
			}
		}
		return count;
	}
public: int countLetters(string text)
	{
		for (int i = 0; i< text.length(); i++)
		{
			if (isalpha(text[i]))
			{
				letter++;
			}
		}
		return letter;
	}


public: int countVowels(string text)
	{
		for (int i = 0; i< text.length(); i++)
		{
			if (text[i] == L'A' || text[i] == L'a' || text[i] == L'E' || text[i] == L'e' || text[i] == L'I' || text[i] == L'i' || text[i] == L'O' || text[i] == L'o' || text[i] == L'U' || text[i] == L'u')
			{
				vowel++;
			}
		}
		return vowel;
	}

public: int countConsonants(string text)
	{
		return (countLetters(text) - countVowels(text)) / 2;
	}
public: string getFrequent(string text)
{
	return text;
}
public: string getLongest(string text)
{
	string::size_type max_size;
	string max_word;
	string word;
	istringstream is(text);
	max_size = 0;
	while (is >> word)
	{
		if (max_size < word.size())
		{
			max_size = word.size();
			max_word = word;
		}
		else if (max_size == word.size())
		{
			max_word += "; ";
			max_word += word;
		}
	}
	return max_word ;
}
};

int main()
{
	Text text;
	string str;
	cout << "\n\n\t---Basic Level---\n";
	cout << "\tIntroduceti textul:";
	getline(cin, str);
	cout << "\tNr. de propozitii:" << text.countSentences(str);
	cout << "\tNr. de cuvinte:" << text.countWords(str);

	cout << "\n\n\t---Advanced Level (1)---\n";
	cout << "\tLitere:" << text.countLetters(str);
	cout << "\tConsoane:" << text.countConsonants(str);
	cout << "\tVocale:" << text.countVowels(str);

	cout << "\n\n\t---Advanced Level (2)---\n";
	cout << "\tCel mai utilizat cuvint:" << text.getFrequent(str);
	cout << "\tCel mai lung cuvint:" << text.getLongest(str)<<endl;

}