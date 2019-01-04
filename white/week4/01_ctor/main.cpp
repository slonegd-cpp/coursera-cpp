#include <string>

struct Specialization {
   std::string v;
   explicit Specialization (const std::string v) : v{v} {}
};

struct Course {
   std::string v;
   explicit Course (const std::string v) : v{v} {}
};

struct Week {
   std::string v;
   explicit Week (const std::string v) : v{v} {}
};

struct LectureTitle {
   std::string specialization;
   std::string course;
   std::string week;
   LectureTitle (Specialization s, Course c, Week w)
      : specialization {s.v}
      , course         {c.v}
      , week           {w.v}
   {}
};


// int main()
// {
// // good
//    LectureTitle title(
//       Specialization("C++"),
//       Course("White belt"),
//       Week("4th")
//    );


//    // // bad
//    // LectureTitle title2("C++", "White belt", "4th");

//    // LectureTitle title3(std::string("C++"), std::string("White belt"), std::string("4th"));

//    // LectureTitle title4 = {"C++", "White belt", "4th"};

//    // LectureTitle title5 = {{"C++"}, {"White belt"}, {"4th"}};

//    // LectureTitle title6(
//    //    Course("White belt"),
//    //    Specialization("C++"),
//    //    Week("4th")
//    // );

//    // LectureTitle title7(
//    //    Specialization("C++"),
//    //    Week("4th"),
//    //    Course("White belt")
//    // );
// }
