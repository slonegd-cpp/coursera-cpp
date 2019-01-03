#include <vector>
#include <string>


void MoveStrings (std::vector<std::string>& s, std::vector<std::string>& d)
{
   for (auto v : s)
      d.push_back(v);
   s.clear();
}