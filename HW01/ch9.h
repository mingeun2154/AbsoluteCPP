/*
 * 2018203023
 * ch9.h
 */

#ifndef CH_9_H_
#define CH_9_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

namespace Ch9 {

	int countWords(string sentence);
	vector<string> wordbreak(const string sentence);
	string removePunctuation(string word);
	map<char, int> countChar(const string);
	bool enclose(map<char, int>, map<char, int>);
	bool p7Check(const string);


	string project1(const char*);
	void project2(const string);
	void project3(const string);
	void project4(string);
	void project5(const char str[101]);
	void project6(const string);
	void project7(const string);
	void project8(const string);
	void project9(const char*, const char*);
	void project10();
	void project11(const string, const string);
	void project12(const string);
	void project13(const string);

	class Trivia {
		private: 
			string question;
			string answer;
			int worth;
		public:
			Trivia();
			Trivia(string, string, int);
			Trivia(Trivia&);
			const string getQuestion() const { return question; }
			const string getAnswer() const { return answer; }
			int getWorth() { return worth; }
			void setQuestion(string q) { this->question = q; }
			void setAnswer(string a) { this->answer = a; }
			void setWorth(int w) { this->worth = w; }

	};// Trivia

};// Ch9

#endif// CH_9_H_
