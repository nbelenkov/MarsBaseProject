#pragma once

/// @file
/// @brief Class mbe::State

#include <iostream> // for error messages
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include <cassert>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/NonCopyable.hpp>

#include "AssetHolder.h"
#include "FilePathDictionary.h"

namespace mbe
{
	class StateManager;

	class State : private sf::NonCopyable
	{
		friend class StateManager;

	public:
		/// @brief Defines a State::Ptr for readability reasons
		typedef std::unique_ptr<State> Ptr;

		/// @brief Defines the type of id used for states
		typedef std::string ID;

	public:
		// Use refernces for the context --> so that it generates a copy constructor.....
		struct Context
		{
			// Constructor
			explicit Context(sf::RenderWindow & window, TextureWrapperHolder<std::string> & textures, SoundBufferHolder<std::string> & sounds, FontHolder<std::string> & fonts, FilePathDictionary<std::string> & musicFilePaths);
			Context(const Context & context) = default;

			sf::RenderWindow & window;
			TextureWrapperHolder<std::string> & textureWrappers;
			SoundBufferHolder<std::string> & sounds;
			FontHolder<std::string> & fonts;
			FilePathDictionary<std::string> & musicFilePaths;
		};

	// States can only be created by the state manager
	protected:
		/// @brief Constructor
		/// @param stateManager A reference to the mbe::StateManager that is used to push onto, pop from or clear the state stack
		/// @param context The Context containing global information that can be used by all states
		explicit State(StateManager & stateManager, Context context);

	public:
		/// @brief Virtual default destructor
		virtual ~State() = default;

		virtual bool HandleSFMLEvents(const sf::Event & event) = 0;
		virtual bool Update(sf::Time frameTime) = 0;
		virtual void Render() = 0;

	protected:
		StateManager & stateManager;
		Context context;
	};

} // namespace mbe