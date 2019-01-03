#include <iostream>
#include <cmath>

int main() {
   float a, b, c, x1 , x2;
   std::cin >> a >> b >> c;
   
   if (a != 0) {
      float d = b*b - 4*a*c;
      if (d >= 0) {
         x1 = (-b + std::sqrt(d)) / 2 / a;
         x2 = (-b - std::sqrt(d)) / 2 / a;
      }
      if (d > 0)
         std::cout << (x1 == 0 ? 0 : x1) << " " << (x2 == 0 ? 0 : x2) << std::endl;
      else if (d == 0)
         std::cout << (x1 == 0 ? 0 : x1) << std::endl;

   } else if (b != 0) {
      x1 = -c / b;
      std::cout << (x1 == 0 ? 0 : x1) << std::endl;
   }
}
