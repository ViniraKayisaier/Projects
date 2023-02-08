#include <iostream>
#include <tuple>
#include <string>
class TicTacToeGame
{
public:
  TicTacToeGame();
  virtual ~TicTacToeGame();

  void play();

//private:
  void initializeGrid();
  void displayGrid();
  std::tuple<int, int>findFirstUnoccupiedGridSqure();
  std::tuple<int, int>promptForGridCoord();
  bool checkForDraw();
  bool checkForWin();

private:
  char**pp_cGrid = nullptr;
};
//constructor
TicTacToeGame::TicTacToeGame()
{
  this->pp_cGrid = new char*[3];

  for(int iRow = 0;iRow<3;++iRow)
  {
    pp_cGrid[iRow] = new char[3];
  }
  initializeGrid();
}
//destructor
TicTacToeGame::~TicTacToeGame()
{
  for(int iRow = 0;iRow<3;iRow++)
  {
    delete[]pp_cGrid[iRow];
  }
  delete[]pp_cGrid;
  pp_cGrid = nullptr;
}


void TicTacToeGame::initializeGrid()
{
  for(int iRow = 0;iRow<3;iRow++)
  {
    for(int iColumn = 0;iColumn<3;iColumn++)
    {
      this->pp_cGrid[iRow][iColumn] = '~';
    }
    std::cout<<std::endl;
  }

}


void TicTacToeGame::displayGrid()
{
  for(int iRow = 0;iRow<3;iRow++)
  {
    for(int iColumn = 0;iColumn<3;iColumn++)
    {
      std::cout<<this->pp_cGrid[iRow][iColumn] << " ";
    }
    std::cout<<std::endl;
  }

  std::cout<<std::endl;
}

std::tuple<int,int>TicTacToeGame::findFirstUnoccupiedGridSqure()
{
  int iRowUnoccupied = -1;
  int iColumnUnoccupied = -1;

  bool bFound = false;

  for(int iRow = 0;(iRow<3)&& !bFound;iRow++)
  {
    for(int iColumn = 0;(iColumn<3)&& !bFound;iColumn++)
    {
      if(this->pp_cGrid[iRow][iColumn] =='~')
      {
        iRowUnoccupied = iRow;
        iColumnUnoccupied = iColumn;
        bFound = true;
      }
    }
  }

  std::tuple<int,int>tupleUnoccupiedGridSquare(iRowUnoccupied,iColumnUnoccupied);
  return tupleUnoccupiedGridSquare;
}

std::tuple<int,int>TicTacToeGame::promptForGridCoord()
{
  int iRow = 0;
  int iColumn = 0;

  std::cout<<"Please enter grid row number:"<<std::endl;
  std::cin>>iRow;

  std::cout<<"Please enter grid Column number:"<<std::endl;
  std::cin>>iColumn;

  std::tuple<int,int>tupleCoord = std::make_tuple(iRow,iColumn);

  return tupleCoord;
}

//check for draw
bool TicTacToeGame::checkForDraw()
{
  bool bContinue = false;

  for(int iRow = 0;iRow<3;iRow++)
  {
    for(int iColumn = 0;iColumn<3;iColumn++)
    {
      if(this->pp_cGrid[iRow][iColumn] != 'X'&& this->pp_cGrid[iRow][iColumn] != 'O')
      bContinue = true;
    }
  }
  return !bContinue;
}
//check for win
bool TicTacToeGame::checkForWin()
{
  bool bWin = false;
  for(int iRow = 0;(iRow<3)&& !bWin;iRow++)
  {
    if(this->pp_cGrid[iRow][0] !='~')
    {
      if((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1])&&(this->pp_cGrid[iRow][0]==this->pp_cGrid[iRow][2]))
      {
        bWin = true;
        std::cout<<"WINNER:"<<this->pp_cGrid[iRow][0]<<"!"<<std::endl;
      }
    }
  }
  //std::cout<<"Diag:Row Check"<<bWin<<std::endl;
  for(int iColumn = 0;(iColumn<3)&& !bWin;iColumn++)
  {
    if(this->pp_cGrid[0][iColumn] !='~')
    {
      if((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn])&&(this->pp_cGrid[0][iColumn]==this->pp_cGrid[2][iColumn]))
      {
        bWin = true;
        std::cout<<"WINNER:"<<this->pp_cGrid[0][iColumn]<<"!"<<std::endl;
      }
    }
  }
  //std::cout<<"Diag:Column Check"<<bWin<<std::endl;

  if(this->pp_cGrid[0][0] !='~')
  {
    if((this->pp_cGrid[0][0] == this->pp_cGrid[1][1])&&(this->pp_cGrid[0][0]==this->pp_cGrid[2][2]))
    {
      bWin = true;
      std::cout<<"WINNER:"<<this->pp_cGrid[0][0]<<"!"<<std::endl;
    }
  }
  //std::cout<<"Diag:Diag L Check"<<bWin<<std::endl;
  if(this->pp_cGrid[0][2] !='~')
  {
    if((this->pp_cGrid[0][2] == this->pp_cGrid[1][1])&&(this->pp_cGrid[0][2]==this->pp_cGrid[2][0]))
    {
      bWin = true;
      std::cout<<"WINNER:"<<this->pp_cGrid[0][2]<<"!"<<std::endl;
    }
  }
  //std::cout<<"Diag:Diag R Check"<<bWin<<std::endl;
  return bWin;

}

void TicTacToeGame::play()
{
  bool bWin = false;
  bool bDraw = false;

  std::cout<<std::endl;

  displayGrid();

  while(!bWin && !bDraw)
  {
    int iRow = 0;
    int iColumn = 0;
    std::tie(iRow,iColumn) = promptForGridCoord();
    this->pp_cGrid[iRow][iColumn] = 'X';

    displayGrid();
    bWin = checkForWin();
    bDraw = checkForDraw();

    if(!bWin and !bDraw)
    {
      std::tie(iRow,iColumn) = findFirstUnoccupiedGridSqure();
      this->pp_cGrid[iRow][iColumn] = 'O';

      displayGrid();
      bWin = checkForWin();
      bDraw = checkForDraw();
    }
    if(bDraw && !bWin)
    {
      std::cout<<"Draw"<<std::endl;
    }
  }
  std::cout<<"Game over."<<std::endl;
  return;
}

int main()
{
  TicTacToeGame*p_game = new TicTacToeGame();

  p_game->play();
  //p_game->displayGrid();
  //p_game->promptForGridCoord();

  delete p_game;
}
