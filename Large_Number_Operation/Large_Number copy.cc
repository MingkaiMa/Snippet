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

        cout << "count is: " << count << "\n";
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


        for(int i = 0; i < n_size; i++){
            cout << op1[i];
        }
        cout << "\n";

        for(int i = 0; i < n_size; i++){
            cout << op2[i];
        }

        cout << "\n";

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



        for(int i = 0; i < n_size + 1; i++){
            cout << res[i];
        }

        cout << "\n";

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
        cout << R << "\n";
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

        cout << "count is: " << count << "\n";
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


        for(int i = 0; i < n_size; i++){
            cout << op1[i];
        }
        cout << "\n";

        for(int i = 0; i < n_size; i++){
            cout << op2[i];
        }

        cout << "\n";

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



        for(int i = 0; i < n_size; i++){
            cout << res[i];
        }

        cout << "\n";

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
        cout << R << "\n";
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

        cout << "count is: " << count << "\n";
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


        for(int i = 0; i < n_size; i++){
            cout << op1[i];
        }
        cout << "\n";

        for(int i = 0; i < n_size; i++){
            cout << op2[i];
        }

        cout << "\n";

        //int carry = 0;

        for(int i = 0; i < n_size; i++){
            for(int j = 0; j < n_size; j++){
                res[i + j] = res[i + j] + op1[i] * op2[j];
            }
        }
        //reverse(res.begin(), res.end());

        cout << "=====\n";
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << ", ";
        }

        cout << "\n===" << res.size() << "\n";



        int carry = 0;
        for(int i = 0; i < res.size(); i++){
            int rr =res[i];
            res[i] = (res[i] + carry) % 10;
            cout << "res is: " << res[i] << "\n";
            carry = (rr + carry) / 10;
            cout << "carry is: " << carry << "\n";
        }

        for(int i = 0; i < res.size(); i++){
            cout << res[i] << ", ";
        }
        cout << "\nabove\n";

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

        //string R = to_string(res[0]);
        cout << R << "\n";
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

        cout << "count is: " << count << "\n";
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

        for(int i = 0; i < n_size; i++){
            cout << op1[i] << ", ";
        }
        cout << "\n";

        for(int i = 0; i < n_size; i++){
            cout << op2[i] << ", ";
        }
        cout << "\n";

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

        cout << "count is: " << count << "\n";
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

        for(int i = 0; i < n_size; i++){
            cout << op1[i] << ", ";
        }
        cout << "\n";

        for(int i = 0; i < n_size; i++){
            cout << op2[i] << ", ";
        }
        cout << "\n";

        for(int i = 0; i < n_size; i++){


            if(op1[i] == op2[i]){
                continue;
            }
            else if(op1[i] > op2[i]){
                return true;
            }
            else if(op1[i] < op2[i]){
                return false;
            }
        }


        return true;
    }




    bool operator == (const LargeNumber& param){

        string str2 = param.large_num;
        long int len1 = large_num.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param

        int count = abs(len1 - len2);

        cout << "count is: " << count << "\n";
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

        for(int i = 0; i < n_size; i++){
            cout << op1[i] << ", ";
        }
        cout << "\n";

        for(int i = 0; i < n_size; i++){
            cout << op2[i] << ", ";
        }
        cout << "\n";

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
        while(dividend > divisor)
        {
            long int length_diff = dividend.large_num.length() - divisor.large_num.length();
            string ten_times = "1";
            for(int i = 0; i < length_diff; i++){
                ten_times += '0';
            }


            LargeNumber TEN_TIMES(ten_times);
            LargeNumber subrahend = TEN_TIMES * divisor;

            int count = 0;
            while(dividend > subrahend){
                dividend = dividend - subrahend;
                count += 1;
            }

            cout << "^^^^^^^^^\n";
            cout << "count is: " << count << "\n";
            LargeNumber part_of_result (to_string(count));
            cout << "part is: " << part_of_result.large_num << "\n";
            difference.push_back(part_of_result * ten_times);

        }


        cout << "*********************************\n";

        for(int i = 0; i < difference.size(); i++){
            cout << difference[i].large_num << "\n";
        }

        LargeNumber rr("123");
        return rr;
    }





//    void square_root(){
//
//        long int len1 = large_num.length();
//
//        int len2 = 0;
//        if(len1 % 2 == 0){
//            len2 = len1 / 2;
//        }
//        else{
//            len2 = (len1 / 2) + 1;
//        }
//
//
//        cout << "len2 is: " << len2 << "\n";
//        vector<int> num(len2);
//
//        if(len1 % 2 == 0){
//            for(int i = 0; i < len2; i++){
//                string temp_string = "";
//                temp_string += large_num[2 * i];
//                temp_string += large_num[2 * i + 1];
//                num[i] = stoi(temp_string);
//            }
//        }
//        else{
//            cout << "come here\n";
//            num[0] = large_num[0] - '0';
//            for(int i = 1; i < len2; i++){
//                string temp_string = "";
//                temp_string += large_num[2 * i - 1];
//                cout << large_num[2 * i - 1];
//
//                temp_string += large_num[2 * i];
//                cout << ":" << temp_string << "\n";
//                num[i] = stoi(temp_string);
//            }
//
//        }
//
//
//        for(int i = 0; i < num.size(); i++){
//            cout << num[i] << ", ";
//        }
//        cout << "\n";
//
//        vector<int> Result;
//
//        int c = 1;
//        while(true){
//
//            if(pow(c, 2) <= num[0]){
//                c += 1;
//            }
//            else{
//                c -= 1;
//                break;
//            }
//        }
//
//        Result.push_back(c);
//
//        int carry = num[0] - pow(c, 2);
//
//        int ten_times = 10;
//        for(int i = 1; i < num.size(); i++){
//
//            int ac_carry = carry * 100;
//            int calcu_nb = ac_carry + num[i];
//
//            int guess_nb = get_R(R);
//
//            int d = 1;
//            while(true){
//
//                if((0 + d) * d <= calcu_nb){
//                    d += 1;
//                }else{
//                    d -= 1;
//                    break;
//                }
//
//            }
//
//
//
//        }
//
//
////        reverse(num.begin(), num.end());
////
////        for(int i = 0; i < len1; i++){
////            cout << num[i] << ", ";
////        }
////        cout << "\n";
//        return;
//    }

};

int main(){

    LargeNumber x1("28536");
    LargeNumber x2("23");

    LargeNumber x3 = x1 / x2;
    cout << x3.large_num << "\n";

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