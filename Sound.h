#pragma once
#include <Windows.h>

namespace Pharmacy {

	using namespace System;
	using namespace std;
	using namespace System::Windows::Forms;
	using namespace System::Media;
	using namespace System::IO;

	ref class Sounds
	{
	private:
		SoundPlayer^ player1 = gcnew SoundPlayer();
	public:
		Sounds() {}
		Sounds(SoundPlayer^ p) {
			this->player1 = gcnew SoundPlayer();
		}
		void Play() {
			player1->Load();
			player1->Play();
		}
		void Click() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "click.wav");
			Play();
		}
		void Keyboard() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "keyboard.wav");
			Play();
		}
		void Error() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "error.wav");
			Play();
		}
		void Stop() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "stop.wav");
			Play();
		}
		void Success() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "success.wav");
			Play();
		}
		void Welcome() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "welcome.wav");
			Play();
		}
		void Creator() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "creator.wav");
			Play();
		}
		void Notification() {
			player1->SoundLocation = Path::Combine(Application::StartupPath, "sounds", "notification.wav");
			Play();
		}
	};
}