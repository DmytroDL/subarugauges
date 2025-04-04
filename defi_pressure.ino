int mapsen = 1; // Set sensor input on Analog port 0
int NUM_SAMPLES= 300;  // number of samples
float sum = 0;         // sum of samples taken
int sample_count = 0; // current sample number
float input_voltage = 5; //measured with multimeter

void setup() {
 Serial.begin(9600);
}
void loop() {
  sum = 0;
  sample_count = 0;
  while (sample_count <= NUM_SAMPLES) {
        sum += float(analogRead(mapsen));
        sample_count++;
        delay(1);
    }   
 float out_voltage = (sum / NUM_SAMPLES * input_voltage) / 1024;
 float P = out_voltage*12.5/input_voltage-1.25; //pressure in bar
 Serial.println(P);
}