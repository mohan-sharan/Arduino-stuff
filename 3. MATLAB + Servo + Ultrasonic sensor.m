clear 
a = arduino('COM7', 'Uno', 'Libraries', {'Servo', 'JRodrigoTech/HCSR04'});
ultrasonic_sensor = addon(a,'JRodrigoTech/HCSR04','D2','D3' );
servo_motor = servo(a,'D9');
p = 1;
table = zeros(180,2);
for angle = 0 : 1/180 : 1
    writePosition(servo_motor, angle);
    distance = readDistance(ultrasonic_sensor);
    writeDigitalPin(a, 'D6', 1); 
    writeDigitalPin(a, 'D7', 0);
    table(p,1) = (p-1);
    table(p,2) = round(distance * 100,2);
    p = p + 1;
end

q = 1; 
for angle = 1 : -1/180 : 0
    writePosition(servo_motor, angle);
    distance = readDistance(ultrasonic_sensor);
    writeDigitalPin(a, 'D6', 0);
    writeDigitalPin(a, 'D7', 1);
    table(p-q,2) = (table(p-q,2) + round(distance * 100,2))/2;
    q = q + 1;
end

polarplot (table(:,1)*pi/180, table (:,2));
title('Ultrasonic Sensor - Environment Map');
thetalim([0 180]);
grid on;