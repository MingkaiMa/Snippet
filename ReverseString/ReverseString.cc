#include <iostream>
#include <string>

using namespace std;

void reverseString(string& str, int start, int end){


	int left = start;
	int right = end;

	while(left < right){
		swap(str[left], str[right]);
		left++;
		right--;
	}
}

void reverseSentence(string& str){
	reverseString(str, 0, str.size() - 1);

	int index = 0;

	while(index < str.size()){
		while(str[index] == ' '){
			index++;
		}

		int end = index;
		while(end < str.size() && str[end] != ' ')
			end++;

		reverseString(str, index, end - 1);

		index = end;
	}
}

void reverseLeft(string& str, int pos){
	reverseString(str, 0, pos - 1);
	reverseString(str, pos, str.size() - 1);
	reverseString(str, 0, str.size() - 1);
}

int main(){
	//string str = "Ifuck am student";
	//reverseString(str, 1, 2);
	string str = "abcdefg";
	reverseLeft(str, 2);
	cout << str << endl;
}