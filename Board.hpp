#include <string>
#include <vector>
#include "Direction.hpp"

namespace ariel
{
    class Board
    {
    private:
        unsigned int max_rows;
        unsigned int max_columns;

        std::vector<std::vector<char>> board;

    public:
        Board()
        {
            board = std::vector<std::vector<char>>(5, std::vector<char>(5, '_'));
            max_rows =  max_columns = 5;
        }
        ~Board() {}
        void post(unsigned int row, unsigned int column, Direction direction, std::string message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
        void resizeBoard(unsigned int rows, unsigned int columns);
    };
}
