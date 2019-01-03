#include <iostream>

int main() {
   int a ,b;
   std::cin >> a  >> b;
   while (a <= b) {
      if (not (a % 2))
         std::cout << a << ' ';
      a++;
   }
   std::cout << std::endl;
}