#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>


class ReversibleString {
   std::string string;
public:
   ReversibleString() = default;
   ReversibleString (const std::string& s) : string(s) {}

   std::string ToString() const { return string; }
   void Reverse()
   {
      std::reverse (string.begin(), string.end());
   }
};




// int main() {
//   ReversibleString s("live");
//   s.Reverse();
//   std::cout << s.ToString() << std::endl;
  
//   s.Reverse();
//   const ReversibleString& s_ref = s;
//   std::string tmp = s_ref.ToString();
//   std::cout << tmp << std::endl;
  
//   ReversibleString empty;
//   std::cout << '"' << empty.ToString() << '"' << std::endl;
  
//   return 0;
// }