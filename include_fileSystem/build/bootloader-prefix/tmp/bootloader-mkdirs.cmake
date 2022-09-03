# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/maningchen/esp/esp-idf/components/bootloader/subproject"
  "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader"
  "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader-prefix"
  "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader-prefix/tmp"
  "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader-prefix/src"
  "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/maningchen/Desktop/web_course/ESP32-IDF/test3/template-app/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
