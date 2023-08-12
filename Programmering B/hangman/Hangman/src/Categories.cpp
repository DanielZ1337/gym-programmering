#include "Categories.h"

using namespace std;

Categories::Categories()
{
    subject_category["Animals"] = vector<string> {"Amerikansk cocker spaniel","Persier","Iguana","Bjerg ged","Pepe"};
    subject_category["Countries"] = vector<string> {"Rusland","Danmark","Uzbekistan","Canada","Thailand"};
    subject_category["Clothing brands"] = vector<string> {"Adidas","Gucci","Nike","8848 Altitude","Champion"};
    subject_category["Minecraft blocks"] = vector<string> {"Stone","Bee nest","Honey block","Waxed Lightly Weathered Cut Copper Stairs","Grass Block","Golden Apple", "Apple", "Stick"};
    subject_category["Twitch Emotes"] = vector<string> {"PogChamp", "Kappa", "LUL", "MingLee", "haHAA", "bibleThump", "Pepega"};
}

Categories::~Categories()
{
    //dtor
}
