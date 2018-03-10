#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//int l;
//int work(int o,char *O,int I) {
//    char c, *D=O ;
//    if (o>0) {
//        for (l=0;D[l];D[l++]-=10) {
//            D[l++] -= 120;
//            D[l] -= 110;
//            while (!work(0,O,l)) D[l] += 20;
//            putchar((D[l]+1032)/20);
//            cout << "here\n";
//        }
//        putchar(10);
//    }
//    else {
//        c = o+(D[I]+82)%10-(I>l/2)*(D[I-l+I]+72)/10-9;
//        D[I] += I<0?0:!(o=work(c/10,O,I-1))*((c+999)%10-(D[I]+92)%10);
//    }
//    return o;
//}

int l;
int work(int o,char* O,int I, string &R) {
    //int l = 0;
    char c, *D=O;

    if (o>0) {
        for (l=0;D[l];D[l++]-=10) {
            D[l++] -= 120;
            D[l] -= 110;
            while (!work(0,O,l,R)) D[l] += 20;
            //putchar((D[l]+1032)/20);
            //cout << "here\n";
            R += (D[l]+1032)/20;
        }
        putchar(10);
        //R += "\n";

    }
    else {
        c = o+(D[I]+82)%10-(I>l/2)*(D[I-l+I]+72)/10-9;
        D[I] += I<0?0:!(o=work(c/10,O,I-1,R))*((c+999)%10-(D[I]+92)%10);
    }
    return o;
}


string integer_square_root(string n) {
  // Coding and coding ...

  char s[1200] = {'0'};
  s[0] = '0';

  for(int i = 0; i < n.length(); i++){
    s[i + 1] = n[i];
  }
  cout << "\n====\n";
  cout << s << "\n====\n";
  //string s = "0";
  //s += n;
  string R = "";
  if(strlen(s) % 2 == 1){
    work(2,s+1,0,R);
  }
  else{
    work(2, s, 0,R);
  }


  return R;
}







int main() {
//    char s[1200];
//    s[0]='0';
//    scanf("%s",s+1);
//    cout << "\n======\n";
//    cout << s;
//    cout << "\n======\n";
//    if (strlen(s)%2 == 1){
//        int n = work(2,s+1,0);
//        cout <<"\n"<< n << "\n";
//    }
//    else {
//        int n = work(2,s,0);
//        cout <<"\n"<< n << "\n";
//    }
//    return 0;

    string R = "59676850312621998725542577355906394196526587660";
    string r = integer_square_root(R);
    cout << "\n===\n";
    cout << r << "\n";
////    cout << "saf";
////    putchar(10);
//    string s = "0";
//    s += "asdf";
//    cout << s;
}

