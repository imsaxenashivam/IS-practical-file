#include <iostream>
#include<cctype>
#include<algorithm>
using namespace std;

main(){
string input;

cout << "Enter information to be encrypted" << endl;
getline(cin,input);
input.erase(std::remove (input.begin(), input.end(), ' '), input.end());

int columns = 6;
int rows;
  if (input.size() <= 5){
    rows = 1;
  }
  else if (input.size()% 5 > 0){
    rows = input.size()/5 + 1;
  }
  else
    rows = input.size()/5;

char message[rows][columns];
int place = 0;

    for(int i = 0; i < rows; i++){
      for(int j = 0; j < (columns-1); j++){
        if(place <= input.size()){
        message[rows][columns] = input[place];
        }
        else {
        message[rows][columns] = 'x';
        }
        place++;
        message[rows][5] = 'y';
        cout << message[rows][columns];
      }
        cout << endl;
    }


}