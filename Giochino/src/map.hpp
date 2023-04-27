//
//  map.hpp
//  main
//
//  Created by Francesco Esposito on 22/03/23.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>
using namespace std;

class Map{
public:
	Map();
    Map (int colonna, int riga);
    void draw(int x, int y, char P);
    void canc(int x, int y, char P);


};
#endif /* map_hpp */
