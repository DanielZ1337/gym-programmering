#include <vector>
#include <string>
#include <iostream>
#include "data_layer.h"
#include "presentation_layer.h"
using namespace std;

int main()
{
    vector<string> games;
    vector<int> ranking;
    vector<float> geekrating;
    vector<float> avgrating;
    vector<int> numvote;

    try
    {
        games = data::get_games_from_file(ranking, geekrating, avgrating, numvote);
        presentation::init(ranking, games, geekrating, avgrating, numvote);
        presentation::display_best(games[0]);

    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
