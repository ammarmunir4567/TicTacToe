#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


class ticTacToe
{
    
public:
    int size;
    char** board;

public:

    ticTacToe()//default cons
    {
        board = new char* [3];
        for (int i = 0; i < 3; i++)
        {
            board[i] = new char[3];
        }
    }
    ticTacToe(int size)//parameterized constructor//
    {
        board = new char* [size];
        for (int i = 0; i < size; i++)
        {
            board[i] = new char[size];
            
        }
    }

    ticTacToe(ticTacToe& obj)//copy constructor//
    {
        obj.size = size;
        obj.board = new char* [obj.size];
        for (int i = 0; i < obj.size; i++)
        {
            obj.board[i] = new char[obj.size];
        }
        for (int i = 0; i < obj.size; i++)
        {
            for (int j = 0; j < obj.size; j++)
            {
                obj.board[i][j] = board[i][j];
            }
        }
    }
    void SetBoard(int size)//intializing board with some alphabets//
    {
        char x = 'a';
        
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                board[i][j] =x; //displaying different alphabets
                x++;
            }
        }
    }
    
    void Turn (char alphabet, char Player){//function for assigning X,O
        bool wrong = true;
        for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (board[i][j] == alphabet)//checking if the point is available
                    {
                        board[i][j] = Player; //Assigns the space with the X or O,
                        wrong = false;
                    }
                }
            }
            if (wrong == true)
            {
                cout << " sorry you can only mark free spaces!!!"<<endl;
            }
        }

        bool CheckResult(char Player, bool Over)//checker function for win
        {
            char *x;//row wise check
            x = new char[size];
            int count = 0;
            bool check = true;
        
        for(int i=0;i<size;i++)
            {
            x[i] = board[i][0];
            }
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (x[i] == board[i][j] && count <= size)
                    {
                        check = true;
                        count++;

                    }
                    else
                    {
                        check = false;
                        count = 0;
                        break;
                    }
                    if (check == true && count == size)
                    {
                        Over = true;    }
                }
            }
        char* x1;
        x1 = new char[size];
        int count1 = 0;
        bool check1 = true;

        for(int i=0;i<size;i++)
        {
            x1[i] = board[0][i];
        }
        
        for (int i = 0; i < size; i++)//for column
        {
            
            for (int j = 0; j < size; j++)
            {
                if (x1[i] == board[j][i] && count1 <= size)
                {
                    check1 = true;
                    count1++;
                    
                }
                else
                {
                    check1 = false;
                    count1 = 0;
                    break;
                    
                }
                if (check1 == true && count1 == size)
                {
                    Over = true;    }
            }
        }
        delete x;
        delete x1;
        x = nullptr;
        x1 = nullptr;
            //Checking the Diagonals
            char y = board[0][0];
            char z = board[0][size-1];
            bool found = true;
            bool found1 = true;
            int counter = 0;
            int counter1 = 0;
        for(int i=0;i<size;i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j) {//condition for left diagnol
                    if (board[i][j] == y)
                    {
                        found = true;
                        counter++;
                    }
                    else
                    {
                        found = false;
                        counter = 0;
                    
                    }
                    if (counter == size && found == true)
                    {
                        Over = true;
                        }
                }
            
            }
            
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i + j == size - 1)//condition for rigth diagnol
                {
                    if (board[i][j] == z)
                    {
                        found1 = true;
                        counter1++;
                    }
                    else
                    {
                        found1 = false;
                        counter1 = 0;


                    }

                }
                if (counter1 == size && found1 == true)
                {
                    Over = true;

                }
            }
        }
        
        result_print(Over, Player);
            return Over;
        }

    void result_print(bool Over,char Player)//print func
    {
        if (Over == true)
        {
            cout << endl<<endl << " CONGRATULATIONS --Player " << Player << " won!!!!" << endl << endl;
        
        }
    }
    
        bool CheckDraw(bool Over)//function to check draw
        {
            char n = 'a';
        
            int temp = 0;

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (board[i][j] == n)//checking if the places are taken or not
                    {
                        temp++;
                    }
                    n++;
                }
            }
            if (temp <1)
            {
                cout << "Game is draw!!"<<endl;
                Over = true;
            }
            return Over;
        }
        void PrintBoard(int size)
            {
            this ->size = size;
            int i = 0;
            int j = 0;

            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {

                    cout << board[i][j] << "  ";
                }cout << endl;
                }
        
            }

    void save(int size)
    {
        ofstream save;
        save.open("BasicGame.txt");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                save << board[i][j] << " ";
            }
            save << endl;
        }
    }
    void load(int size) {
        ifstream save;
        save.open("BasicGame.txt");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                save >> board[i][j];
            }
        
        }
    }
    void alternate(char &Player)
    {

        if (Player == 'X')//for alaternate selection of marks
        {
            Player = 'O';
        }
        else
        {
            Player = 'X';
        }
    }
    
        friend ostream& operator << (ostream& out, const ticTacToe&obj);
        
        ~ticTacToe()
        {
            for (int i = 0; i < size; i++) {
                
                delete[] board[i]; // delete sub array
            }
            delete[] board; //delete outer array
            board = NULL;
        };
    
};

ostream& operator << (ostream& out, const ticTacToe& obj) {
    
    for (int i = 0; i <obj.size; i++){
        for (int j = 0; j <obj.size; j++) {
            out << obj.board[i][j] << " ";
            
        }
    out << endl;}
    return out;
}
int main()
{
    bool gamecycle = false;
    bool game = false;
    char Player;
    char alphabet;
    int x,y;
    cout << "-----W-E-L-L-C-O-M-E----T-O------T-I-C-T-A-C-T-O-E------------" << endl << endl;;
    cout << "Read the instructions please: " << endl;
    cout << "press those keywords which you want to select from game to mark your move:" << endl;
    cout << "For example " << endl << endl;
    cout << "Table will be shown like this:" << endl;
    cout << " a  b  c" << endl;
    cout << " d  e  f " << endl;
    cout << " f  g  h " << endl;
    cout << "so to select press a,b,c" << endl;
    cout << "-------------" << endl;
    cout << "Enter the size" << endl;
    cin >> x;
    cout << "Press 1 To play a loaded game?" << endl;
    cout << "press 2 to play normally" << endl;
    cin >> y;
    if (y == 2) {
        ticTacToe myGame(x);
        myGame.SetBoard(x);
        cout << "First person will choose X or O"<<endl;
        cin >> Player;

        while (gamecycle == false)
        {
            
            //cout << myGame;
            myGame.PrintBoard(x);
            
            cout << endl << "Player " << Player << " "" << ""it's your turn: " << endl;
            cin >> alphabet;
            

            myGame.Turn(alphabet, Player);
            bool game2;
            game = myGame.CheckResult(Player, game);
            game2 = myGame.CheckDraw(game);
            myGame.save(x);
            if (game2 == true)
            {
                myGame.PrintBoard(x);
                system("pause");
                gamecycle = true;
                
            }
            myGame.alternate(Player);
            
            system("CLS");
        }

        system("pause");
    }
    if(y==1)
    {

        ticTacToe myGame(x);
        myGame.SetBoard(x);
        myGame.load(x);

        cout << "First person will choose X or O" << endl;
        cin >> Player;

        while (gamecycle == false)
        {

            //cout << myGame;
            myGame.PrintBoard(x);

            cout << endl << "Player " << Player << " "" << ""it's your turn: " << endl;
            cin >> alphabet;


            myGame.Turn(alphabet, Player);
            bool game2;
            game = myGame.CheckResult(Player, game);
            game2 = myGame.CheckDraw(game);

            if (game2 == true)
            {
                myGame.PrintBoard(x);
                system("pause");
                gamecycle = true;

            }
            myGame.alternate(Player);

            system("CLS");
        }

        system("pause");
    }
    return 0;
}
    





