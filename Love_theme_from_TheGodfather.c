//Godfather
#define C3 131
#define C3s 139
#define D3 147
#define D3s 156
#define E3 165
#define F3 175
#define F3s 185
#define G3 196
#define G3s 208
#define A3 220
#define A3s 233
#define B3 247
#define C4 262
#define C4s 277
#define D4 294
#define D4s 311
#define E4 330
#define F4 349
#define F4s 370
#define G4 392
#define G4s 415
#define A4 440
#define A4s 466
#define B4 494
#define C5 523
#define C5s 554
#define D5 587
#define D5s 622
#define E5 659
#define F5 698
#define F5s 740
#define G5 784
#define G5s 831
#define A5 880
#define A5s 932
#define B5 988
#define C6 1047
uint32_t CLOCK = 10500000;
unsigned int notes[] = {
                        G3,C4,D4s,D4,C4,D4s,C4,D4,C4,G3s,A3s,G3,
                        G3,C4,D4s,D4,C4,D4s,C4,D4,C4,G3,F3s,F3,
                        F3,G3s,B3,D4,  F3,G3s,B3,C4,
                        C4,D4s,A4s,G4s,G4,A4s,G4s,G4s,G4,G4,B3,C4,
                        C5,C5,B4,A4s,  A4s,D5,C5,G4s,G4,
                        G4,A4s,G4,F4,  F4,G4s,G4,F4,G4
                        };
unsigned int duration[] = {
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 
                          1, 1, 1, 5,    1, 1, 1, 4,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5,
                          1, 1, 1, 3,  1, 2, 1, 1, 4,
                          1, 1, 1, 3,  1, 2, 1, 1, 4
                          };
