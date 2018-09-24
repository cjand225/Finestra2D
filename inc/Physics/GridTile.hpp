#ifndef GRIDTILE_H
#define GRIDTILE_H

#include <SFML/Graphics.hpp>

class gridTile{

    public:
        gridTile(int x, int y);
        ~gridTile();

        void setVertPos(int x, int y);
        void setTileID(int numID);

        void getAABB();                  //returns AABB for specific tile

    private:
        sf::VertexArray tileVertices;

        int tileID;
        int height;
        int width;



};




#endif // GRIDTILE_H
