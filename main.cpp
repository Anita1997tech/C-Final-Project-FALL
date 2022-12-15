#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void show_artist(vector<string> artistf1,vector<string> artistl2){
  cout << "The name of the artist: " << endl;
  for(int i = 0; i < artistf1.size(); i++){
    cout  << artistf1.at(i) << " " << artistl2.at(i) << endl;
  }
}

void show_making(vector<string> artistf1,vector<string> artistl2, vector<int> artist1making){
  cout << "The making of the artist: " << endl;
for(int i = 0; i < artistf1.size(); i++){
cout << artistf1.at(i) << " " << artistl2.at(i) <<" "<< artist1making.at(i) << " Millions " << endl;
}
}

void print_menu(){
    cout << "**************" << endl;
    cout << "The best selling artists of our time!" << endl;
    cout << " t - The artist" << endl;
    cout << " s - Show the artist making" << endl;
    cout << " f - Finish" << endl;
    cout << "**************" << endl;
    cout << " Enter your selection: " << endl;
}

void initialize_data(vector<string>& artistf1,vector<string>& artistl2, vector<int>& artist1making){
  
  ifstream docu;
  string temp_T;
  int temp_S;
  
  docu.open("myproject.txt");
  if(docu.is_open()){
    while(!docu.eof()){
      docu >> temp_T;
      artistf1.push_back(temp_T);
      docu >> temp_T;
      artistl2.push_back(temp_T);
      docu >> temp_S;
      artist1making.push_back(temp_S);

    }
    docu.close();
    cout << "Initialized" << artistf1.size() << " artist..." << endl;
  } else {
    cout << "There is something wrong with reading the file" << endl;
  }
}

void save_data(vector<string> artist1,vector<string> artist2, vector<int> artist1making){
  ofstream doout;
  doout.open("myproject.txt");
  if(doout.is_open()){
      for (int i = 0; i << artist1.size(); i++){
        doout << artist1.at(i) << "," << artist1making.at(i) << "," << artist2.at(i) << endl;
      }
      doout.close();
    } else {
      cout << "Error data not saved..." << endl;
    }
  }

int main(){
  char user_input;
  
  vector<string> artistf1;
  vector<string> artistl2;
  vector<int> artist1making;
  
  initialize_data(artistf1, artistl2, artist1making);
  
  do {
    print_menu();
    cin >> user_input;
    switch(user_input){
      case 't':
        show_artist(artistf1, artistl2);
        break;
      case 's':
        show_making(artistf1, artistl2, artist1making);
        break;
      case 'f':
        cout << "Thank you, Good bye!" << endl;
        save_data (artistf1, artistl2, artist1making);
        break;
      default:
        cout << "Error, Try again!" << endl;
    }
    
} while(user_input != 'F'); 
  
  return 0;
}