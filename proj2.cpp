//File: proj2.cpp
//Project: CMSC 202 Project 2, Fall 2016
//Author: Tyler Little
//Date: 10/16/2016
//Section 14
//Email: tyler10@umbc.edu

#include "proj2.h"

int main () {
  srand(10);
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu (pokeDex, myCollection);
  return 0;
}

void getPokeDex(vector<Pokemon> & pokeDex){

  ifstream myFile(POKEDEX);
  int num, minCP, maxCP, rarity;
  string name;

  while (myFile >> num >> name >> minCP >> maxCP >> rarity) {
    
    Pokemon *swagPtr = new Pokemon(num, name, minCP, maxCP, rarity);

    pokeDex.push_back(*swagPtr);

    delete swagPtr;
    swagPtr = 0;
  }

  myFile.close();
}

void getMyCollection(vector<MyPokemon> & myCollection){

  ifstream myFile(MYCOLLECTION);
  int num, cp, hp, rarity;
  string name;

  while (myFile >> num >> name >> cp >> hp >> rarity) {

    MyPokemon *swagPtr = new MyPokemon(num, name, cp, hp, rarity);
    
    myCollection.push_back(*swagPtr);

    delete swagPtr;
    swagPtr = 0;
  }

  myFile.close();
}

void printPokeDex(vector <Pokemon> & pokeDex){


  for (unsigned int i = 0; i < pokeDex.size(); i++) {
    
    cout << pokeDex[i].GetNum();
    cout << "\t" << pokeDex[i].GetName() << endl;

  }
  cout << "\n" << endl;
}

void printMyCollection(vector <MyPokemon> & myCollection){

  int listNumber = 0;
  
  cout << "\n" << endl;

  for (unsigned int i = 0; i < myCollection.size(); i++) {

    cout << listNumber << "."
	 << setw(5) << myCollection[i].GetNum()
	 << "\t" << myCollection[i].GetName()
	 << setw(6) << myCollection[i].GetCP()
	 << setw(5) << myCollection[i].GetHP()
	 << setw(5) << myCollection[i].GetRarity() << endl;

    listNumber++;
  }
  cout << "\n" << endl;
}

void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){

  int option = 0;
  bool chance;

  do {
  cout << "\n\nWhat type of Pokemon would you like to try and catch?" << endl;
  cout << "1. Very Common (Very High Probability)" << endl;
  cout << "2. Common (High Probability)" << endl;
  cout << "3. Uncommon (Normal Probability)" << endl;
  cout << "4. Rare (Low Probability)" << endl;
  cout << "5. Ultra Rare (Extremely Low Probability)" << endl;
  cin >> option;
  }while(option < 1 || option > 5);

  cout << "\nYou start to search..." << endl;
  
  //chance has a 65% chance of returning true for option 1,
  //45% chance for option 2, etc.
  if (option == 1) {    
    chance = (rand() % 100) < 65;
    if (chance){ 
      foundPokemon(option, pokeDex, myCollection);
    }
    else {
      cout << "Oh no! You couldn't find any pokemon :[ \n\n" << endl;
    }
  }
  if (option == 2) {
    chance = (rand() % 100) < 45;
    if (chance){
      foundPokemon(option, pokeDex, myCollection);
    }
    else {
      cout << "Oh no! You couldn't find any pokemon :[ \n\n" << endl;
    }
  }
  if (option == 3) {
    chance = (rand() % 100) < 25;
    if (chance){
      foundPokemon(option, pokeDex, myCollection);
    }
    else {
      cout << "Oh no! You couldn't find any pokemon :[ \n\n" << endl;
    }
  }
  if (option == 4) {
    chance = (rand() % 100) < 10;
    if (chance){
      foundPokemon(option, pokeDex, myCollection);
    }
    else {
      cout << "Oh no! You couldn't find any pokemon :[ \n\n" << endl;
    }
  }
  if (option == 5) {
    chance = (rand() % 100) < 1;
    if (chance){
      foundPokemon(option, pokeDex, myCollection);
    }
    else {
      cout << "Oh no! You couldn't find any pokemon :[ \n\n" << endl;
    }
  }
}

void foundPokemon(int rarity, vector <Pokemon> & pokeDex, 
		 vector<MyPokemon> & myCollection ){

  vector<Pokemon> rarityMatch;
  
  //collects all pokemon with the same rarity into one vector
  for (unsigned int i = 0; i < pokeDex.size(); i++){
    if (pokeDex[i].GetRarity() == rarity) 
      rarityMatch.push_back(pokeDex[i]);
  }

  unsigned int randomElement = rand() % rarityMatch.size();


  int combatPoints = rand() % rarityMatch[randomElement].GetCPMax() + 
		      rarityMatch[randomElement].GetCPMin();
  int hitPoints = (combatPoints * .1);

  cout << "Congratulations!! You found " << rarityMatch[randomElement].GetName() << "!!!\n\n" << endl;

  MyPokemon *newPokemon = new MyPokemon(rarityMatch[randomElement].GetNum(), 
					rarityMatch[randomElement].GetName(), 
					combatPoints, hitPoints, rarity);
  
  myCollection.push_back(*newPokemon);

  delete newPokemon;
  newPokemon = 0;
	   
}

void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){

  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 6);
  
    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);    
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}
 void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){

   int randomElement = rand() % pokeDex.size();
   int combatPoints = (rand() % pokeDex[randomElement].GetCPMax()) + pokeDex[randomElement].GetCPMin();
   int chosenElement;

   printMyCollection(myCollection);

   do{
   cout << "You're going to battle " << pokeDex[randomElement].GetName() << endl;
   cout << "who has a CP of " << combatPoints << endl;
   cout << "Who would you like to battle? : " << endl;
   cin >> chosenElement;
   }while (chosenElement < 0 || chosenElement > static_cast<int>(myCollection.size() - 1));
   
   if (myCollection[chosenElement].GetCP() > combatPoints)
     cout << "You won the battle!!!!!!\n" << endl;
   if (myCollection[chosenElement].GetCP() < combatPoints)
     cout << "You lost the battle :[ \n" << endl;
   if (myCollection[chosenElement].GetCP() == combatPoints){
     cout << "Your pokemon and the wild " << pokeDex[randomElement].GetName() << " have fought vigorously over the past 14 hours. You don't see any sign of either side backing down, and it is too dangerous to intervene. I GUESS YOU TIED!!" << endl;
   }
}

 void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   
   int option;

   printMyCollection(myCollection);

   do{
   cout << "Which of your Pokemon would you like to train? : "<< endl;
   cin >> option;
   }while (option < 0 || option > (static_cast<int>(myCollection.size()) - 1));

   // cant train over max cp
   if ((pokeDex[(myCollection[option].GetNum()) - 1].GetCPMax()) >= (myCollection[option].GetCP() + 10)){
     myCollection[option].SetCP(myCollection[option].GetCP() + 10);
   
     cout << "Your " << myCollection[option].GetName() << " has trained." << endl;
     cout << "Its CP is now " << myCollection[option].GetCP() << ".\n" << endl; 
   }
   else
     cout << myCollection[option].GetName() << " cannot train any more!\n" << endl;

}

 void exitPokemon(vector<MyPokemon> & myCollection){
   saveMyCollection(myCollection);
 }

void saveMyCollection(vector<MyPokemon> & myCollection){

  ofstream myFile(MYCOLLECTION);

  for (unsigned int i = 0; i < myCollection.size(); i++){

    myFile << myCollection[i].GetNum() << " " 
	   << myCollection[i].GetName() << " "
	   << myCollection[i].GetCP() << " "
	   << myCollection[i].GetHP() << " "
	   << myCollection[i].GetRarity() << endl;
  }
  myFile.close();

  cout << "File Saved" << endl;
  cout << "Thank you for playing UMBC Squirrel Simulator" << endl;
}
