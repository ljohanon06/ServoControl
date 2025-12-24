# ServoControl
ESP32-S3 Code and PCB design used for controlling up to 32 servos with 4 GPIO pins. Uses level shifters and d flip-flops on the pcb to control the servos. RMT is used on the ESP32-S3 to control the signals.

## How it works
![Diagram](docs/Media/Simulation_Annotated.png)
In the above simulation (simulation file is in hardware folder) there is an oscilliscope output with 3 signals labled clk, pulse, and servo. Also pictured are two 8-bit level shifters (SN74164) hooked together, with their outputs connected to two 8 bit D-flip-flop (SN74574). During each rising edge of the clk signal, the level of the servo signal is passed through the level shifter. Then at the rising edge of the pulse signal, those signals are copied into the D-flip-flop and is shown on the LEDs. As you can see, the white ellipses mark where the servo signal is high during a rising edge of clk and those signals are reflected in the LEDs.
