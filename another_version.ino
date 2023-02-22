const int reed_pin = 2; // La broche numérique utilisée pour le capteur Reed
const float wheel_circumference = 2.07; // Le périmètre de votre roue en mètres

unsigned int time_old = 0;
unsigned int time_new = 0;
unsigned int time_period = 0;

void setup() {
  pinMode(reed_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  time_new = millis();
  if (digitalRead(reed_pin) == HIGH) {
    time_period = time_new - time_old;
    float velocity = wheel_circumference / time_period * 1000;
    Serial.print("Vitesse : ");
    Serial.print(velocity, 2);
    Serial.println(" km/s");
    time_old = time_new;
  }
}

voir https://www.notion.so/tchalifour91/Arduino-c72ffb1d797b4dceb189497f4a531612