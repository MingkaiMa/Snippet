#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> divide_strings(string a, string b) {

    vector<char> result(a.length());
    int bb = 0;
    long long int d = stoi(b);

    for(int i = 0; i < a.length(); i++){

        bb = bb * 10 + a[i] - '0';
        cout << "bb is: " << bb << "\n";
        result[i] = bb / d + '0';
        bb = bb % d;
        cout << "after bb is: " << bb << "\n";
    }

    string R = "";

    int k = 0;
    while(result[k] == '0'){
        k += 1;
    }



    for( ; k < a.length(); k++){

        R += result[k];

        //cout << result[i] << ", ";
    }

    if(R.length() == 0){
        R += '0';
    }

//    cout << "\n";
//    cout << R << "\n";
//    cout << "\n";


    //cout << "quotient is: " << bb << "\n";

    string quotient = to_string(bb);
    //cout << quotient << "\n";

    vector<string> L = {R, quotient};
    return L;

}

int main(){

    vector<string> s = divide_strings("9223372036854775807", "2147483647");

    cout << "*****************\n";
    cout << s[0] << "\n";
    cout << s[1] << "\n";


}