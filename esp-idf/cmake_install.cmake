# Install script for directory: C:/Users/Matteo/esp/v5.2.1/esp-idf

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/TANWA-SLAVE-TEMPLATE")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/Matteo/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32s3-elf-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/xtensa/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_ringbuf/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/efuse/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_mm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/driver/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_pm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/mbedtls/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_bootloader_format/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_app_format/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/bootloader_support/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/bootloader/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esptool_py/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/partition_table/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_partition/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/app_update/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/spi_flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/pthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_system/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_rom/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/hal/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/log/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/heap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/soc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_hw_support/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/freertos/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/newlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/cxx/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_common/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_timer/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/app_trace/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_event/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/nvs_flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_phy/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/vfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/lwip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_netif_stack/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_netif/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/wpa_supplicant/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_coex/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_wifi/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/bt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/unity/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/cmock/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/console/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/http_parser/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp-tls/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_adc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_eth/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_gdbstub/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_hid/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/tcp_transport/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_http_client/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_http_server/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_https_ota/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_https_server/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_psram/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_lcd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/protobuf-c/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/protocomm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/esp_local_ctrl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/espcoredump/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/wear_levelling/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/sdmmc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/fatfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/idf_test/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/ieee802154/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/json/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/mqtt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/nvs_sec_provider/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/openthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/perfmon/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/spiffs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/touch_element/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/ulp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/usb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/wifi_provisioning/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/main/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/Board_Data/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/mcu_config/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/can/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/hardware/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/cli/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/config/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/control12V/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/control24V/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/control24V_SOL/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Matteo/Desktop/PWR_IN_SPACE/TANWA+8/TANWA-8-POWER/esp-idf/app/cmake_install.cmake")
endif()

