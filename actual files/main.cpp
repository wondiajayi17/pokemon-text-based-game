#include <iostream>
#include <string>
#include <random>
#include "Pokemon.h"
#include "Pokemon_moves.h"
#include "battles.h"
#include "storyline.h"
using namespace std;


int main()
{   
    //create story object
    Story story;

    //call the first part of the story which will lead to the rest of the code
    story.storyPart1();
    
    return 0;
}
