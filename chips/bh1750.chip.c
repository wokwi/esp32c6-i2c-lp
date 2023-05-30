// Wokwi Custom Chip - For information and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2022 Uri Shaked / wokwi.com

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

const int ADDRESS = 0x23;

typedef struct {
  uint32_t read_value;
  uint32_t read_index;
  uint32_t lux_attr;
} chip_state_t;

static bool on_i2c_connect(void *user_data, uint32_t address, bool connect);
static uint8_t on_i2c_read(void *user_data);
static bool on_i2c_write(void *user_data, uint8_t data);

void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  chip->read_value = 0;
  chip->read_index = 0;

  const i2c_config_t i2c_config = {
    .user_data = chip,
    .address = ADDRESS,
    .scl = pin_init("SCL", INPUT_PULLUP),
    .sda = pin_init("SDA", INPUT_PULLUP),
    .connect = on_i2c_connect,
    .read = on_i2c_read,
    .write = on_i2c_write
  };
  i2c_init(&i2c_config);

  // This attribute can be edited by the user. It's defined in wokwi-custom-part.json:
  chip->lux_attr = attr_init("lux", 127);

  // The following message will appear in the browser's DevTools console:
  printf("Hello from light sensor!\n");
}

bool on_i2c_connect(void *user_data, uint32_t address, bool connect) {
  chip_state_t *chip = user_data;
  uint32_t lux = attr_read(chip->lux_attr);
  chip->read_value = (lux * 12 + 11) / 10;
  chip->read_index = 0;
  return true; /* Ack */
}

uint8_t on_i2c_read(void *user_data) {
  chip_state_t *chip = user_data;
  uint8_t result = 0;
  switch (chip->read_index) {
    case 0:
      result = (chip->read_value >> 8) & 0xff;
      break;
    case 1:
      result = chip->read_value & 0xff;
      break;
  }
  chip->read_index++;
  return result;
}

bool on_i2c_write(void *user_data, uint8_t data) {
  return true; // Ack
}
