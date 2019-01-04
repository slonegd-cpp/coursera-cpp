#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}

int main()
{
   auto count = get<int>(std::cin); 
   std::vector<int> v;
   v.reserve(count);
   while (count--) {
      v.push_back (get<int>(std::cin));
   }

   std::sort (v.begin(), v.end(), [](auto l, auto r) { return std::abs(l) < std::abs(r); });

   for (auto i : v)
      std::cout << i << ' ';
   std::cout << std::endl;
}