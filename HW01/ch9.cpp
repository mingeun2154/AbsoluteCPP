/*
 * 2018203023
 * ch9.cpp
 */

#include "ch9.h"
#include "testfunctions.h"

namespace Ch9 {

	// 문장에서 단어의 개수를 반환
	int countWords(string str) {
		int count = 0;
		for (int i=0; i<str.length(); i++)
			if ((str[i]!=' '&&i==0)||(i>0&&str[i]!=' '&&str[i-1]==' ')) 
				count++;
		return count;
	}

	// 문장을 구성하는 단어를 벡터 형태로 반환
	vector<string> wordbreak(const string str) {
		vector<string> result;
		int i=0;
		while (i < str.length()) {
			if ((i==0&&isalpha(str[i])) || (i>0&&isalpha(str[i])&&str[i-1]==' ')) {
				string word;
				while (i<str.length() && str[i]!=' ')
					word.push_back(str[i++]);
				result.push_back(word);
			}
			i++;
		}
		return result;
	}

	// 구두점을 제거한 단어 반환
	// he, -> he
	string removePunctuation(string word) {
		string result = "";
		for (int i=0; i<word.length(); i++)
			if (!isalpha(word[i]))
				break;
			else
				result.push_back(word[i]);
		return result;
	}

	string project1(const char* str) {
		char result[101];
		int n = strlen(str);
		// 첫 글자 대문자로, 나머지 문자는 소문자로 변환
		bool isFirstChar = true;
		for (int i=0; i<n; i++) {
			if (str[i] != ' ' && isFirstChar) {
				result[i] = toupper(str[i]);
				isFirstChar = false;
			}
			else 
				result[i] = tolower(str[i]);
		}
		// 중복된 공백 제거
		int j = 0;
		for (int i=0; i<n; i++)
			if (str[i] != ' ' || (i>0 && str[i-1]!=' '))
				result[j++] = result[i];
		result[j] = '\0';
		return static_cast<string>(result);
	}

	/*
	 * Output the number of words in the line and the number
	 * of occureences of each letter.
	 * I say Hi.
	 */
	void project2(const string str) {
		map<char, int> occurrences;
		// count words
		int wordCount = 0;
		wordCount = countWords(str);
		// count each character
		char a = 'a', z = 'z', A = 'A', Z = 'Z';
		for (char c : str) {
			c = tolower(c);
			if ((a<=c && c<=z) || (A<=c && c<=Z)) {
				if (occurrences.find(c)!=occurrences.end())
					occurrences[c] += 1;
				else
					occurrences[c] = 1;
			}
		}
		// output
		cout << G;
		cout << "words: " << wordCount << endl;
		for (auto iter = occurrences.begin(); iter!=occurrences.end(); ++iter)
			cout << iter->first << " : " << iter->second  << endl;
		cout << DEFAULT;
	}

	/*
	 * first name, middle name (or initial), last name
	 * -> last name, first name, middle initial
	 * Marry Average User -> User, A. Marry
	 * Marry User -> User, Marry (no middle name)
	 */
	void project3(string input) {
		int count = countWords(input);
		string first, middle, last;
		// first name, middle name, last name
		if (count == 3) {
			int i = 0;
			// first name
			while (input[i] != ' ') {
				if (input[i] != '.')
					first.push_back(input[i]);
				i++;
			}
			while (input[++i] == ' ') {}
			// middle name
			while (input[i] != ' ') {
				middle.push_back(input[i]);
				i++;
			}
			while (input[++i] == ' ') {}
			// middle name
			while (i < input.length() && input[i] != ' ') {
				last.push_back(input[i]);
				i++;
			}
			cout << G << last << ", " << first << " " << middle[0] << ". " << DEFAULT;
		}
		// first name, last name
		if (count == 2) {
			int i = 0;
			// first name
			while (input[i] != ' ') {
				if (input[i] != '.')
					first.push_back(input[i]);
				i++;
			}
			while (input[++i] == ' ') {}
			// last name
			while (i < input.length() && input[i] != ' ') {
				last.push_back(input[i]);
				i++;
			}
			cout << G << last << ", " << first << DEFAULT;
		}
	}

	/*
	 * replaces all four-letter words with the word "love"
	 * John will run home. -> Love love run love.
	 * */
	void project4(string str) {
		int i=0;
		while (i < str.length()) {
			// 각 단어의 첫 문자를 만난 경우
			if ((i==0 && str[i] !=' ')||(i>0 && str[i]!=' ' && str[i-1]==' '))
				// 해당 단어의 길이가 4
				if (isalpha(str[i+3]) && str[i+4]==' ') {
					// four-letter word가 소문자로 시작
					if ('a' <= str[i] && str[i]<='z' )
						str.replace(i, 4, "love");
					else
						str.replace(i, 4, "Love");
					i += 3;
				}
			i+=1;
		}
		cout << G << str << DEFAULT;
	}

	/*
	 * preserve uppercase
	 * he -> he or she
	 * his -> her(s)
	 * */
	void project5(const char str[101]) {
		vector<string> words = wordbreak(str);
		string output = "";
		for (auto iter=words.begin(); iter!=words.end(); ++iter) {
			if (removePunctuation(*iter).compare("he") == 0) {
				output += "he";
				// 구두점 조사
				if ((*iter).length() > 2) {
					for (int i=2; i<(*iter).length(); i++)
						output.push_back((*iter)[i]);
				}
				output.push_back(' ');
			}
			else if (removePunctuation(*iter).compare("He") == 0) {
				output += "He";
				// 구두점 조사
				if ((*iter).length() > 2) {
					for (int i=2; i<(*iter).length(); i++)
						output.push_back((*iter)[i]);
				}
				output.push_back(' ');
			}
			else if (removePunctuation(*iter).compare("his")==0) {
				output += "her(s)";
				// 구두점 조사
				if ((*iter).length() > 3) {
					for (int i=3; i<(*iter).length(); i++)
						output.push_back((*iter)[i]);
				}
				output.push_back(' ');
			}
			else if (removePunctuation(*iter).compare("His")==0) {
				output += "Her(s)";
				// 구두점 조사
				if ((*iter).length() > 3) {
					for (int i=3; i<(*iter).length(); i++)
						output.push_back((*iter)[i]);
				}
				output.push_back(' ');
			}
			else if (removePunctuation(*iter).compare("him")==0) {
				output += "her or him";
				// 구두점 조사
				if ((*iter).length() > 3) {
					for (int i=3; i<(*iter).length(); i++)
						output.push_back((*iter)[i]);
				}
				output.push_back(' ');
			}
			else if (removePunctuation(*iter).compare("Him")==0) {
				output += "Her or him";
				// 구두점 조사
				if ((*iter).length() > 3) {
					for (int i=3; i<(*iter).length(); i++)
						output.push_back((*iter)[i]);
				}
				output.push_back(' ');
			}
			else
				output += *iter + " ";
		}
		cout << G << output << DEFAULT;
	}

	/*
	 * converts a string into integer
	 * 1234
	 * -1234
	 * */
	void project12(const string str) {
		int result = 0;
		int sign = 1;
		int digit = str.length()-1;
		for (int i=0; i<str.length(); i++) {
			if (i==0&&str[i]=='-') {
				sign = -1;
				digit--;
				continue;
			}
			result += static_cast<int>(pow(10, digit)) * (str[i]-'0');
			digit--;
		}
		result = sign*result;
		cout << G << result << DEFAULT;
	}

};// Ch9

