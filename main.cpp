#include <bits/stdc++.h>

// To take input grid from User
void takeGridInput(int row, int column, char* grid)
{
  int counter = 0;

  std::cout << "Enter the grid elements : " ;
  std::cout << std::endl;

  for(int i=0; i < (row * column); i++)
  {
    std::cin >> *(grid+i);
  }
}

// To check next word is present
bool checkNextWord(int &index, int row, int column, char* grid, int wordIndex, char word[])
{
  if( (*(grid+index+1)) == word[wordIndex] || (*(grid+index+column)) == word[wordIndex])
  {
    if(wordIndex + 1 <= (*(&word + 1) - word))
    {
      if( (*(grid+index+1) > (row*column - 1)) || ((*(grid+index+1) > (row*column - 1))))
      {
        return false;
      }
      checkNextWord(index, column, row, (char*)grid, wordIndex + 1, word);
    }
    else
    {
      return true;
    }
  }
  return false;
}

// To check first word index inside grid
bool searchWord(int row, int column, char* grid, char word[])
{
  int index = 0;
  bool check = false;

  for(int i=0; i < (row * column); i++)
  {
    if(*(grid+i) == word[0])
    {
      index = i;
      check = checkNextWord(index, row, column, (char*)grid, 1, word);
    }
  }
  return check;
}


int main()
{
  int rows = 0;
  int columns = 0;
  char word[20];

  std::cout << "Enter the number of Rows in a grid : " ;
  std::cin >> rows; 
  std::cout << std::endl;

  std::cout << "Enter the number of columns in a grid : " ;
  std::cin >> columns; 
  std::cout << std::endl;

  char grid[rows][columns];

  takeGridInput(rows, columns, (char *)grid);

  std::cout << std::endl << "Enter the word to search : " ;
  std::cin >> word; 
  std::cout << std::endl;

  if(searchWord(rows, columns, (char*)grid, word))
  {
    std::cout << "Word is present in the grid" ;
  }
  else
  {
    std::cout << "Word is not present in the grid" ;
  }

 return 0;
 
}