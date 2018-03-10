#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;



class LargeNumber
{
public:
    string large_num;
    LargeNumber(string n){
        large_num = n;
    }

    LargeNumber operator + (const LargeNumber& param){

        string str2 = param.large_num;
        long int len1 = large_num.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param
        vector<int> res(n_size + 1);

        int count = abs(len1 - len2);

        //cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == large_num.size()){
                op1[i] = large_num[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = large_num[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == str2.size()){
                op2[i] = str2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = str2[i - count] - '0';
            }
        }

        reverse(op1.begin(), op1.end());
        reverse(op2.begin(), op2.end());


//        for(int i = 0; i < n_size; i++){
//            cout << op1[i];
//        }
//        cout << "\n";
//
//        for(int i = 0; i < n_size; i++){
//            cout << op2[i];
//        }
//
//        cout << "\n";

        int carry = 0;

        for(int i = 0; i < n_size; i++){
            //res[i] = (op1[i] + op2[i]) % 10 + carry;
            res[i] = (op1[i] + op2[i] + carry) % 10;
            carry = (op1[i] + op2[i] + carry) / 10;
            if(i == n_size - 1 && carry != 0){
                res[n_size] = 1;
            }
            else if(i == n_size - 1 && carry == 0){
                res[n_size] = 0;
            }

        }

        reverse(res.begin(), res.end());


//
//        for(int i = 0; i < n_size + 1; i++){
//            cout << res[i];
//        }

//        cout << "\n";

        int flag = 1;
        string R;
        for(int i = 0; i < n_size + 1; i++){
            if(res[i] == 0 && flag == 1){
                continue;
            }
            else{
                R += to_string(res[i]);
                flag = 0;
            }
        }

        //string R = to_string(res[0]);
        //cout << R << "\n";
        LargeNumber r(R);
        return r;
    }


    LargeNumber operator - (const LargeNumber& param){

        string str2 = param.large_num;
        long int len1 = large_num.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param
        vector<int> res(n_size);

        int count = abs(len1 - len2);

        //cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == large_num.size()){
                op1[i] = large_num[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = large_num[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == str2.size()){
                op2[i] = str2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = str2[i - count] - '0';
            }
        }

        reverse(op1.begin(), op1.end());
        reverse(op2.begin(), op2.end());


//        for(int i = 0; i < n_size; i++){
//            cout << op1[i];
//        }
//        cout << "\n";
//
//        for(int i = 0; i < n_size; i++){
//            cout << op2[i];
//        }
//
//        cout << "\n";

        int carry = 0;

        for(int i = 0; i < n_size; i++){
            //res[i] = (op1[i] + op2[i]) % 10 + carry;

            if(op1[i] - carry >= op2[i]){
                res[i] = op1[i] - op2[i] - carry;
                carry = 0;
            }
            else if(op1[i] - carry < op2[i]){
                res[i] = op1[i] + 10 - op2[i] - carry;
                carry = 1;
            }
        }

        reverse(res.begin(), res.end());



//        for(int i = 0; i < n_size; i++){
//            cout << res[i] << ", ";
//        }
////
//        cout << "\n";




        int flag = 1;
        string R;
        for(int i = 0; i < n_size; i++){
            if(res[i] == 0 && flag == 1){
                continue;
            }
            else{
                R += to_string(res[i]);
                flag = 0;
            }
        }

        //string R = to_string(res[0]);
        //cout << "R is: " << R << "\n";

        if(R.length() == 0){
            LargeNumber r("0");
            return r;
        }
        LargeNumber r(R);
        return r;
    }


    LargeNumber operator * (const LargeNumber& param){

        string str2 = param.large_num;
        long int len1 = large_num.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param
        vector<int> res(len1 + len2);
        for(int i = 0; i < len1 + len2; i++){
            res[i] = 0;
        }

        int count = abs(len1 - len2);

        //cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == large_num.size()){
                op1[i] = large_num[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = large_num[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == str2.size()){
                op2[i] = str2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = str2[i - count] - '0';
            }
        }

        reverse(op1.begin(), op1.end());
        reverse(op2.begin(), op2.end());


//        for(int i = 0; i < n_size; i++){
//            cout << op1[i];
//        }
//        cout << "\n";
//
//        for(int i = 0; i < n_size; i++){
//            cout << op2[i];
//        }
//
//        cout << "\n";

        //int carry = 0;

        for(int i = 0; i < n_size; i++){
            for(int j = 0; j < n_size; j++){
                res[i + j] = res[i + j] + op1[i] * op2[j];
            }
        }


//        cout << "=====\n";
//        for(int i = 0; i < res.size(); i++){
//            cout << res[i] << ", ";
//        }

//        cout << "\n===" << res.size() << "\n";
//


        int carry = 0;
        for(int i = 0; i < res.size(); i++){
            int rr =res[i];
            res[i] = (res[i] + carry) % 10;
            //cout << "res is: " << res[i] << "\n";
            carry = (rr + carry) / 10;
            //cout << "carry is: " << carry << "\n";
        }

//        for(int i = 0; i < res.size(); i++){
//            cout << res[i] << ", ";
//        }
//        cout << "\nabove\n";

        reverse(res.begin(), res.end());

        int flag = 1;
        string R;
        for(int i = 0; i < res.size(); i++){
            if(res[i] == 0 && flag == 1){
                continue;
            }
            else{
                R += to_string(res[i]);
                flag = 0;
            }
        }

        if(R.length() == 0){
            LargeNumber r("0");
            return r;
        }

        //string R = to_string(res[0]);
        //cout << R << "\n";
        LargeNumber r(R);
        return r;
    }

    long int get_R(vector<int> R){

        string r = "";
        for(int i = 0; i < R.size(); i++){
            r += to_string(R[i]);
        }

        return stoi(r);

    }


    bool operator < (const LargeNumber& param){

        string str2 = param.large_num;
        long int len1 = large_num.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param

        int count = abs(len1 - len2);

        //cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == large_num.size()){
                op1[i] = large_num[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = large_num[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == str2.size()){
                op2[i] = str2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = str2[i - count] - '0';
            }
        }

//        for(int i = 0; i < n_size; i++){
//            cout << op1[i] << ", ";
//        }
//        cout << "\n";
//
//        for(int i = 0; i < n_size; i++){
//            cout << op2[i] << ", ";
//        }
//        cout << "\n";

        for(int i = 0; i < n_size; i++){


            if(op1[i] == op2[i]){
                continue;
            }
            else if(op1[i] < op2[i]){
                return true;
            }
            else if(op1[i] > op2[i]){
                return false;
            }
        }


        return true;
    }




    bool operator > (const LargeNumber& param){

        string str2 = param.large_num;
        long int len1 = large_num.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param

        int count = abs(len1 - len2);

//        cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == large_num.size()){
                op1[i] = large_num[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = large_num[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == str2.size()){
                op2[i] = str2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = str2[i - count] - '0';
            }
        }

//        for(int i = 0; i < n_size; i++){
//            cout << op1[i] << ", ";
//        }
//        cout << "\n";
//
//        for(int i = 0; i < n_size; i++){
//            cout << op2[i] << ", ";
//        }
//        cout << "\n";

        for(int i = 0; i < n_size; i++){


            if(op1[i] == op2[i]){
                continue;
            }
            else if(op1[i] > op2[i]){
                return true;
            }
            else{
                return false;
            }
        }


        return false;
    }




    bool operator == (const LargeNumber& param){

        string str2 = param.large_num;
        long int len1 = large_num.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param

        int count = abs(len1 - len2);

        //cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == large_num.size()){
                op1[i] = large_num[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = large_num[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == str2.size()){
                op2[i] = str2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = str2[i - count] - '0';
            }
        }

//        for(int i = 0; i < n_size; i++){
//            cout << op1[i] << ", ";
//        }
//        cout << "\n";
//
//        for(int i = 0; i < n_size; i++){
//            cout << op2[i] << ", ";
//        }
//        cout << "\n";

        for(int i = 0; i < n_size; i++){


            if(op1[i] == op2[i]){
                continue;
            }
            else{
                return false;
            }

        }


        return true;
    }




    LargeNumber operator / (const LargeNumber& param){

        LargeNumber dividend(large_num);
        LargeNumber divisor(param.large_num);

        if(dividend == divisor){
            LargeNumber quotient("1");
            return quotient;
        }

        if(dividend < divisor){
            LargeNumber quotient("0");
            return quotient;
        }

        vector<LargeNumber> difference;
        while(dividend > divisor || dividend == divisor)
        {
            //cout << "divident is: " << dividend.large_num << "\n";
            long int length_diff = dividend.large_num.length() - divisor.large_num.length();
            string ten_times = "1";
            int count_ten = 0;
            for(int i = 0; i < length_diff; i++){
                ten_times += '0';
                count_ten += 1;
            }

            //cout << "ten times is: " << ten_times << "\n";

            LargeNumber TEN_TIMES(ten_times);
            LargeNumber subrahend = TEN_TIMES * divisor;

            //cout << "subrahend is: " << subrahend.large_num << "\n";

            if(subrahend > dividend)
            {

                ten_times.pop_back();
                LargeNumber TEN_TIMES(ten_times);

                subrahend = TEN_TIMES * divisor;

            }

            //cout << "after check subrahend is: " << subrahend.large_num << "\n";
            int count = 0;
            while(dividend > subrahend || dividend == subrahend){
                //cout << "two while : dividend: " << dividend.large_num << "\n";
                dividend = dividend - subrahend;
                //cout << "two while : subrahend: " << subrahend.large_num << "\n";
                count += 1;
            }
            //cout << "after two while : dividend: " << dividend.large_num << "\n";

            //cout << "^^^^^^^^^\n";
            //cout << "count is: " << count << "\n";
            LargeNumber part_of_result (to_string(count));
            //cout << "part is: " << part_of_result.large_num << "\n";
            difference.push_back(part_of_result * ten_times);

        }


//        cout << "*********************************\n";
//
//        for(int i = 0; i < difference.size(); i++){
//            cout << difference[i].large_num << "\n";
//        }

        LargeNumber difference_result(difference[0].large_num);

        for(int i = 1; i < difference.size(); i++){
            difference_result = difference_result + difference[i];
        }

//        cout << difference_result.large_num << "\n";
//
//        cout << dividend.large_num << "\n";

        return difference_result;
    }




    LargeNumber operator % (const LargeNumber& param){

        LargeNumber dividend(large_num);
        LargeNumber divisor(param.large_num);

        if(dividend == divisor){
            LargeNumber quotient("0");
            return quotient;
        }

        if(dividend < divisor){
            return dividend;
        }

        vector<LargeNumber> difference;
        while(dividend > divisor || dividend == divisor)
        {
            //cout << "divident is: " << dividend.large_num << "\n";
            long int length_diff = dividend.large_num.length() - divisor.large_num.length();
            string ten_times = "1";
            for(int i = 0; i < length_diff; i++){
                ten_times += '0';
            }


            LargeNumber TEN_TIMES(ten_times);
            LargeNumber subrahend = TEN_TIMES * divisor;


            if(subrahend > dividend)
            {
                ten_times.pop_back();
                LargeNumber TEN_TIMES(ten_times);

                subrahend = TEN_TIMES * divisor;

            }

//            cout << "subrahend is: " << subrahend.large_num << "\n";

            int count = 0;
            while(dividend > subrahend || dividend == subrahend){
                dividend = dividend - subrahend;
                count += 1;
            }

            //cout << "^^^^^^^^^\n";
            //cout << "count is: " << count << "\n";
            LargeNumber part_of_result (to_string(count));
            //cout << "part is: " << part_of_result.large_num << "\n";
            difference.push_back(part_of_result * ten_times);

        }


//        cout << "*********************************\n";
//
//        for(int i = 0; i < difference.size(); i++){
//            cout << difference[i].large_num << "\n";
//        }

//        LargeNumber difference_result(difference[0].large_num);
//
//        for(int i = 1; i < difference.size(); i++){
//            difference_result = difference_result + difference[i];
//        }

        //cout << difference_result.large_num << "\n";

        //cout << dividend.large_num << "\n";

        return dividend;
    }


};

vector<string> divide_strings(string a, string b) {

    LargeNumber dividend(a);
    LargeNumber divisor(b);
    LargeNumber quotient = dividend / divisor;
    LargeNumber reminder = dividend % divisor;
    vector<string> R = {quotient.large_num, reminder.large_num};
    return R;

}




int main(){

//    LargeNumber x1("2666");
//    LargeNumber x2("2333");
//
//    LargeNumber x3 = x1 / x2;
//    cout << x3.large_num << "\n";

//    cout << "sdf\n";
//
//    cout << "\nmain============\n";
//    vector<string> s = divide_strings("600001", "100");
//    for(int i = 0; i < s.size(); i++){
//        cout << s[i] << "\n";
//    }

    LargeNumber x1("1020303004875647366210");
    LargeNumber x2("2774537626200857473632627613");
    //LargeNumber x1("123");
    //LargeNumber x2("23");
    LargeNumber x3 = x1 * x2;
    cout << x3.large_num << "\n";

//    LargeNumber x1("99");
//    LargeNumber x2("99");
//    LargeNumber x3 = x1 - x2;
//    cout << x3.large_num << "\n";

//    string s = "12345";
//
//    cout << s << "\n";
//
//    s.pop_back();
//
//    cout << s << "\n";
    //LargeNumber x3 = x1 * x2;
    //LargeNumber x4("28536");
    //LargeNumber x5 = x4 - x3;


    //cout << x5.large_num << "\n";

//    if(x1 == x2){
//        cout << "yes\n";
//    }
//    int n = 12345;
//    string nn = to_string(n);
//    cout << nn << "\n";
//    vector<int> R = {1,2,3};

    //x1.square_root();
   // cout << x1.get_R(R) << "\n";
//    LargeNumber x2("87654321");
//    //LargeNumber sum = x1 + x2;
//    //LargeNumber diff = x1 - x2;
//    LargeNumber product = x1 * x2;
//    cout << "\n\n\n";
//    cout << product.large_num << "\n";







}