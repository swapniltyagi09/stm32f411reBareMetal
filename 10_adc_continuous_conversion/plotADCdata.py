import serial
import matplotlib.pyplot as plt
import numpy as np

# Open Serial Port
ser = serial.Serial('/dev/ttyACM0', 115200)  # Adjust port & baudrate

# Initialize Plot
plt.ion()
fig, ax = plt.subplots()
x_data, y_data = [], []
counter = 0

while True:
    try:
        # Read sensor value
        data = ser.readline().strip()
        if data:
            sensor_value = int(data)
            
            # Update Plot Data
            x_data.append(counter)
            y_data.append(sensor_value)
            counter+= 1
            
            # Limit data points
    
            if len(x_data) > 100:
                x_data.pop(0)
                y_data.pop(0)

            # Plot
            ax.clear()
            ax.plot(x_data, y_data, marker='o', linestyle='-')
            ax.set_title("Live ADC Data")
            ax.set_xlabel("Time Step")
            ax.set_ylabel("Sensor Value")

            plt.pause(0.01)
    
    except KeyboardInterrupt:
        break

ser.close()
