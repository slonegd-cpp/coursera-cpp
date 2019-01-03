#include <iostream>
#include <vector>

int main()
{
   std::vector<int> res;
   int a;
   std::cin >> a;
   for (; a; a /= 2) {
      res.push_back (a % 2);
   }
   for (auto it = res.rbegin(); it < res.rend(); ++it)
      std::cout << *it;
   std::cout << std::endl;
}