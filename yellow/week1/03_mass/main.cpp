#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


int main()
{
   size_t n, r, res {0};
   std::cin >> n >> r;

   while (n--) {
      size_t a, b, c;
      std::cin >> a >> b >> c;
      res += a*b*c*r;
   }

   std::cout << res << std::endl;
}