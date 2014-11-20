#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>


#endif // LEVEL_H

class RuleSet{
public:
  double initial_velocity = 0.0;
  int initial_words = 0;
  double max_velocity = 0.0;
  int max_word_amount = 0;
  int max_word_length = 0;
  int min_word_length = 0;
  double increment_interval_velocity = 0.0;
  double increment_amount_velocity = 0.0;
  double increment_interval_words = 0.0;
  double increment_amount_words = 0.0;
};

class Level{
private:

  std::vector<std::string> words;
  std::string relative_path;
public:

  Level();
  ~Level();
  RuleSet *rules;
  void loadFromFile(std::string filename);
  std::string pullRandomWord(time_t seed);
};
