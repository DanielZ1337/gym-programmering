#ifndef DATA_LAYER_H
#define DATA_LAYER_H

#include <string>
#include <vector>

namespace data
{
using namespace std;
std::vector<std::string> get_games_from_file(vector<int>& ranking, vector<float>& geekrating, vector<float>& avgrating, vector<int>& numvote);

}

#endif // DATA_LAYER_H
