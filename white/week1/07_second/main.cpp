#include <iostream>
#include <string>

int main() {
   std::string str;
   std::cin >> str;
   int count = 0;
   for (int i = 0; i < str.size(); ++i) {
      if (str[i] == 'f')
         count++;
      if (count == 2) {
         std::cout << i << std::endl;
         return 0;
      }
   }
   std::cout << count - 2 << std::endl;
   return 0;
}