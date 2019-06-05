#include <iostream>
#include <vector>

using namespace std;

int main(){
  char s[] = "acdbcb";
  vector<char> t;
  int a = 0; // current begin
  int b = sizeof(s) / sizeof(char) - 1; // current end

  while(a <= b){
    bool getleft = true;
    
    for(int i=0; a+i <= b; ++i){
      if(s[a+i] < s[b-i]){
	break;
      }else if(s[a+i] > s[b-i]){
	getleft = false;
	break;
      } // if s[a+i]==s[b-i], check next i.
    }

    if(getleft) t.push_back(s[a++]);
    else t.push_back(s[b--]);

    cout << "a,b=" << a << "," << b << endl;
  }

  cout << "output t = ";
  for(auto tt : t) cout << tt;
  cout << endl;
  
  return 0;
}
