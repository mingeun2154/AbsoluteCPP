/*
 * 2018203023
 * ch9.cpp
 */

#include "ch9.h"

namespace Ch9 {

	string fixString(const char* str) {
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

};// Ch9

