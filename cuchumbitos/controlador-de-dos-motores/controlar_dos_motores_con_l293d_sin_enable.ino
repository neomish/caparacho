/*
 *   Un L293D sin los pines de enable
 * 
 *     vcc  v_m2 +X2  gnd  gnd  -X2  g_m2
 *      |    |    |    |    |    |    |    |
 *   +--^----^----^----^----^----^----^----^---+
 *   | vcc1 in4  out4 gnd  gnd  out3 in3  en2  |
 *   |\                                        |
 *   | )      L293                             |
 *   |/                                        |
 *   | en1  in1  out1 gnd  gnd  out2 in2  vcc2 |
 *   +--v----v----v----v----v----v----v----v---+
 *      |    |    |    |    |    |    |    |
 *          v_m1 +X1  gnd  gnd  -X1  g_m1 vcc
 *  
 *    +------+        +---+        +------+
 *    |      |__ +X1  | U |  +X2 __|      |
 *  ==|  M1  |        |   |        |  M2  |==
 *    |      |__ -X1  |   |  -X2 __|      |
 *    +------+        +---+        +------+
 *  
 *   De LinUES para el mundo :)
 */

int v_m1 = 3;
int g_m1 = 5;
int v_m2 = 6;
int g_m2 = 9;
int led_1 = 13;
int led_2 = 12;

void mover_motor( int potencia , int x1 , int x2 ){
  if ( potencia > 255 ) {
    potencia = 255;
  }
  if ( potencia < -255 ) {
    potencia = -255;
  }
  if ( potencia == 0 ) {
    digitalWrite(x1,LOW);
    digitalWrite(x2,LOW);
  }
  if ( potencia > 0 ) {
    analogWrite(x1,potencia);
    digitalWrite(x2,LOW);
  }
  if ( potencia < 0) {
    potencia = 0 - potencia ;
    digitalWrite(x1,LOW);
    analogWrite(x2,potencia);
  }
}

void setup() {
  pinMode(v_m1,OUTPUT);
  pinMode(g_m1,OUTPUT);
  pinMode(v_m2,OUTPUT);
  pinMode(g_m2,OUTPUT);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
}
 
void loop(){
  mover_motor(255, v_m1, g_m1);
  mover_motor(255, v_m2, g_m2);
  digitalWrite(led_1, HIGH);
  delay(1000);
  digitalWrite(led_1, LOW);
  mover_motor(0, v_m1, g_m1);
  mover_motor(0, v_m2, g_m2);
  delay(500);
  mover_motor(-255, v_m1, g_m1);
  mover_motor(-255, v_m2, g_m2);
  digitalWrite(led_2, HIGH);
  delay(1000);
  digitalWrite(led_2, LOW);
  mover_motor(0, v_m1, g_m1);
  mover_motor(0, v_m2, g_m2);
  delay(500);
}
