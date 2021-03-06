#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"
#include "NonCopyable.h"
#include "NonMoveable.h"

class ResourceHolder : public NonCopyable, public NonMovable {
  public:
	static ResourceHolder& get();

	ResourceManager<sf::Font> fonts;
	ResourceManager<sf::Texture> textures;
	ResourceManager<sf::SoundBuffer> soundBuffers;

  private:
	ResourceHolder();
};

#endif // RESOURCEHOLDER_H
