#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

// struct Name {
//    std::string first;
//    std::string last;
// };


class Person {
public:
   Person ( const std::string& first, const std::string& last, int year)
   {
      this->first[year] = first;
      this->last [year] = last;
   }
   void ChangeFirstName (int year, const std::string& first_name) {
      if (year < first.begin()->first)
         return;
      first[year] = first_name;
   }
   void ChangeLastName (int year, const std::string& last_name) {
      if (year < first.begin()->first)
         return;
      last[year] = last_name;
   }
   std::string GetFullName (int year) const {
      if (year < first.begin()->first)
         return "No person";
      std::string first = get_name(this->first, year);
      std::string last  = get_name(this->last , year);

      return first.empty() and last.empty() ? "Incognito" :
             first.size()  and last.empty() ? first + " with unknown last name" :
             first.empty() and last.size()  ? last  + " with unknown first name" :
             first + " " + last;
   }

   std::string GetFullNameWithHistory(int year) const {
      if (year < first.begin()->first)
         return "No person";
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

   std::string get_name (const std::map<int, std::string>& map, int year) const
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

   std::string get_name_w_history (const std::map<int, std::string>& map, int year) const
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
//   Person person("Polina", "Sergeeva", 1960);
//   for (int year : {1959, 1960}) {
//     std::cout << person.GetFullNameWithHistory(year) << std::endl;
//   }
  
//   person.ChangeFirstName(1965, "Appolinaria");
//   person.ChangeLastName(1967, "Ivanova");
//   for (int year : {1965, 1967}) {
//     std::cout << person.GetFullNameWithHistory(year) << std::endl;
//   }

//   return 0;
// }