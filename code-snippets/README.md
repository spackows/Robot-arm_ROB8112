

<table>
<tr><th>File</th><th>Description</th></tr>
<tr>
<td valign="top">
<p><a href="ultrasonic_2026_03_02_04_ints.ino">ultrasonic_2026_03_02_04_ints.ino</a></p>
<p><img src="../images/ultrasonic-circuit_2026-03-03.png" width="300"/></p>
</td>
<td valign="top">
<p>Prints distance measured by ultrasonic sensor in millimeters.  Uses Arduino <a href="https://docs.arduino.cc/language-reference/en/functions/interrupts/noInterrupts">noInterrupts()</a> to keep timing more accurate.  Using <a href="https://en.wikipedia.org/wiki/Exponential_smoothing">exponential smoothing</a> on the measurements.</p>
<ul>
<li>Link: <a href="https://www.handsontec.com/dataspecs/HC-SR04-Ultrasonic.pdf">HC-SR04 Ultrasonic Sensor Module</a></li>
<li>Alternative, array-based smoothing implementation: <a href="ultrasonic_2026_03_02_03_exp-mov-ave.ino">ultrasonic_2026_03_02_03_exp-mov-ave.ino</a></li>
</ul>
</td>
</tr>
<tr>
<td valign="top">
<p><a href="servo-dashboard_2026-03-03.ino">servo-dashboard_2026-03-03.ino</a></p>
<p><img src="../images/servo_00.png" width="300"/></p>
</td>
<td valign="top">
<p>Turns a servo motor in response to interraction with a dashboard</p>
<ul>
<li>Link: <a href="https://www.handsontec.com/dataspecs/HC-SR04-Ultrasonic.pdf">MG996R Metal Gear Servo Motor</a></li>
</ul>
<img src="../images/dashboard_servo_00.png" width="500" />
</td>
</tr>
</table>


