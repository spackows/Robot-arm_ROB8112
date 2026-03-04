
// See:
// https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
// https://projecthub.arduino.cc/panagorko/next-level-ultrasonic-sensor-df5768
// https://www.google.com/search?q=arduino+how+to+smooth+sensor+data
// https://forum.arduino.cc/t/smooth-averaging-in-loop-simple-advice/868330
// https://forum.arduino.cc/t/smoothing-input-from-analog-accelerometer/10781/4
//

const int TRIGGER_PIN = 14;  
const int ECHO_PIN = 15; 

float duration, distance;
int oldest_distance, total, ave_distance;

const int num_readings = 10;
int readings[ num_readings ] = {0};
int read_index = 0;


void setup()
{
   pinMode( TRIGGER_PIN, OUTPUT );  
   pinMode( ECHO_PIN, INPUT  );  
   Serial.begin( 9600 );
}

void loop()
{
   sendPulse();
   distance = receivePulse();
   ave_distance = getAverageDistance( distance );

   Serial.print( "Distance (mm): " );  
   Serial.println( ave_distance );
	delay( 100 );

}


void sendPulse()
{
   digitalWrite( TRIGGER_PIN, LOW );  
   delayMicroseconds( 2 );  
   digitalWrite( TRIGGER_PIN, HIGH );  
   delayMicroseconds( 10 );  
   digitalWrite( TRIGGER_PIN, LOW );  
}


float receivePulse()
{
   // https://docs.arduino.cc/language-reference/en/functions/interrupts/noInterrupts
   // https://docs.arduino.cc/language-reference/en/functions/advanced-io/pulseIn
   noInterrupts(); 
   duration = pulseIn( ECHO_PIN, HIGH ); 
   interrupts();

   // velocity = distance / time
   // -> distance = [ speed of sound (unit: mm/microseconds) ] * [ time (unit: microseconds) ]
   distance = ( 0.343 * duration )/2;  
   
   return distance;

}


float getAverageDistance( float newest_distance )
{
   oldest_distance = readings[ read_index ];
   readings[ read_index ] = (int)( 0.5 + newest_distance );

   //Serial.print( "After: " );
   //Serial.println( readings[ read_index ] );

   read_index = ( read_index >= ( num_readings - 1 ) ) ? 0 : read_index + 1;
   total = total - oldest_distance + newest_distance;
   ave_distance = (int) ( 0.5 + ( total / num_readings ) );
   return ave_distance;
}
