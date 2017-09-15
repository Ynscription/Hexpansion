#ifndef MAP_H
#define MAP_H

#include <Entity.h>


class Map : public Entity
{
	public:
		Map();
		~Map();

		void update (sf::Time deltaTime) override;
		void fixedUpdate (sf::Time deltaTime) override;
		void render (sf::RenderTarget& renderer) override;

	private:

};

#endif // MAP_H
