#include "level.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "randik.h"
Level::Level(){
  relative_path = "lefel\\";
  rules = new RuleSet();
}

Level::~Level(){

}
void Level::loadFromFile(std::string filename){
  std::ifstream file;
  std::string line;
  file.open(relative_path.append(filename).c_str());
  while (std::getline(file, line))
  {
    int pos;
    if(((pos = line.find(':'))!=-1))
    {
      std::string key = line.substr(0, pos);
      const char *value = line.substr(pos+1).c_str();
      if(key == "initial_velocity") rules->initial_velocity = atof(value);
      else if(key == "initial_words") rules->initial_words = atoi(value);
      else if(key ==  "max_velocity") rules->max_velocity = atof(value);
      else if(key ==  "max_word_amount") rules->max_word_amount = atoi(value);
      else if(key ==  "max_word_length") rules->max_word_length = atoi(value);
      else if(key ==  "increment_interval_velocity") rules->increment_interval_velocity = atof(value);
      else if(key ==  "increment_amount_velocity") rules->increment_amount_velocity = atof(value);
      else if(key ==  "increment_interval_words") rules->increment_interval_words = atof(value);
      else if(key ==  "increment_amount_words") rules->increment_amount_words = atof(value);
    }
    else{
      words.push_back(line);
    }
  }
  file.close();
}

std::string Level::pullRandomWord(time_t seed){
  Randik randik(seed);
  int pos = randik.getRandomInt(0, words.size());
  return words[pos];
}

