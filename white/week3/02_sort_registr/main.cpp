#include <vector>
#include <string>
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
   std::vector<std::string> v;
   v.reserve(count);
   while (count--) {
      v.push_back (get<std::string>(std::cin));
   }

   std::sort (v.begin(), v.end(), [](auto l, auto r) {
      for (auto& c : l) c = std::tolower(c);
      for (auto& c : r) c = std::tolower(c);
      return l < r;
   });

   for (auto& i : v)
      std::cout << i << ' ';
   std::cout << std::endl;
}