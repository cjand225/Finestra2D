#ifndef GRID_H
#define GRID_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "GridTile.hpp"

class grid{

    public:
        grid(int height, int width, int X, int Y);
        ~grid();

    private:
        std::vector<gridTile*>  gridTiles;

};

#endif // GRID_H
