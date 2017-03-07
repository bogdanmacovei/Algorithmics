#include <iostream>

typedef struct nodcol
{
    int _indexCol;
    int _val;
    nodcol *_nextCol;
}NodCol;

typedef struct nodline
{
    int _indexLine;
    nodline *_nextLine;
    NodCol *nextCol;
}NodLine;

NodLine *primLine1, *ultimLine1, *primLine2, *ultimLine2, *primLine3, *ultimLine3;
NodCol *primCol1, *ultimCol1, *primCol2, *ultimCol2, *primCol3, *ultimCol3;

int search_line(int index, NodLine *primLine)
{
    for(NodLine *newNodLine = primLine; newNodLine; newNodLine = newNodLine->_nextLine)
        if(newNodLine->_indexLine == index)
            return 1;
    return 0;
}

void adaug_element(int val, int line, int column, NodLine *&primLine, NodLine *&ultimLine, NodCol *&primCol, NodCol *ultimCol)
{
    if(!search_line(line, primLine))
    {
        if(!primLine)
        {
            NodLine *newNodLine = new NodLine;
            newNodLine->_indexLine = line;
            primLine = ultimLine = newNodLine;
            ultimLine->_nextLine = NULL;

            NodCol *newNodCol = new NodCol;
            newNodCol->_indexCol = column;
            newNodCol->_val = val;
            primCol = ultimCol = newNodCol;
            ultimCol->_nextCol = NULL;

            newNodLine->nextCol = newNodCol;
        }
        else
        {
            NodLine *newNodLine = new NodLine;
            newNodLine->_indexLine = line;
            newNodLine->_nextLine = NULL;
            ultimLine->_nextLine = newNodLine;
            ultimLine = newNodLine;

            NodCol *newNodCol = new NodCol;
            newNodCol->_indexCol = column;
            newNodCol->_val = val;
            primCol = ultimCol = newNodCol;
            ultimCol->_nextCol = NULL;

            newNodLine->nextCol = newNodCol;

        }
    }
    else
    {
        for(NodLine *newNodLine = primLine; newNodLine; newNodLine = newNodLine->_nextLine)
        {
            if(newNodLine->_indexLine == line)
            {
                NodCol *newNodCol = newNodLine->nextCol;
                for(;newNodCol->_nextCol; newNodCol = newNodCol->_nextCol);

                NodCol *newCol = new NodCol;
                newCol->_val = val;
                newCol->_indexCol = column;
                newCol->_nextCol = NULL;
                newNodCol->_nextCol = newCol;
                ultimCol = newCol;
                break;
            }
        }
    }
}

int max_line(NodLine *primLine)
{
    int maxLine = 0;
    for(NodLine *newNodLine = primLine; newNodLine; newNodLine = newNodLine->_nextLine)
        if(newNodLine->_indexLine > maxLine)
            maxLine=newNodLine->_indexLine;
    return maxLine;
}

int max_column(NodLine *primLine, int index)
{
    int maxColumn = 0;
    for(NodLine *newNodLine = primLine; newNodLine; newNodLine = newNodLine->_nextLine)
        if(newNodLine->_indexLine == index)
        {
            NodCol *newNodCol = newNodLine->nextCol;
            for(;newNodCol; newNodCol = newNodCol->_nextCol)
                if(newNodCol->_indexCol > maxColumn)
                    maxColumn = newNodCol->_indexCol;
            break;
        }
    return maxColumn;
}

int caut_nod(int line, int column, NodLine *primLine)
{
    for(NodLine *newNodLine = primLine; newNodLine; newNodLine = newNodLine->_nextLine)
    {
        if(newNodLine->_indexLine == line)
        {
            NodCol *newNodCol = newNodLine->nextCol;
            for(;newNodCol; newNodCol = newNodCol->_nextCol)
            {
                if(newNodCol->_indexCol == column)
                    return newNodCol->_val;
            }
        }
    }
    return 0;
}

void suma_matrice(NodLine *primLine1, NodLine *ultimLine1, NodLine *primLine2, NodLine *ultimLine2,
                  NodCol *primCol1, NodCol *ultimCol1, NodCol *primCol2, NodCol *ultimCol2,
                  NodLine *&primLine3, NodLine *&ultimLine3, NodCol *&primCol3, NodCol *&ultimCol3)
{
    int index_line1 = max_line(primLine1);
    int index_line2 = max_line(primLine2);
    int index_line = index_line1>index_line2?index_line1:index_line2;

    for(int line = 1; line <= index_line; ++line)
    {
        int index_column1 = max_column(primLine1, line);
        int index_column2 = max_column(primLine2, line);
        int index_column = index_column1>index_column2?index_column1:index_column2;

        for(int column = 1; column <= index_column; ++column)
        {
            int S=0;
            S+=caut_nod(line, column, primLine1) + caut_nod(line, column, primLine2);
            if(S)
            {
                adaug_element(S, line, column, primLine3, ultimLine3, primCol3, ultimCol3);
            }
        }
    }
}

void afisare_matrice(NodLine *primLine, NodCol *primCol)
{
    for(NodLine *newNodLine = primLine; newNodLine; newNodLine = newNodLine->_nextLine)
    {
        NodCol *newNodCol = newNodLine->nextCol;
        for(;newNodCol; newNodCol = newNodCol->_nextCol)
            std::cout << "("<< newNodCol->_val<< ", " << newNodLine->_indexLine << ", " << newNodCol->_indexCol << ") ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{
    primLine1 = ultimLine1 = primLine2 = ultimLine2 = NULL;
    primCol1 = ultimCol1 = primCol2 = ultimCol2 = NULL;

    adaug_element(1, 5, 5, primLine1, ultimLine1, primCol1, ultimCol1);
    adaug_element(2, 7, 7, primLine1, ultimLine1, primCol1, ultimCol1);
    adaug_element(3, 7, 8, primLine1, ultimLine1, primCol1, ultimCol1);
    adaug_element(4, 10, 10, primLine1, ultimLine1, primCol1, ultimCol1);

    afisare_matrice(primLine1, primCol1);

    adaug_element(1, 5, 5, primLine2, ultimLine2, primCol2, ultimCol2);
    adaug_element(2, 7, 7, primLine2, ultimLine2, primCol2, ultimCol2);
    adaug_element(3, 8, 8, primLine2, ultimLine2, primCol2, ultimCol2);
    adaug_element(4, 10, 10, primLine2, ultimLine2, primCol2, ultimCol2);

    afisare_matrice(primLine2, primCol2);

    suma_matrice(primLine1, ultimLine1, primLine2, ultimLine2, primCol1,
                 ultimCol1, primCol2, ultimCol2, primLine3, ultimLine3, primCol3, ultimCol3);
    afisare_matrice(primLine3, primCol3);

    return 0;
}
