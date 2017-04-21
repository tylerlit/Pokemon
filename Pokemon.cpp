//File: Pokemon.cpp
//Project: CMSC 202 Project 2, Fall 2016
//Author: Tyler Little
//Date: 10/16/2016
//Section 14
//Email: tyler10@umbc.edu


#include "Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//constructors
Pokemon::Pokemon(){}

Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity) {

  m_Num = num;
  m_Name = name;
  m_MinCP = cpMin;
  m_MaxCP = cpMax;
  m_Rarity = rarity;

}

//accessors
int Pokemon::GetCPMin() {

  return m_MinCP;

}

int Pokemon::GetCPMax() {

  return m_MaxCP;

}
int Pokemon::GetRarity() {

  return m_Rarity;

}

string Pokemon::GetName() {

  return m_Name;

}

int Pokemon::GetNum() {

  return m_Num;

}


//mutators
void Pokemon::SetRarity(int newRarity) {

  m_Rarity = newRarity;

}

void Pokemon::SetName(string newName) {

  m_Name = newName;

}

void Pokemon::SetCP(int newCP) {}
