#include <string>
#include <vector>

bool IsPalindrom(std::string str)
{

   for (int i = 0; i < str.size() / 2 + 1; ++i) {
      if (str[i] != str[str.size()-i-1])
         return false;
   }
   return true;
}

std::vector<std::string> PalindromFilter (std::vector<std::string> in, int min)
{
   std::vector<std::string> res;
   for (auto s : in)
      if (s.size() >= min and IsPalindrom(s))
         res.push_back(s);
   return res;
}

