#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

struct Name {
   std::string first;
   std::string last;
};


class Person {
public:
   void ChangeFirstName (int year, const std::string& first_name) {
         first[year] = first_name;
   }
   void ChangeLastName (int year, const std::string& last_name) {
      last[year] = last_name;
   }
   std::string GetFullName (int year) {
      std::string first = get_name(this->first, year);
      std::string last  = get_name(this->last , year);

      return first.empty() and last.empty() ? "Incognito" :
             first.size()  and last.empty() ? first + " with unknown last name" :
             first.empty() and last.size()  ? last  + " with unknown first name" :
             first + " " + last;
   }

   std::string GetFullNameWithHistory(int year) {
      std::string first = get_name_w_history(this->first, year);
      std::string last  = get_name_w_history(this->last , year);

      return first.empty() and last.empty() ? "Incognito" :
             first.size()  and last.empty() ? first + " with unknown last name" :
             first.empty() and last.size()  ? last  + " with unknown first name" :
             first + " " + last;
   }

private:
   std::map<int, std::string> first;
   std::map<int, std::string> last;

   std::string get_name (std::map<int, std::string>& map, int year)
   {
      std::string res;
      for (const auto& p : map) {
         if (p.first > year)
            break;
         else
            res = p.second;
      }
      return res;
   }

   std::string get_name_w_history (std::map<int, std::string>& map, int year)
   {
      std::vector<std::string> history;
      
      for (const auto& p : map) {
         if (p.first > year)
            break;
         else if (history.empty())
            history.push_back (p.second);
         else if (history.back() != p.second)
            history.push_back (p.second);
      }

      std::string res;
      auto it = history.rbegin();

      if (it != history.rend())
         res += *it++;

      if (it != history.rend())
         res += " (";

      for (; it != history.rend(); ++it)
         (res += *it) += ", ";

      if (res.back() == ' ') {
         res.pop_back();
         res.pop_back();
         res += ")";
      }
      
      return res;
   }
};








// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     std::cout << person.GetFullNameWithHistory(year) << std::endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     std::cout << person.GetFullNameWithHistory(year) << std::endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     std::cout << person.GetFullNameWithHistory(year) << std::endl;
//   }
  
//   person.ChangeFirstName(1990, "Polina");
//   person.ChangeLastName(1990, "Volkova-Sergeeva");
//   std::cout << person.GetFullNameWithHistory(1990) << std::endl;
  
//   person.ChangeFirstName(1966, "Pauline");
//   std::cout << person.GetFullNameWithHistory(1966) << std::endl;
  
//   person.ChangeLastName(1960, "Sergeeva");
//   for (int year : {1960, 1967}) {
//     std::cout << person.GetFullNameWithHistory(year) << std::endl;
//   }
  
//   person.ChangeLastName(1961, "Ivanova");
//   std::cout << person.GetFullNameWithHistory(1967) << std::endl;
  
//   return 0;
// }