#include <Melody.h>

Melody::Melody(const uint8_t BUZZER_PIN) : buzzerPin(BUZZER_PIN)
{
	// Default constructor
}

void Melody::play()
{
	if (songName == "mario")
	{
		melody = marioMelody;
		tempo = MARIO_TEMPO;
	}
	else if (songName == "tetris")
	{
		melody = tetrisTheme;
		tempo = TETRIS_TEMPO;
	}
	else
	{
		return;
	}

	// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
	// there are two values per note (pitch and duration), so for each note there are four bytes
	int notes = sizeof(marioMelody) / sizeof(marioMelody[0]) / 2;

	// this calculates the duration of a whole note in ms
	int wholenote = (60000 * 4) / tempo;

	int divider = 0, noteDuration = 0;
	// iterate over the notes of the melody.
	// Remember, the array is twice the number of notes (notes + durations)
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
	{
		// calculates the duration of each note
		divider = melody[thisNote + 1];
		if (divider > 0)
		{
			// regular note, just proceed
			noteDuration = (wholenote) / divider;
		}
		else if (divider < 0)
		{
			// dotted notes are represented with negative durations!!
			noteDuration = (wholenote) / abs(divider);
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}

		// we only play the note for 90% of the duration, leaving 10% as a pause
		tone(buzzerPin, melody[thisNote], noteDuration * 0.9);

		// Wait for the specified duration before playing the next note.
		delay(noteDuration);

		// stop the waveform generation before the next note.
		noTone(buzzerPin);
	}
}

void Melody::setTempo(int tempo)
{
	this->tempo = tempo;
}

void Melody::setSongName(String songName)
{
	this->songName = songName;
}
