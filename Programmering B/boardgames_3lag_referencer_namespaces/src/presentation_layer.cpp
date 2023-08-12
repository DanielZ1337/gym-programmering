#include "presentation_layer.h"
#include <iostream>

namespace presentation
{

void display_best(std::string game)
{
    std::cout << "Best game according to BGG: " << game;
}
void print(const vector<int>& games){
    for(int k = 0; k < games.size(); k++){
        cout << games[k] << endl;
    }
}
void init(vector<int>& ranking, const vector<string>& games, vector<float>& geekrating, vector<float>& avgrating, vector<int>& numvote){
    for(int k = 0; k < ranking.size(); k++){
        cout << ranking[k] << ": ";
        cout << games[k] << "  ";
        cout << geekrating[k] << "  ";
        cout << avgrating[k] << "  ";
        cout << numvote[k] << "  ";
        cout << "\n";

    }
}
}
