#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

std::map<char, int> char_count (const std::string& s)
{
   std::map<char, int> res;
   for (auto c : s)
      res[c]++;
   return res;
}

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}

int main()
{
   auto count = get<int>(std::cin);
   std::vector<bool> res;
   res.reserve (count);
   while (count--) {
      auto s1 = get<std::string>(std::cin);
      auto s2 = get<std::string>(std::cin);
      res.push_back (char_count(s1) == char_count(s2));
   }

   for (auto b : res)
      std::cout << (b ? "YES" : "NO") << std::endl;
}