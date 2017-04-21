//File: MyPokemon.cpp
//Project: CMSC 202 Project 2, Fall 2016
//Author: Tyler Little
//Date: 10/16/2016
//Section 14
//Email: tyler10@umbc.edu


#include "MyPokemon.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//constructors
MyPokemon::MyPokemon() {}

MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity) {

  m_Num = num;
  m_Name = name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;

}
 

//accessors
int MyPokemon::GetCP() {

  return m_CP;

}

int MyPokemon::GetHP() {

  return m_HP;

}

int MyPokemon::GetRarity() {

  return m_Rarity;

}

string MyPokemon::GetName() {

  return m_Name;

}

int MyPokemon::GetNum() {

  return m_Num;

}


//mutators
void MyPokemon::SetRarity(int newRarity){

  m_Rarity = newRarity;

}

void MyPokemon::SetName(string newName) {

  m_Name = newName;

}

void MyPokemon::SetCP(int newCP) {

  m_CP = newCP;

}

void MyPokemon::SetHP(int newHP) {

  m_HP = newHP;

}

//member function
void MyPokemon::Train() {

  m_CP += 10;

}
