/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/

#ifndef QUEEN_H
#define QUEEN_H
///@author Abigail Cabascango and Carlos Romero M.
class Queen
{
private:
    int queen_number;
    int *board;
public:
    /**
    *@brief Constructor
    *@param int queens number.
    */
    Queen (int queen_number)
    {
        this->queen_number = queen_number;
        this->board = new int[queen_number];
    }
    ///@brief Destroyer
    ~Queen() {}
    /**
    *@brief Wax the chess board.
    *@param void.
    *@return void.
    */
    void wax()
    {
        for (int i = 0; i < GetQueenNumber(); i++)
            *(GetBoard() + i) = 0;
    }
    /**
    *@name NQueens
    *@brief Start the solutions.
    *@param void.
    *@return void.
    *@see solution
    */
    void NQueens()
    {
        wax();
        solution(board, 0, 0);
    }
    /**
    *@name solution
    *@brief Position a queen on the chess board.
    *@param int* board.
    *@param int row of board.
    *@param int column of board.
    *@see IsValid
    *@return void.
    */
    void solution(int* board, int row, int column)
    {
        int queens = GetQueenNumber();
        if (row == queens)
        {
            print(board);
        }
        else
        {
            if (column < queens)
            {
                *(board + row) = column;
                if (IsValid(board, row, 0))
                {
                    solution(board, row + 1, 0);
                }
                solution(board, row, column + 1);
            }
        }

    }
    /**
    *@name IsValid
    *@brief Validate if the queen is correctly positioned.
    *@param int* board.
    *@param int row of board.
    *@param int column of board.
    *@see solution
    *@return void.
    */
    bool IsValid(int* board, int row, int column)
    {
        if (column < row)
        {
            if (*(board + column) == *(board + row))
            {
                return false;
            }
            if ((*(board + column) + column) == (*(board + row) + row))
            {
                return false;
            }
            if ((*(board + column) - column) == (*(board + row) - row))
            {
                return false;
            }
            else
            {
                return IsValid(board, row, column + 1);
            }
        }
        return true;
    }
    /**
    *@brief Print the chess board.
    *@param int* board.
    *@return void.
    */
    void print(int* board)
    {
        int queens = GetQueenNumber();
        for (int i = 0; i < queens; i++)
        {
            for (int j = 0; j < queens; j++)
            {
                if (*(board + i) == j)
                {
                    std::cout << " Q ";
                }
                else
                {
                    std::cout << " * ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    /**
    *@brief Getter of queen number.
    *@param void
    *@return int queens number.
    */
    int GetQueenNumber()
    {
        return queen_number;
    }
    /**
    *@brief Setter of queen number.
    *@param int queens number.
    *@return void.
    */
    void SetQueenNumber(int queen_number)
    {
        this->queen_number = queen_number;
    }
    /**
    *@brief Getter of board.
    *@param void.
    *@return int* board.
    */
    int* GetBoard()
    {
        return board;
    }
    /**
    *@brief Setter of board.
    *@param int* board.
    *@return void.
    */
    void SetBoard(int* board)
    {
        this->board = board;
    }
};
#endif // QUEEN_H
