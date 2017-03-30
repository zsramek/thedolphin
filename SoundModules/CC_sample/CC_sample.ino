#include <avr/pgmspace.h>
#include <avr/sleep.h>
#define adc_disable()  (ADCSRA &= ~(1<<ADEN))

boolean clicked0 = false;

// Audio encoded as unsigned 8-bit, 8kHz sampling rate
const char sample[] PROGMEM = {
  0x81, 0x85, 0x87, 0x88, 0x87, 0x85, 0x83, 0x82, 0x82, 0x7f, 0x7e, 0x7c,
  0x7a, 0x7a, 0x7b, 0x72, 0x6b, 0x4d, 0x0e, 0x10, 0x1b, 0x1e, 0x21, 0x26,
  0x2e, 0x35, 0x3f, 0x4c, 0x5a, 0x6a, 0x79, 0x89, 0x9a, 0xa9, 0xb3, 0xbc,
  0xc2, 0xc3, 0xc6, 0xc7, 0xc6, 0xc1, 0xbc, 0xb5, 0xab, 0x9f, 0x91, 0x81,
  0x73, 0x65, 0x55, 0x46, 0x3a, 0x34, 0x31, 0x2c, 0x28, 0x2b, 0x2f, 0x34,
  0x3c, 0x46, 0x56, 0x65, 0x74, 0x83, 0x90, 0x9c, 0xa8, 0xb2, 0xbb, 0xc2,
  0xc4, 0xc6, 0xc7, 0xc8, 0xc8, 0xc5, 0xc2, 0xbe, 0xb9, 0xb1, 0xa7, 0x9c,
  0x90, 0x85, 0x7a, 0x6c, 0x5f, 0x51, 0x44, 0x3a, 0x34, 0x30, 0x2d, 0x2b,
  0x2b, 0x2c, 0x2f, 0x33, 0x39, 0x3f, 0x49, 0x55, 0x62, 0x6f, 0x7c, 0x87,
  0x91, 0x9c, 0xa5, 0xae, 0xb6, 0xbd, 0xc1, 0xc4, 0xc6, 0xc8, 0xc9, 0xc9,
  0xc8, 0xc6, 0xc4, 0xc1, 0xbe, 0xb9, 0xb3, 0xab, 0xa3, 0x9a, 0x91, 0x88,
  0x7e, 0x74, 0x69, 0x5e, 0x54, 0x4a, 0x41, 0x3b, 0x37, 0x34, 0x31, 0x30,
  0x2e, 0x2e, 0x30, 0x33, 0x36, 0x3a, 0x3e, 0x43, 0x4b, 0x54, 0x5e, 0x68,
  0x72, 0x7c, 0x85, 0x8e, 0x96, 0x9e, 0xa5, 0xac, 0xb3, 0xb9, 0xbe, 0xc1,
  0xc3, 0xc5, 0xc6, 0xc7, 0xc7, 0xc8, 0xc7, 0xc6, 0xc4, 0xc3, 0xc1, 0xbe,
  0xbb, 0xb7, 0xb2, 0xac, 0xa6, 0x9f, 0x98, 0x91, 0x89, 0x82, 0x7a, 0x72,
  0x6a, 0x62, 0x59, 0x51, 0x4a, 0x43, 0x3e, 0x3b, 0x38, 0x36, 0x34, 0x33,
  0x32, 0x31, 0x31, 0x33, 0x35, 0x38, 0x3b, 0x3e, 0x41, 0x45, 0x4a, 0x51,
  0x58, 0x60, 0x68, 0x70, 0x77, 0x7f, 0x86, 0x8d, 0x93, 0x99, 0x9f, 0xa5,
  0xaa, 0xb0, 0xb4, 0xb9, 0xbd, 0xbf, 0xc2, 0xc3, 0xc4, 0xc5, 0xc5, 0xc6,
  0xc6, 0xc6, 0xc6, 0xc5, 0xc4, 0xc2, 0xc1, 0xbf, 0xbd, 0xbb, 0xb9, 0xb6,
  0xb2, 0xae, 0xa9, 0xa4, 0x9e, 0x99, 0x94, 0x8e, 0x89, 0x83, 0x7d, 0x77,
  0x71, 0x6b, 0x65, 0x5f, 0x59, 0x53, 0x4d, 0x48, 0x43, 0x40, 0x3d, 0x3b,
  0x39, 0x38, 0x37, 0x36, 0x35, 0x35, 0x34, 0x35, 0x37, 0x38, 0x3a, 0x3c,
  0x3e, 0x41, 0x43, 0x47, 0x4a, 0x4e, 0x53, 0x59, 0x5e, 0x65, 0x6b, 0x71,
  0x77, 0x7c, 0x82, 0x87, 0x8d, 0x92, 0x96, 0x9b, 0xa0, 0xa4, 0xa8, 0xac,
  0xb0, 0xb4, 0xb7, 0xba, 0xbd, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc3, 0xc4,
  0xc4, 0xc4, 0xc4, 0xc4, 0xc4, 0xc3, 0xc2, 0xc1, 0xc0, 0xbe, 0xbd, 0xbc,
  0xba, 0xb8, 0xb7, 0xb4, 0xb2, 0xaf, 0xab, 0xa8, 0xa4, 0xa0, 0x9c, 0x98,
  0x93, 0x8f, 0x8b, 0x87, 0x82, 0x7e, 0x79, 0x74, 0x70, 0x6b, 0x67, 0x62,
  0x5d, 0x58, 0x54, 0x4f, 0x4b, 0x48, 0x45, 0x42, 0x40, 0x3e, 0x3d, 0x3c,
  0x3b, 0x3a, 0x3a, 0x39, 0x39, 0x39, 0x38, 0x39, 0x3a, 0x3b, 0x3d, 0x3e,
  0x40, 0x42, 0x43, 0x45, 0x47, 0x4a, 0x4c, 0x4f, 0x53, 0x56, 0x5a, 0x5f,
  0x64, 0x68, 0x6d, 0x72, 0x77, 0x7b, 0x80, 0x84, 0x88, 0x8c, 0x90, 0x94,
  0x98, 0x9b, 0x9f, 0xa2, 0xa5, 0xa9, 0xac, 0xaf, 0xb1, 0xb4, 0xb6, 0xb9,
  0xbb, 0xbc, 0xbe, 0xbe, 0xbf, 0xc0, 0xc0, 0xc0, 0xc1, 0xc1, 0xc1, 0xc1,
  0xc1, 0xc0, 0xc0, 0xc0, 0xbf, 0xbe, 0xbd, 0xbc, 0xbb, 0xba, 0xb9, 0xb8,
  0xb6, 0xb5, 0xb3, 0xb2, 0xb0, 0xae, 0xab, 0xa9, 0xa6, 0xa3, 0xa0, 0x9d,
  0x99, 0x96, 0x93, 0x90, 0x8c, 0x89, 0x85, 0x82, 0x7f, 0x7b, 0x78, 0x74,
  0x71, 0x6d, 0x69, 0x66, 0x62, 0x5f, 0x5b, 0x58, 0x54, 0x51, 0x4e, 0x4b,
  0x49, 0x47, 0x46, 0x44, 0x43, 0x42, 0x42, 0x41, 0x41, 0x41, 0x40, 0x40,
  0x40, 0x40, 0x40, 0x40, 0x41, 0x42, 0x43, 0x45, 0x46, 0x47, 0x49, 0x4a,
  0x4c, 0x4e, 0x4f, 0x51, 0x53, 0x55, 0x58, 0x5b, 0x5e, 0x61, 0x64, 0x68,
  0x6c, 0x6f, 0x73, 0x77, 0x7a, 0x7e, 0x81, 0x85, 0x88, 0x8b, 0x8e, 0x91,
  0x94, 0x97, 0x9a, 0x9c, 0x9f, 0xa2, 0xa4, 0xa7, 0xa9, 0xab, 0xad, 0xaf,
  0xb1, 0xb3, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xb9, 0xba, 0xba, 0xba, 0xba,
  0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xb9, 0xb9, 0xb8, 0xb7, 0xb7,
  0xb6, 0xb5, 0xb4, 0xb3, 0xb2, 0xb1, 0xb0, 0xaf, 0xae, 0xac, 0xab, 0xa9,
  0xa7, 0xa6, 0xa3, 0xa1, 0x9f, 0x9c, 0x9a, 0x98, 0x95, 0x93, 0x90, 0x8d,
  0x8b, 0x88, 0x86, 0x83, 0x80, 0x7e, 0x7b, 0x78, 0x76, 0x73, 0x70, 0x6e,
  0x6b, 0x68, 0x65, 0x63, 0x60, 0x5d, 0x5b, 0x58, 0x56, 0x54, 0x52, 0x51,
  0x4f, 0x4e, 0x4d, 0x4d, 0x4c, 0x4c, 0x4b, 0x4b, 0x4b, 0x4b, 0x4a, 0x4a,
  0x4a, 0x4a, 0x4a, 0x4b, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x53,
  0x54, 0x55, 0x56, 0x58, 0x59, 0x5b, 0x5d, 0x5f, 0x61, 0x63, 0x65, 0x68,
  0x6b, 0x6e, 0x70, 0x73, 0x76, 0x79, 0x7c, 0x7e, 0x81, 0x84, 0x86, 0x89,
  0x8b, 0x8d, 0x8f, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9d, 0x9f, 0xa1,
  0xa3, 0xa4, 0xa6, 0xa7, 0xa8, 0xaa, 0xab, 0xac, 0xad, 0xad, 0xae, 0xae,
  0xae, 0xae, 0xaf, 0xaf, 0xaf, 0xaf, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae,
  0xad, 0xad, 0xad, 0xac, 0xab, 0xab, 0xaa, 0xaa, 0xa9, 0xa8, 0xa7, 0xa7,
  0xa6, 0xa5, 0xa4, 0xa3, 0xa2, 0xa1, 0xa0, 0x9e, 0x9d, 0x9b, 0x99, 0x98,
  0x96, 0x94, 0x92, 0x90, 0x8e, 0x8c, 0x8b, 0x89, 0x87, 0x85, 0x83, 0x81,
  0x7f, 0x7d, 0x7b, 0x79, 0x77, 0x75, 0x73, 0x71, 0x6f, 0x6d, 0x6b, 0x69,
  0x67, 0x65, 0x63, 0x61, 0x5f, 0x5e, 0x5c, 0x5b, 0x5a, 0x59, 0x58, 0x58,
  0x57, 0x57, 0x57, 0x56, 0x56, 0x56, 0x56, 0x56, 0x56, 0x56, 0x56, 0x56,
  0x56, 0x56, 0x57, 0x58, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x60, 0x61, 0x62, 0x63, 0x64, 0x66, 0x67, 0x69, 0x6b, 0x6d, 0x6f, 0x71,
  0x73, 0x75, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x87, 0x89,
  0x8b, 0x8c, 0x8e, 0x90, 0x91, 0x93, 0x94, 0x96, 0x97, 0x98, 0x99, 0x9b,
  0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0xa2, 0xa3, 0xa3, 0xa4, 0xa4,
  0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa3,
  0xa3, 0xa3, 0xa3, 0xa2, 0xa2, 0xa1, 0xa1, 0xa0, 0x9f, 0x9f, 0x9e, 0x9e,
  0x9d, 0x9d, 0x9c, 0x9b, 0x9a, 0x9a, 0x99, 0x98, 0x97, 0x95, 0x94, 0x93,
  0x92, 0x90, 0x8f, 0x8d, 0x8c, 0x8b, 0x89, 0x88, 0x86, 0x85, 0x83, 0x82,
  0x80, 0x7f, 0x7d, 0x7c, 0x7a, 0x79, 0x77, 0x76, 0x74, 0x73, 0x71, 0x70,
  0x6e, 0x6c, 0x6b, 0x69, 0x68, 0x67, 0x65, 0x64, 0x63, 0x62, 0x62, 0x61,
  0x60, 0x60, 0x60, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f,
  0x5f, 0x5f, 0x5f, 0x5f, 0x60, 0x60, 0x61, 0x62, 0x62, 0x63, 0x64, 0x64,
  0x65, 0x66, 0x67, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6e, 0x6f, 0x70,
  0x72, 0x74, 0x75, 0x77, 0x79, 0x7a, 0x7c, 0x7d, 0x7f, 0x81, 0x82, 0x84,
  0x85, 0x86, 0x88, 0x89, 0x8a, 0x8b, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92,
  0x93, 0x94, 0x95, 0x96, 0x97, 0x97, 0x98, 0x99, 0x99, 0x9a, 0x9a, 0x9b,
  0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9c, 0x9b, 0x9b, 0x9b,
  0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9a, 0x9a, 0x9a, 0x99, 0x99, 0x98, 0x98,
  0x98, 0x97, 0x97, 0x96, 0x96, 0x95, 0x95, 0x94, 0x93, 0x93, 0x92, 0x91,
  0x90, 0x8f, 0x8e, 0x8d, 0x8c, 0x8b, 0x8a, 0x89, 0x88, 0x87, 0x85, 0x84,
  0x83, 0x82, 0x81, 0x80, 0x7f, 0x7e, 0x7c, 0x7b, 0x7a, 0x79, 0x78, 0x77,
  0x75, 0x74, 0x73, 0x72, 0x71, 0x70, 0x6e, 0x6d, 0x6c, 0x6b, 0x6a, 0x69,
  0x69, 0x68, 0x68, 0x67, 0x67, 0x67, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x67, 0x67, 0x67, 0x68, 0x68,
  0x69, 0x69, 0x6a, 0x6b, 0x6b, 0x6c, 0x6c, 0x6d, 0x6e, 0x6f, 0x6f, 0x70,
  0x71, 0x72, 0x73, 0x75, 0x76, 0x77, 0x78, 0x7a, 0x7b, 0x7c, 0x7d, 0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b,
  0x8c, 0x8c, 0x8d, 0x8e, 0x8f, 0x8f, 0x90, 0x91, 0x91, 0x92, 0x93, 0x93,
  0x94, 0x94, 0x94, 0x94, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95,
  0x95, 0x95, 0x95, 0x95, 0x95, 0x94, 0x94, 0x94, 0x94, 0x94, 0x93, 0x93,
  0x93, 0x93, 0x92, 0x92, 0x92, 0x91, 0x91, 0x91, 0x90, 0x90, 0x8f, 0x8f,
  0x8e, 0x8e, 0x8d, 0x8d, 0x8c, 0x8b, 0x8a, 0x8a, 0x89, 0x88, 0x87, 0x86,
  0x85, 0x84, 0x84, 0x83, 0x82, 0x81, 0x80, 0x7f, 0x7e, 0x7d, 0x7d, 0x7c,
  0x7b, 0x7a, 0x79, 0x78, 0x77, 0x76, 0x75, 0x74, 0x73, 0x73, 0x72, 0x71,
  0x70, 0x6f, 0x6f, 0x6e, 0x6e, 0x6d, 0x6d, 0x6d, 0x6c, 0x6c, 0x6c, 0x6c,
  0x6c, 0x6c, 0x6c, 0x6c, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6c, 0x6c, 0x6c,
  0x6c, 0x6d, 0x6d, 0x6e, 0x6e, 0x6e, 0x6f, 0x6f, 0x70, 0x70, 0x71, 0x71,
  0x72, 0x72, 0x73, 0x74, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b,
  0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x81, 0x82, 0x83, 0x84, 0x85, 0x85,
  0x86, 0x87, 0x88, 0x88, 0x89, 0x89, 0x8a, 0x8b, 0x8b, 0x8c, 0x8c, 0x8d,
  0x8d, 0x8e, 0x8e, 0x8e, 0x8f, 0x8f, 0x8f, 0x8f, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8f, 0x8f, 0x8f,
  0x8f, 0x8f, 0x8f, 0x8e, 0x8e, 0x8e, 0x8e, 0x8d, 0x8d, 0x8d, 0x8d, 0x8c,
  0x8c, 0x8c, 0x8b, 0x8b, 0x8b, 0x8a, 0x8a, 0x89, 0x89, 0x88, 0x87, 0x87,
  0x86, 0x86, 0x85, 0x84, 0x84, 0x83, 0x82, 0x82, 0x81, 0x80, 0x80, 0x7f,
  0x7e, 0x7e, 0x7d, 0x7c, 0x7c, 0x7b, 0x7a, 0x79, 0x79, 0x78, 0x77, 0x77,
  0x76, 0x75, 0x75, 0x74, 0x73, 0x73, 0x72, 0x72, 0x71, 0x71, 0x71, 0x71,
  0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70,
  0x70, 0x70, 0x70, 0x71, 0x71, 0x71, 0x71, 0x72, 0x72, 0x72, 0x73, 0x73,
  0x73, 0x74, 0x74, 0x74, 0x75, 0x75, 0x76, 0x76, 0x77, 0x78, 0x78, 0x79,
  0x7a, 0x7b, 0x7b, 0x7c, 0x7d, 0x7e, 0x7e, 0x7f, 0x80, 0x80, 0x81, 0x82,
  0x82, 0x83, 0x84, 0x84, 0x85, 0x85, 0x86, 0x86, 0x87, 0x87, 0x88, 0x88,
  0x89, 0x89, 0x89, 0x8a, 0x8a, 0x8a, 0x8b, 0x8b, 0x8b, 0x8b, 0x8c, 0x8c,
  0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c,
  0x8c, 0x8c, 0x8c, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8a, 0x8a, 0x8a,
  0x8a, 0x8a, 0x89, 0x89, 0x89, 0x89, 0x88, 0x88, 0x88, 0x88, 0x87, 0x87,
  0x86, 0x86, 0x85, 0x85, 0x84, 0x84, 0x83, 0x83, 0x82, 0x82, 0x81, 0x81,
  0x80, 0x80, 0x7f, 0x7f, 0x7e, 0x7e, 0x7d, 0x7d, 0x7c, 0x7c, 0x7b, 0x7b,
  0x7a, 0x79, 0x79, 0x78, 0x78, 0x77, 0x77, 0x76, 0x76, 0x76, 0x75, 0x75,
  0x75, 0x74, 0x74, 0x74, 0x74, 0x74, 0x74, 0x74, 0x74, 0x74, 0x73, 0x73,
  0x73, 0x73, 0x73, 0x73, 0x73, 0x74, 0x74, 0x74, 0x74, 0x74, 0x75, 0x75,
  0x75, 0x75, 0x76, 0x76, 0x76, 0x76, 0x77, 0x77, 0x77, 0x78, 0x78, 0x79,
  0x79, 0x7a, 0x7a, 0x7b, 0x7b, 0x7c, 0x7d, 0x7d, 0x7e, 0x7e, 0x7f, 0x7f,
  0x80, 0x80, 0x81, 0x81, 0x82, 0x82, 0x83, 0x83, 0x84, 0x84, 0x84, 0x85,
  0x85, 0x85, 0x86, 0x86, 0x86, 0x87, 0x87, 0x87, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89,
  0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x86, 0x86, 0x86,
  0x86, 0x85, 0x85, 0x85, 0x85, 0x84, 0x84, 0x83, 0x83, 0x83, 0x82, 0x82,
  0x82, 0x81, 0x81, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7e, 0x7e, 0x7e, 0x7d,
  0x7d, 0x7c, 0x7c, 0x7c, 0x7b, 0x7b, 0x7a, 0x7a, 0x7a, 0x79, 0x79, 0x78,
  0x78, 0x78, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x76, 0x76, 0x76,
  0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x77, 0x77,
  0x77, 0x77, 0x77, 0x77, 0x78, 0x78, 0x78, 0x78, 0x78, 0x79, 0x79, 0x79,
  0x79, 0x7a, 0x7a, 0x7a, 0x7b, 0x7b, 0x7c, 0x7c, 0x7c, 0x7d, 0x7d, 0x7e,
  0x7e, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82,
  0x83, 0x83, 0x83, 0x84, 0x84, 0x84, 0x84, 0x85, 0x85, 0x85, 0x85, 0x86,
  0x86, 0x86, 0x86, 0x86, 0x86, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87,
  0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x86,
  0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x85, 0x85, 0x85, 0x85,
  0x85, 0x85, 0x85, 0x84, 0x84, 0x84, 0x84, 0x84, 0x83, 0x83, 0x83, 0x82,
  0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f,
  0x7f, 0x7e, 0x7e, 0x7e, 0x7d, 0x7d, 0x7d, 0x7c, 0x7c, 0x7c, 0x7b, 0x7b,
  0x7b, 0x7b, 0x7a, 0x7a, 0x7a, 0x7a, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79,
  0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79,
  0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x79, 0x7a, 0x7a, 0x7a, 0x7a,
  0x7a, 0x7a, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x7c, 0x7c, 0x7c, 0x7d, 0x7d,
  0x7d, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x81,
  0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0x82, 0x83, 0x83, 0x83, 0x83, 0x83,
  0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85,
  0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85,
  0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x84, 0x84, 0x84, 0x84, 0x84,
  0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83,
  0x82, 0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80,
  0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7e, 0x7e, 0x7d, 0x7d,
  0x7d, 0x7d, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b,
  0x7b, 0x7b, 0x7b, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a,
  0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b,
  0x7b, 0x7b, 0x7b, 0x7b, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7d, 0x7d,
  0x7d, 0x7d, 0x7d, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x80,
  0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0x82,
  0x82, 0x82, 0x82, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x84,
  0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84,
  0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x83, 0x83, 0x83, 0x83,
  0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x82, 0x82,
  0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e,
  0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7c,
  0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c,
  0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c,
  0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d,
  0x7d, 0x7d, 0x7d, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82,
  0x82, 0x82, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83,
  0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83,
  0x83, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82,
  0x82, 0x82, 0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
  0x7e, 0x7e, 0x7e, 0x7e, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d,
  0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d,
  0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
  0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x82,
  0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
  0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80
};
unsigned int sample_wav_len = 2716;
unsigned int p = 0;

void setup()
{
  // Enable 64 MHz PLL and use as source for Timer1
  PLLCSR = 1 << PCKE | 1 << PLLE;

  // Set up Timer/Counter1 for PWM output
  TIMSK = 0;                              // Timer interrupts OFF
  TCCR1 = 1 << PWM1A | 2 << COM1A0 | 1 << CS10; // PWM A, clear on match, 1:1 prescale
  GTCCR = 1 << PWM1B | 2 << COM1B0;       // PWM B, clear on match
  OCR1A = 128; OCR1B = 128;               // 50% duty at start

  // Set up Timer/Counter0 for 8kHz interrupt to output samples.
  TCCR0A = 3 << WGM00;                    // Fast PWM
  TCCR0B = 1 << WGM02 | 2 << CS00;        // 1/8 prescale
  TIMSK = 1 << OCIE0A;                    // Enable compare match
  OCR0A = 124;                            // Divide by 1000

  //set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  pinMode(4, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, INPUT);

  noInterrupts();
}

void loop()
{
  if (digitalRead(0) == HIGH && clicked0 == false)
  {
    clicked0 = true;
    p = 0;
    interrupts();
  }
  else if (p != 0 && digitalRead(0) == LOW && clicked0 == true)
  {
    clicked0 = false;
    interrupts();
  }
  else if (p == 0 && digitalRead(0) == LOW)
  {
    noInterrupts();
  }
}

// Sample interrupt
ISR(TIMER0_COMPA_vect)
{
  char c = pgm_read_byte(&sample[p++]);
  OCR1A = c;
  OCR1B = c ^ 255;

  if (p == sample_wav_len)
  {
    p = 0;
  }
}



