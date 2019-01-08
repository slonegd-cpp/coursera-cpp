#include <tuple>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// enum class Lang {
//   DE, FR, IT
// };

// struct Region {
//   string std_name;
//   string parent_std_name;
//   map<Lang, string> names;
//   int64_t population;
// };


auto Get(const Region& v)
{
   return tie(v.std_name, v.parent_std_name, v.names, v.population);
}

bool operator< (const Region& r, const Region& l)
{
   return Get(r) < Get(l);
}

int FindMaxRepetitionCount (const vector<Region>& regions)
{
   if (regions.empty())
      return 0;
   map<Region, int> map_;
   for (const auto& r : regions) 
      ++map_[r];

   return max_element(map_.begin(), map_.end(), [](auto l, auto r){ return l.second < r.second; })->second;
}

// int main() {
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       },
//   }) << endl;
  
//   cout << FindMaxRepetitionCount({
//       {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Russia",
//           "Eurasia",
//           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Toulouse",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           89
//       }, {
//           "Moscow",
//           "Russia",
//           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//           31
//       },
//   }) << endl;
  
//   return 0;
// }
