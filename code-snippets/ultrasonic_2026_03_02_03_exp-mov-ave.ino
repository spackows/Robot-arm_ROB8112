
// See:
// https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
// https://projecthub.arduino.cc/panagorko/next-level-ultrasonic-sensor-df5768
// https://www.google.com/search?q=arduino+how+to+smooth+sensor+data
// https://forum.arduino.cc/t/smooth-averaging-in-loop-simple-advice/868330
// https://forum.arduino.cc/t/smoothing-input-from-analog-accelerometer/10781/4
//

const int trig = 14;  
const int echo = 15; 

float duration, distance, oldest_distance, total, ave_distance;

const int num_readings = 10;
float readings[ num_readings ] = {0};
int read_index = 0;


void setup()
{
   pinMode( trig, OUTPUT );  
   pinMode( echo, INPUT  );  
   Serial.begin( 9600 );
}

void loop()
{
   sendPulse();

   noInterrupts(); 
   duration = pulseIn( echo, HIGH ); 
   interrupts(); 

   distance = ( duration * 0.0343 )/2;  

   Serial.print( "Distance: " );  
	//Serial.println( distance );  
   Serial.println( getAverageDistance( distance ) );
	delay( 100 );


}


void sendPulse()
{
   digitalWrite( trig, LOW );  
   delayMicroseconds( 2 );  
   digitalWrite( trig, HIGH );  
   delayMicroseconds( 10 );  
   digitalWrite( trig, LOW );  
}


float getAverageDistance( float newest_distance )
{
   //for( int i = 0; i < num_readings; i++ )
   //{
   //   Serial.print( readings[i] );
   //   Serial.print( " " );
   //}
   //Serial.println();

   //Serial.print( "Before: " );
   //Serial.println( readings[ read_index ] );

   oldest_distance = readings[ read_index ];
   readings[ read_index ] = newest_distance;

   //Serial.print( "After: " );
   //Serial.println( readings[ read_index ] );

   read_index = ( read_index >= ( num_readings - 1 ) ) ? 0 : read_index + 1;
   total = total - oldest_distance + newest_distance;
   ave_distance = total / num_readings;
   return ave_distance;
}
