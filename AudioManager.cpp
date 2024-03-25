#include "AudioManager.h"
#include <cassert>

namespace AudioManager {

	int confirmSound;
	int gunSound;
	int killSound;

	void AudioManager::PlayConfirmSound(){
		confirmSound =  Audio::Load("Sounds/Confirm.wav");
		assert(confirmSound >= 0);
		Audio::Play(confirmSound);

	}

	void PlayGunSound(){
		gunSound = Audio::Load("Sounds/Œe‚ðŒ‚‚Â.wav",false,10);
		assert(gunSound >= 0);
		Audio::Play(gunSound);
	}

	void PlayKillSound()
	{
		killSound = Audio::Load("Sounds/Jump.wav", false, 10);
		assert(killSound >= 0);
		Audio::Play(killSound);
	}

}
