#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include "Map.h"



int main()
{
    Map map = Map("../map.txt");
    map.show();    
}
