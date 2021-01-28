#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::cout;

string findAndReplace(string subject, string lookfor, string replace_with){
  auto x = subject.find(lookfor);
  cout << x << "\n";
  if ( x > subject.size()){
    return subject;
  }
  subject.replace(x, lookfor.length(), replace_with);
  return subject;
}

int main(){
  string subject1 = "We We the Web Content cometh";
  string subject2 = "We We the Weeb Content cometh";
  string lookfor = "Web Content";
  string replace_with = "Web_Content";

  cout << findAndReplace(subject1, lookfor, replace_with) << "\n";
  cout << findAndReplace(subject2, lookfor, replace_with) << "\n";
}