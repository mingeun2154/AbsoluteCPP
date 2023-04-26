/*
 * 2018203023
 * ch9.cpp
 */

#include "ch9.h"
#include "testfunctions.h"
#include <cctype>
#include <cstring>
#include <fstream>
#include <string>

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

	// 단어에 사용된 {문자: 개수} 반환
	map<char, int> countChar(const string word) {
		map<char, int> result;
		for(const auto& c: word)
			if (isalpha(c))
				result[tolower(c)]++;
		return result;
	}

	// m1이 m2를 포함하면 true, 아니면 false
	bool enclose(map<char, int> m1, map<char, int> m2) {
		if (m1.size() < m2.size())
			return false;
		for (const auto& iter: m2) {
			if (m1.find(iter.first)==m1.end())
				return false;
			else if (m1[iter.first] < iter.second)
				return false;
		}
		return true;
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
				if (isalpha(str[i+3]) && !isalpha(str[i+4])) {
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
				output += "he or she";
				// 구두점 조사
				if ((*iter).length() > 2) {
					for (int i=2; i<(*iter).length(); i++)
						output.push_back((*iter)[i]);
				}
				output.push_back(' ');
			}
			else if (removePunctuation(*iter).compare("He") == 0) {
				output += "He or she";
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
	 * word의 첫 번째 문자만 소문자이고 나머지는 모두 대문자이면 true, 
	 * 아니면 false 반환
	 */
	bool p7Check(const string word) {
		// 첫 문자 대문자 또는 길이가 1인 단어
		if (word[0]!=tolower(word[0]) || word.length()==1)
			return false;
		else {
			// 나머지 모든 문자가 대문자인 경우에만 true 반환
			int i = 1;
			while (i<word.length()){
				if (word[i]==tolower(word[i]))
					return false;
				i++;
			}
			return true;
		}
	}

	/*
	 * 단어의 첫 글자만 소문자이고 나머지는 모두 대문자인 단어를 선택적으로 출력한다.
	 * */
	void project7(const string str) {
		// Detect word
		int i = 0;
		vector<string> mistakes;
		vector<string> words = wordbreak(str);
		for (const auto& word: words)
			if (p7Check(word)) 
				mistakes.push_back(word);
		for (const auto& word: mistakes)
			cout << G << word << " ";
		cout << DEFAULT;
	}

	bool isvowel(char c) {
		c = tolower(c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		else
			return false;
	}

	/*
	 * Converts a sentence into the pig latin.
	 * */
	void project8(const string word) {
		string result;
		// b.The first charcater was a vowel
		if (isvowel(word[0]))
			result = word + "ay";
		// a.The first character was a consonant.
		else {
			for (int i=1; i<word.length(); i++)
				result.push_back(tolower(word[i]));
			result.push_back(word[0]);
			result += "ay";
		}
		cout << G << result << DEFAULT << endl;
	}

	// 두 문자열의 내용이 같으면 true 반환.
	// 대소문자, 구두점, 공백 무시
	bool isSameCstring(const char* s1, const char* s2) {
		int i=0, j=0;
		while (i<strlen(s1) && j<strlen(s2)) {
			if (!isalpha(s1[i]))
				i++;
			if (!isalpha(s2[j]))
				j++;
			if (isalpha(s1[i])&&isalpha(s2[j])) {
				if (tolower(s1[i])!=tolower(s2[j]))
					return false;
				i++;
				j++;
			}
		}
		return true;
	}

	void project9(const char* s1, const char* s2) {
		if (isSameCstring(s1, s2))	
			cout << G << "true" << DEFAULT;
		else
			cout << G << "false" << DEFAULT;
	}

	Trivia::Trivia(string q, string a, int w) {
		this->question = q;
		this->answer = a;
		this->worth = w;
	}

	Trivia::Trivia(Trivia& t) {
		this->question = t.question;
		this->answer = t.answer;
		this->worth = t.worth;
	}

	void project10() {
		// Prepare questions
		vector<Trivia*> quizes;
		quizes.push_back(new Trivia("What is the capital of Korea?", "Seoul", 10));
		quizes.push_back(new Trivia("What is the capital of Australia?", "Canberra", 10));
		quizes.push_back(new Trivia("What is the capital of Japan?", "Tokyo", 10));
		quizes.push_back(new Trivia("What is the capital of China?", "Beijing", 10));
		quizes.push_back(new Trivia("What is the capital of Egypt?", "Cairo", 10));
		int i=1;
		for (const auto& t: quizes) {
			printf("Question%d) ", i++);
			cout << t->getQuestion() << endl;
			string answer; // 사용자가 입력한 답
			string actual = t->getAnswer(); // 실제 정답
			cout << "Answer) ";
			cin >> answer;
			// 대소문자 무시(모두 소문자로 변환)
			for (auto& c: answer) 
				if (isalpha(c))
					c = tolower(c);
			for (auto& c: actual) 
				if (isalpha(c))
					c = tolower(c);
			if (answer == actual)
				cout << G << "Correct" << endl << DEFAULT;
			else
				cout << G << "Wrong. The correct answer is " << t->getAnswer() << endl << DEFAULT;
		}

		// release memories
		for (auto& ptr: quizes) {
			delete ptr;
			ptr = nullptr;
		}
	}

	/*
	 * Determines if two strings are anagrams.
	 * Disregard of case and punctuation or spaces.
	 * */
	void project11(const string s1, const string s2) {
		map<char, int> s1Chars = countChar(s1);
		map<char, int> s2Chars = countChar(s2);
		if (s1Chars == s2Chars)
			cout << G << "true" << DEFAULT;
		else
			cout << G << "false" << DEFAULT;
	}

	/*
	 * Converts a string into integer.
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
		cout << endl;
	}

	/*
	 * 사용자로부터 입력받은 단어의 알파벳으로 만들 수 있는
	 * words.txt의 모든 단어를 출력
	 * N = 87314
	 * */
	void project13(const string str) {
		// 파일에서 모든 단어를 읽어 벡터 형태로 저장
		ifstream inputFile("words.txt");
		vector<string> words;
		if (inputFile.is_open()) {
			string line;
			while (getline(inputFile, line)) {
				words.push_back(line);
			}
			inputFile.close();
		}
		else
			cout << R << "[ERROR] Unable to open file \"words.txt\"" << endl;
		// 사용자가 입력한 단어 분석
		map<char, int> inputInfo = countChar(str);
		// 파일에서 읽은 모든 단어 분석	
		map<string, map<char, int>> wordsInfo;
		for (const auto& iter : words)
			if (enclose(inputInfo, countChar(iter)))
				cout << G << iter << endl;
		cout << DEFAULT;
	}

};// Ch9

