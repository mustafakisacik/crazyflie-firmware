/**
 *    ||          ____  _ __                           
 * +------+      / __ )(_) /_______________ _____  ___ 
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2011-2018 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include <stdbool.h>

#define PLATFORM_DEVICE_TYPE_STRING_MAX_LEN (32 + 1)
#define PLATFORM_DEVICE_TYPE_MAX_LEN (4 + 1)

typedef enum {
  #ifdef SENSOR_INCLUDED_BMI088_BMP388
  SensorImplementation_bmi088_bmp388,
  #endif

  #ifdef SENSOR_INCLUDED_BMI088_SPI_BMP388
  SensorImplementation_bmi088_spi_bmp388,
  #endif

  #ifdef SENSOR_INCLUDED_MPU9250_LPS25H
  SensorImplementation_mpu9250_lps25h,
  #endif

  #ifdef SENSOR_INCLUDED_BOSCH
  SensorImplementation_bosch,
  #endif

  SensorImplementation_COUNT,
} SensorImplementation_t;

/**
 * Initilizes all platform specific things.
 */
int platformInit(void);

void platformGetDeviceTypeString(char* deviceTypeString);
int platformParseDeviceTypeString(const char* deviceTypeString, char* deviceType);

void platformSetLowInterferenceRadioMode(void);


// Functions to read configuration
const char* platformConfigGetPlatformName();
const char* platformConfigGetDeviceTypeName();
SensorImplementation_t platformConfigGetSensorImplementation();

#endif /* PLATFORM_H_ */
