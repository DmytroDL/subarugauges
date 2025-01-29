#define coolantsensorDivider 3307   //defines the resistor value that is in series in the voltage divider
#define coolantsensorPin A0         //defines the analog pin of the input voltage from the voltage divider
#define NUMSAMPLES 5                //defines the number of samples to be taken for a smooth average

const float steinconstA = 0.001281515579;        //steinhart equation constant A, determined from wikipedia equations
const float steinconstB = 0.0002636218288;       //steinhart equation constant B, determined from wikipedia equations
const float steinconstC = 0.0000001401344732;    //steinhart equation constant C, determined from wikipedia equations
int samples[NUMSAMPLES];                              //variable to store number of samples to be taken

void setup() {
  Serial.begin(9600);
}

void loop() {
  uint8_t i;                                          //integer for loop
  float average;                                      //decimal for average
  
  for (i=0; i<NUMSAMPLES; i++) {                      
    samples[i] = analogRead(coolantsensorPin);        //takes samples at number defined with a short delay between samples
    delay(10);
  }

  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
    average += samples[i];                            //adds all number of samples together
  }
  average /= NUMSAMPLES;                              //divides by number of samples to output the average
  average = (coolantsensorDivider*average)/(1023-average);        //conversion equation to read resistance from voltage divider

  float steinhart;                              //steinhart equation to estimate temperature value at any resistance from curve of thermistor sensor
  steinhart = log(average);                     //lnR
  steinhart = pow(steinhart,3);                 //(lnR)^3
  steinhart *= steinconstC;                     //C*((lnR)^3)
  steinhart += (steinconstB*(log(average)));    //B*(lnR) + C*((lnR)^3)
  steinhart += steinconstA;                     //Complete equation, 1/T=A+BlnR+C(lnR)^3
  steinhart = 1.0/steinhart;                    //Inverse to isolate for T
  steinhart -= 273.15;                          //Conversion from kelvin to celcius
  Serial.println("Temperature = "+ String(steinhart));
}
