#pragma once

/// @file
/// @brief Class mbe::MusicComponent

#include <SFML/Audio/Music.hpp>

#include <MBE/Audio/BaseAudioComponent.h>

namespace mbe
{

	class MusicComponent : public BaseAudioComponent
	{
	public:
		typedef std::shared_ptr<MusicComponent> Ptr;
		typedef std::weak_ptr<MusicComponent> WPtr;
		typedef std::unique_ptr<MusicComponent> UPtr;

	public:
		MusicComponent(Entity & parentEntity);

		~MusicComponent() = default;

	public:
		void Update(sf::Time frameTime) override;

		void Update(sf::Time frameTime) override;

		void Play() override;

		void SetPaused(bool value = true) override;

		void Stop() override;

		void SetAttenuation(float value);

		void SetMinDistance(float value) override;

		void SetVolume(float value) override;

		void SetPitch(float value) override;

		void SetPlayingOffset(sf::Time offset) override;

		void SetLooped(bool value = true) override;

		float GetAttenuation() override;

		float GetMinDistance() override;

		float GetVolume() override;

		float GetPitch() override;

		sf::Time GetPlayingOffset() override;

		float IsLooped() override;

		// Is stopped valid?
		AudioStatus GetAudioStatus() override;

	private:
		sf::Music music;
	};

} // namespace mbe