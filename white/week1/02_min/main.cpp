#include <iostream>
#include <string>

int main() {
   std::string a, b, c;
   std::cin >> a >> b >> c;
   if (a < b) {
      if (a < c) {
         std::cout << a << std::endl;
      } else {
         std::cout << c << std::endl;
      }
   } else {
      if (b < c) {
         std::cout << b << std::endl;
      } else {
         std::cout << c << std::endl;
      }      
   }
}