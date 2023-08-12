#ifndef CATEGORIES_H
#define CATEGORIES_H
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Categories
{
    public:
        Categories();
        virtual ~Categories();
        map<string,vector<string>> subject_category;

    protected:

    private:

};

#endif // CATEGORIES_H
