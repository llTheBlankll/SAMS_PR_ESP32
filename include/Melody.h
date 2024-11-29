#ifndef MELODY_H
#define MELODY_H

#include <Arduino.h>
#include <Melodies.h>

class Melody
{
public:
	Melody(const uint8_t BUZZER_PIN);
	void play();
	void play(String songName);
	void setTempo(int tempo);
	void setSongName(String songName);
private:
	int tempo;
	int *melody;
	String songName;
	const uint8_t buzzerPin;
};

#endif
