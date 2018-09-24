#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

class collision;

class collision{

    public:
        collision();
        ~collision();

		//takes bounding boxes of sprites and tiles and checks if they intersect
		//Then checks each corner of the rectangle to see which type of collision happened
		//such as top/bottem/left/right
        int check_Collision(sf::FloatRect BoundingBox1, sf::FloatRect BoundingBox2);

        //handles what needs to be done from bool involving objects
        void handle_collision();


	private:
		//returns bool if collision occured
		bool Collision = false;

		//Tilemap
		//Player
		//Enemy
		//Objects
		//Total Objects that can be collided with
		//T v P,  T v E, T v O, P v E, P v O, E v O
		//Bullet v E, Bullet V O, Bullet V view Bullet v Player

		//have ptrs for 2 objects that collided
		//so you can  handle collision of the two objects
		//Also Variable to Determine what type of Collision Occured

};

#endif // COLLISION_H
