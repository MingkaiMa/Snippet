#include <iostream>

using namespace std;

struct HuffmanTreeNode {
   unsigned char data;
   int freq;
   HuffmanTreeNode* left;
   HuffmanTreeNode* right;
   HuffmanTreeNode(unsigned char d, int f): data(d), freq(f), left(nullptr), right(nullptr) {}
   HuffmanTreeNode(): data('0'), freq(0), left(nullptr), right(nullptr) {}
};


int main(){

	char x[6];
	cout << "size of array x: " << sizeof(x) << endl;
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of char* :" << sizeof(char*) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of int*: " << sizeof(int*) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

   HuffmanTreeNode* node = new HuffmanTreeNode();
   cout << "Size of node: " << sizeof(node) << endl;

   cout << INT_MAX << endl;
   
   return 0;
}
