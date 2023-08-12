#ifndef PRESENTATION_LAYER_H
#define PRESENTATION_LAYER_H

#include <vector>
#include <string>

using namespace std;

namespace presentation
{
void display_best(std::string input);
void print(const vector<int>& games);
void init(vector<int>& ranking, const vector<string>& games, vector<float>& geekrating, vector<float>& avgrating, vector<int>& numvote);
}

#endif // PRESENTATION_LAYER_H
