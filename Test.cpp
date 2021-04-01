#include <string>
#include "Direction.hpp"
#include "Board.hpp"
#include "doctest.h"
using namespace std;

using namespace ariel;

Board board;

TEST_CASE("Test post and read")
{  
    board.post(0, 6, Direction::Horizontal, "Your only limit is your mind");
    board.post(1, 0, Direction::Horizontal, "Once you choose hope, everything is possible");
    board.post(2, 0, Direction::Horizontal, "Inspiration exists, but it has to find you working");
    board.post(3, 2, Direction::Horizontal, "Opportunities dont happen. You create them");
    board.post(4, 1, Direction::Horizontal, "Do one thing every day that scares you");
    board.post(5, 0, Direction::Horizontal, "I never dreamed about success, I worked for it");
    board.post(6, 3, Direction::Horizontal, "Creativity Is Intelligence Having Fun");
    board.post(7, 0, Direction::Horizontal, "Have no fear of perfection, you’ll never reach it");
    board.post(8, 7, Direction::Horizontal, "If you do it right, it’ll last forever");
    board.post(9, 4, Direction::Horizontal, "Dont dream it. Be it!");
    board.post(10,5, Direction::Horizontal, "Home is where the love is");


    CHECK(board.read(0, 0, Direction::Horizontal, 15) == "______Your only");
    CHECK(board.read(1, 3, Direction::Horizontal, 7) == "e you c");
    CHECK(board.read(2, 5, Direction::Horizontal, 10) == "ration exi");
    CHECK(board.read(3, 1, Direction::Horizontal, 20) == "_Opportunities dont ");
    CHECK(board.read(4, 3, Direction::Horizontal, 5) == " one ");
    CHECK(board.read(5, 12, Direction::Horizontal, 9) == "med about");
    CHECK(board.read(6, 30, Direction::Horizontal, 11) == "Having Fun_");
    CHECK(board.read(7, 0, Direction::Horizontal, 13) == "Have no fear ");
    CHECK(board.read(8, 2, Direction::Horizontal, 17) == "_____If you do it");
    CHECK(board.read(9, 4, Direction::Horizontal, 14) == "Dont dream it.");
    CHECK(board.read(10, 0, Direction::Horizontal, 35) == "_____Home is where the love is_____");
    CHECK(board.read(1, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(2, 5, Direction::Horizontal, 0) == "");
    CHECK(board.read(3, 7, Direction::Horizontal, 0) == "");
    
    CHECK(board.read(0, 0, Direction::Horizontal, 6) == "______");
    CHECK(board.read(6, 41, Direction::Horizontal, 5) == "_____");
    CHECK(board.read(9, 0, Direction::Horizontal, 4) == "____");
    CHECK(board.read(3, 0, Direction::Horizontal, 1) == "_");
    CHECK(board.read(4, 38, Direction::Horizontal, 2) == "u_");
    CHECK(board.read(10, 1, Direction::Horizontal, 3) == "___");


    board.post(0, 1, Direction::Vertical, "You'll never know what u can do if u wont try it now");
    board.post(1, 4, Direction::Vertical, "the sky is the limit");
    board.post(2, 3, Direction::Vertical, "Do not regret what makes you smile");
    board.post(3, 7, Direction::Vertical, "hoping for the best but expecting the worst");
    board.post(4, 5, Direction::Vertical, "It's not about how hard you hit. ");
    board.post(5, 0, Direction::Vertical, "It's about how hard you can get hit and keep moving forward.");


    CHECK(board.read(3, 0, Direction::Vertical, 22) == "__It's about how hard ");
    CHECK(board.read(4, 3, Direction::Vertical, 8) == " not reg");
    CHECK(board.read(1, 4, Direction::Vertical, 23) == "the sky is the limit___");
    CHECK(board.read(3, 5, Direction::Vertical, 9) == "oIt's not");
    CHECK(board.read(0, 1, Direction::Vertical, 18) == "You'll never know ");
    CHECK(board.read(1, 4, Direction::Vertical, 11) == "the sky is ");
    CHECK(board.read(2, 3, Direction::Vertical, 15) == "Do not regret w");
    CHECK(board.read(3, 7, Direction::Vertical, 4) == "hopi");
    CHECK(board.read(4, 5, Direction::Vertical, 12) == "It's not abo");
    CHECK(board.read(5, 0, Direction::Vertical, 2) == "It");
 
    CHECK_THROWS(board.read(2, 51,Direction::Horizontal, 5 ));
    CHECK_THROWS(board.read(3, 52,Direction::Horizontal, 1 ));
    CHECK_THROWS(board.read(4, 53,Direction::Horizontal, 3 ));
    CHECK_THROWS(board.read(1, 54,Direction::Horizontal, 3 ));
    CHECK_THROWS(board.read(5, 55,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(4, 57,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(6, 61,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(0, 82,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(1, 95,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(8, 75,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(9, 63,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(53, 100,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(20, 153,Direction::Horizontal, 2 ));
    CHECK_THROWS(board.read(40, 1014,Direction::Horizontal, 2 ));
}