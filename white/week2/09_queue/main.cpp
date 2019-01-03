#include <iostream>
#include <vector>
#include <string>
#include <iterator>

int main()
{
   std::vector<bool> worry;
   std::string command;
   auto N = *std::istream_iterator<int>(std::cin);
   while (N--) {
      std::cin >> command;
      if (command == "WORRY_COUNT") {
         int res;
         res = 0;
         for (auto b : worry)
            res += b;
         std::cout << res << std::endl;
         continue;
      } 

      auto n = *std::istream_iterator<int>(std::cin);
      if (command == "WORRY") {
         if (n < worry.size())
            worry[n] = true;
         continue;
      }

      if (command == "QUIET") {
         if (n < worry.size())
            worry[n] = false;
         continue;
      }

      if (command == "COME") {
         int new_size = worry.size() + n;
         if (n < 0 and new_size >= 0) {
            worry.resize (new_size);
            continue;
         }
         if (n > 0) {
            while (n--)
               worry.push_back(false);
            continue;
         }
      }
   }
}