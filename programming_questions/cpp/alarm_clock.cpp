#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <chrono>
#include <iostream>
#include <thread>

void playSound();

int main() {
  int hours, minutes, seconds;
  std::cout << "Enter the time you wanna set a timer for: Hours:";
  std::cin >> hours;
  std::cout << "minutes: ";
  std::cin >> minutes;
  std::cout << "seconds: ";
  std::cin >> seconds;

  int total_time_in_seconds = (hours * 3600) + (minutes * 60) + seconds;

  if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 1;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: "
              << Mix_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  std::string command{};
  std::this_thread::sleep_for(std::chrono::seconds(total_time_in_seconds));
  if (total_time_in_seconds >= 0) {
    playSound();
  } else {
    std::cout << "Please enter valid seconds" << std::endl;
  }

  Mix_CloseAudio();
  SDL_Quit();

  return 0;
}

void playSound() {
  Mix_Chunk *sound = Mix_LoadWAV("./Alarm_Clock.wav");

  if (sound == nullptr) {
    std::cerr << "Failed to load sound file! SDL_mixer Error: "
              << Mix_GetError() << std::endl;
    return;
  }

  if (Mix_PlayChannel(-1, sound, 0) == -1) {
    std::cerr << "Failed to play sound! SDL_mixer Error: " << Mix_GetError()
              << std::endl;
    Mix_FreeChunk(sound);
    return;
  }

  std::this_thread::sleep_for(
      std::chrono::milliseconds(3000)); // Adjust this value as needed

  Mix_FreeChunk(sound);
}
