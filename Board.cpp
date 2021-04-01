#include <iostream>
#include <string>
#include <vector>
#include "Board.hpp"
using namespace std;

namespace ariel
{

    void Board::resizeBoard(unsigned int rows, unsigned int columns)
    {
        Board::max_rows = max(Board::max_rows, rows);
        Board::max_columns = max(Board::max_columns, columns);
        Board::board.resize(Board::max_rows);
        for (size_t i = 0; i < Board::max_rows; i++)
        {
            Board::board[i].resize(Board::max_columns, '_');
        }
    }

    void Board::post(unsigned int row, unsigned int column, Direction direction, std::string message)
    {
        int d = 0;
        if (direction == Direction::Horizontal)
        {
            resizeBoard(row + 1, column + message.length());
        }
        else
        {
            resizeBoard(row + message.length(), column + 1);
            d++;
        }
        for (size_t i = 0; i < message.length(); i++)
        {
            Board::board[row][column] = message[i];
            if (d == 0)
            {
                column++;
            }
            else
            {
                row++;
            }
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        if ((row > max_rows && direction == Direction::Vertical) || (column > max_columns && direction == Direction::Horizontal))
        {
            string ad;
            for (int i = 0; i < length; i++)
            {
                ad += "_";
            }
            return ad;
        }
        if (length <= 0){
            return "";
        }
        string ad;
        if (row > Board::max_rows - 1 || column > Board::max_columns - 1)
        {
            throw new runtime_error("Out of bounds!");
        }
        unsigned int remains = length;
        for (size_t i = 0; i < length && row <= Board::max_rows - 1 &&
                           column <= Board::max_columns - 1;
             i++)
        {
            ad += board.at(row).at(column);
            if (direction == Direction::Horizontal)
            {
                column++;
            }
            else
            {
                row++;
            }
            remains--;
        }
        for (size_t i = 0; i < remains; i++)
        {
            ad += "_";
        }
        return ad;
    }
    void Board::show()
    {
        for (size_t i = 0; i < Board::max_rows; i++)
        {
            for (size_t j = 0; j < Board::max_columns; j++)
            {
                if (j == 0)
                {
                    cout << i << ":";
                }
                cout << Board::board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
