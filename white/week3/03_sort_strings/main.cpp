#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>


class SortedStrings {
public:
   void AddString(const std::string& s)
   {
      strings.insert (s);
   }
   std::vector<std::string> GetSortedStrings()
   {
      return std::vector<std::string> (strings.begin(), strings.end());
   }
private:
   std::multiset<std::string> strings;
};








// template<class T>
// T get (std::istream& s)
// {
//    return *std::istream_iterator<T>(s);
// }

// int main()
// {
//    SortedStrings strings;
//    strings.AddString (get<std::string>(std::cin));
//    strings.AddString (get<std::string>(std::cin));
//    strings.AddString (get<std::string>(std::cin));

//    auto get = strings.GetSortedStrings();

//    for (auto& i : get)
//       std::cout << i << ' ';
//    std::cout << std::endl;
// }

// void PrintSortedStrings(SortedStrings& strings) {
//   for (const auto& s : strings.GetSortedStrings()) {
//     std::cout << s << " ";
//   }
//   std::cout << std::endl;
// }

// int main() {
//   SortedStrings strings;
  
//   strings.AddString("first");
//   strings.AddString("third");
//   strings.AddString("second");
//   PrintSortedStrings(strings);
  
//   strings.AddString("second");
//   PrintSortedStrings(strings);
  
//   return 0;
// }