# ESP32-C6 LP I2C (Low Power) on Wokwi Example

ESP32-C6 Low Power example - using an I2C light sensor (BH1750) to wake up the chip from deep sleep + Wokwi simulation.

For more information about the example:

- [lp_i2c README](https://github.com/espressif/esp-idf/blob/master/examples/system/lp_core/lp_i2c/README.md)

## Running the project

1. Install [Wokwi Simulator Extension](https://marketplace.visualstudio.com/items?itemName=wokwi.wokwi-vscode) for Visual Studio Code.
2. Clone this repository and open it in Visual Studio Code.
3. Press "F1" and select "Wokwi: Start Simulator". If this is the first time you run the simulator, Wokwi will ask you to get a license
   and activate it.

## Rebuild the ESP-IDF Example

1. Install ESP-IDF from GitHub (master branch)
2. Go to examples/system/lp_core/lp_i2c
3. Run the following commands:
   ```bash
   idf.py set-target esp32c6
   idf.py build
   ```
4. Copy build/lp_i2c_example.elf to firmware/lp_i2c_example.elf in this repo.
