#include <vector>

std::vector<int> Reversed (const std::vector<int>& in)
{
   std::vector<int> out;
   for (auto it = in.rbegin(); it < in.rend(); ++it)
      out.push_back (*it);
   return out;
}