#include <avr/pgmspace.h>
#include <avr/sleep.h>
#define adc_disable()  (ADCSRA &= ~(1<<ADEN))

boolean clicked0 = false;

// Audio encoded as unsigned 8-bit, 8kHz sampling rate
const char sample[] PROGMEM = {
  0x7f, 0x7e, 0x7f, 0x7f, 0x80, 0x81, 0x80, 0x7f, 0x7e, 0x80, 0x80, 0x83,
  0x84, 0x82, 0x82, 0x81, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x82, 0x81, 0x7f,
  0x7f, 0x80, 0x7f, 0x7f, 0x7f, 0x81, 0x82, 0x81, 0x80, 0x7f, 0x7f, 0x7f,
  0x81, 0x82, 0x84, 0x80, 0x7e, 0x7b, 0x7e, 0x87, 0x84, 0x85, 0x87, 0x82,
  0x7a, 0x81, 0x82, 0x76, 0x8d, 0x67, 0x78, 0x98, 0x9b, 0xb9, 0x85, 0x42,
  0x38, 0x83, 0xcd, 0xd5, 0xab, 0x5d, 0x18, 0x30, 0xa3, 0xe4, 0xa7, 0x61,
  0x4a, 0x31, 0x76, 0xe6, 0xc7, 0x80, 0x83, 0x69, 0x43, 0x30, 0x9b, 0xe9,
  0xc6, 0x65, 0x3a, 0x50, 0x76, 0xd7, 0xce, 0x5d, 0x32, 0x72, 0x79, 0xbc,
  0xc7, 0x5e, 0x27, 0x67, 0x8b, 0x9f, 0xdf, 0x87, 0x2e, 0x4b, 0x8b, 0x8f,
  0xd5, 0xa4, 0x3a, 0x33, 0x7b, 0x98, 0xd3, 0xb1, 0x49, 0x33, 0x70, 0x97,
  0xcd, 0xb7, 0x4c, 0x52, 0x77, 0x81, 0xc4, 0xab, 0x3b, 0x6d, 0x88, 0x71,
  0xba, 0xa1, 0x2a, 0x7a, 0xb8, 0x70, 0xa9, 0x86, 0x18, 0x76, 0xb1, 0x6d,
  0xa8, 0x87, 0x1a, 0x6e, 0xb3, 0x6f, 0xa6, 0x91, 0x1b, 0x68, 0xba, 0x75,
  0xa4, 0x9b, 0x23, 0x69, 0xc1, 0x76, 0xa2, 0xa3, 0x24, 0x68, 0xc2, 0x6d,
  0x9e, 0xb0, 0x25, 0x61, 0xcc, 0x67, 0x80, 0xc6, 0x41, 0x4e, 0xce, 0x78,
  0x68, 0xc8, 0x5d, 0x48, 0xc4, 0x82, 0x50, 0xbf, 0x83, 0x42, 0xb5, 0x93,
  0x3c, 0xac, 0xae, 0x43, 0x9c, 0xa4, 0x42, 0x9d, 0xaf, 0x4e, 0x95, 0x7c,
  0x3f, 0xb4, 0x7b, 0x4c, 0xc9, 0x96, 0x35, 0x9e, 0xa8, 0x2e, 0x7e, 0xac,
  0x3d, 0x8e, 0xb1, 0x40, 0x91, 0xa2, 0x31, 0x8e, 0xc7, 0x48, 0x5c, 0xbc,
  0x59, 0x50, 0xcc, 0x8f, 0x30, 0x9a, 0x8f, 0x54, 0xa3, 0x6d, 0x88, 0x9b,
  0x35, 0x73, 0xb4, 0x71, 0x96, 0x97, 0x2f, 0x89, 0xae, 0x4d, 0x9c, 0xa7,
  0x3e, 0x90, 0xb9, 0x42, 0x60, 0xaf, 0x40, 0x58, 0xcb, 0x87, 0x8c, 0xc7,
  0x55, 0x26, 0xa1, 0xa0, 0x53, 0xba, 0x9b, 0x40, 0xaa, 0xaa, 0x31, 0x81,
  0xa2, 0x3d, 0x92, 0xc5, 0x63, 0x89, 0xa3, 0x34, 0x7b, 0x9e, 0x62, 0xb6,
  0xae, 0x6b, 0xa9, 0x9e, 0x48, 0x62, 0x50, 0x41, 0xaa, 0xcc, 0xb5, 0xaf,
  0x4f, 0x0d, 0x65, 0x88, 0x63, 0x91, 0x6d, 0x68, 0xc8, 0xd4, 0x98, 0xb5,
  0x88, 0x2a, 0x74, 0xba, 0x71, 0x9b, 0x91, 0x50, 0x9a, 0x92, 0x3f, 0x7c,
  0x64, 0x30, 0xa3, 0xd2, 0x7a, 0xa1, 0xa3, 0x48, 0x96, 0xa8, 0x42, 0x71,
  0x71, 0x41, 0xac, 0xcc, 0x5f, 0x70, 0x92, 0x53, 0x92, 0xc8, 0x66, 0x35,
  0x5d, 0x74, 0xb4, 0xdd, 0x80, 0x41, 0x59, 0x80, 0xc1, 0xd3, 0x6f, 0x37,
  0x74, 0x75, 0xa5, 0xd5, 0x71, 0x2c, 0x6a, 0x79, 0x95, 0xd2, 0x7e, 0x30,
  0x86, 0x76, 0x6b, 0xc8, 0x91, 0x2b, 0x80, 0x8e, 0x70, 0xc1, 0xa6, 0x2d,
  0x58, 0x91, 0x72, 0xb4, 0xb1, 0x3a, 0x4b, 0x8a, 0x76, 0xb2, 0xc2, 0x4e,
  0x40, 0xa0, 0x7d, 0x72, 0xc0, 0x71, 0x38, 0xa1, 0xab, 0x6a, 0xa4, 0x84,
  0x34, 0x8b, 0xa5, 0x65, 0x98, 0x9c, 0x45, 0x7c, 0xaa, 0x6f, 0x91, 0x99,
  0x51, 0x77, 0x9a, 0x73, 0xa8, 0x9c, 0x44, 0x7c, 0xad, 0x51, 0x88, 0xcb,
  0x58, 0x56, 0xb7, 0x68, 0x6d, 0xc8, 0x78, 0x4e, 0x9e, 0x69, 0x7e, 0xc6,
  0x58, 0x4e, 0xaf, 0x65, 0x61, 0xcb, 0x7f, 0x53, 0xac, 0x68, 0x5b, 0xb8,
  0x6e, 0x68, 0xb5, 0x5a, 0x64, 0xcb, 0x73, 0x60, 0xb4, 0x57, 0x55, 0xc8,
  0x85, 0x59, 0xaf, 0x62, 0x5a, 0xc2, 0x76, 0x50, 0xae, 0x66, 0x59, 0xce,
  0x94, 0x4a, 0x97, 0x70, 0x43, 0xa6, 0xb8, 0x69, 0x7d, 0x72, 0x61, 0x95,
  0xa3, 0x7f, 0x7a, 0x80, 0x6f, 0x6b, 0x7b, 0x98, 0x9b, 0x87, 0x79, 0x68,
  0x6e, 0x90, 0x97, 0x85, 0x78, 0x6e, 0x71, 0x8b, 0x91, 0x89, 0x75, 0x6b,
  0x79, 0x8c, 0x88, 0x92, 0x84, 0x64, 0x79, 0x8f, 0x80, 0x90, 0x8e, 0x62,
  0x75, 0x8c, 0x79, 0x92, 0x95, 0x63, 0x72, 0x96, 0x6b, 0x80, 0xa6, 0x72,
  0x69, 0x9b, 0x79, 0x79, 0xa5, 0x7b, 0x6c, 0x90, 0x72, 0x76, 0xa3, 0x7a,
  0x6a, 0x90, 0x73, 0x6f, 0xa2, 0x86, 0x6d, 0x8f, 0x7c, 0x79, 0x9b, 0x81,
  0x6e, 0x86, 0x79, 0x7f, 0x99, 0x81, 0x71, 0x84, 0x78, 0x7b, 0x94, 0x8a,
  0x74, 0x80, 0x83, 0x7b, 0x94, 0x8d, 0x75, 0x7f, 0x7a, 0x75, 0x8a, 0x89,
  0x77, 0x7b, 0x88, 0x94, 0x98, 0x8c, 0x75, 0x5a, 0x4b, 0x52, 0x7f, 0xaf,
  0xc5, 0xb9, 0x92, 0x63, 0x57, 0x75, 0x84, 0x7c, 0x70, 0x6a, 0x71, 0x84,
  0x92, 0x97, 0x97, 0x92, 0x8b, 0x85, 0x7f, 0x79, 0x73, 0x74, 0x74, 0x73,
  0x76, 0x7b, 0x8a, 0x90, 0x82, 0x74, 0x71, 0x6c, 0x8d, 0xc6, 0xb1, 0x63,
  0x52, 0x6b, 0x55, 0x9d, 0xda, 0x81, 0x39, 0x75, 0x78, 0x64, 0xcf, 0xc0,
  0x42, 0x50, 0xa2, 0x5f, 0x8b, 0xd3, 0x71, 0x31, 0x82, 0x8d, 0x80, 0xce,
  0x95, 0x37, 0x5e, 0x98, 0x75, 0xb8, 0xb6, 0x4b, 0x36, 0x81, 0x7a, 0x9b,
  0xce, 0x7b, 0x37, 0x5b, 0x86, 0x85, 0xcd, 0xa7, 0x4b, 0x45, 0x81, 0x79,
  0xb3, 0xc2, 0x66, 0x36, 0x6a, 0x89, 0x96, 0xd1, 0x86, 0x38, 0x55, 0x8f,
  0x83, 0xc7, 0xb6, 0x48, 0x32, 0x8b, 0x85, 0x99, 0xd9, 0x6c, 0x20, 0x86,
  0x9b, 0x67, 0xc9, 0xb0, 0x2e, 0x40, 0xb3, 0x78, 0x7c, 0xd8, 0x7f, 0x1c,
  0x84, 0xad, 0x52, 0xa5, 0xbc, 0x34, 0x48, 0xbf, 0x72, 0x59, 0xc8, 0x83,
  0x27, 0x93, 0xb6, 0x40, 0x73, 0xc8, 0x59, 0x50, 0xc6, 0x9b, 0x34, 0x8e,
  0xbe, 0x52, 0x7c, 0xcf, 0x6f, 0x35, 0xad, 0x9e, 0x59, 0xa4, 0xa3, 0x49,
  0x4f, 0xa5, 0x93, 0xc5, 0x94, 0x63, 0x7f, 0x48, 0x6f, 0xa6, 0xc1, 0x58,
  0x41, 0xb9, 0x7c, 0x76, 0xb9, 0x88, 0x69, 0x38, 0x94, 0xa7, 0x6a, 0x93,
  0x4a, 0x85, 0x88, 0x52, 0xc1, 0x90, 0x3a, 0x60, 0x7e, 0xbd, 0x93, 0xaa,
  0xb9, 0x3a, 0x36, 0x80, 0x80, 0xc8, 0x8f, 0x41, 0x7d, 0x54, 0x9b, 0xbc,
  0x88, 0xa8, 0x40, 0x4b, 0x95, 0x88, 0xc6, 0xb9, 0x6a, 0x20, 0x2b, 0x91,
  0xab, 0xc3, 0xd1, 0x83, 0x1a, 0x19, 0x62, 0x71, 0x80, 0xc7, 0x98, 0x5e,
  0xbc, 0x9d, 0x36, 0x6e, 0x86, 0x57, 0x9d, 0xc9, 0xc1, 0x7d, 0x63, 0x3e,
  0x16, 0x79, 0xae, 0x7d, 0xba, 0xb7, 0x4b, 0x89, 0x7f, 0x51, 0x67, 0x45,
  0x86, 0xb5, 0xc9, 0xb5, 0x69, 0x5f, 0x42, 0x3c, 0x72, 0xaf, 0x84, 0x75,
  0xaf, 0x9b, 0xa9, 0xba, 0x89, 0x33, 0x2b, 0x36, 0x56, 0xc6, 0xef, 0xc1,
  0x8e, 0x80, 0x3f, 0x64, 0xc9, 0x8d, 0x4e, 0x72, 0x47, 0x51, 0xc7, 0xd8,
  0xa5, 0x71, 0x50, 0x3e, 0x75, 0xcd, 0x9b, 0x5d, 0x5c, 0x4b, 0x7a, 0xd8,
  0xd1, 0xa2, 0x66, 0x3f, 0x61, 0x9d, 0xd4, 0xa1, 0x56, 0x50, 0x4b, 0x7c,
  0xd1, 0xd4, 0x77, 0x46, 0x61, 0x6e, 0xaa, 0xd6, 0x9a, 0x51, 0x41, 0x48,
  0x95, 0xce, 0x9c, 0x6e, 0x68, 0x5a, 0x73, 0xbe, 0xa8, 0x53, 0x5e, 0x7f,
  0x66, 0x9b, 0xc8, 0x72, 0x53, 0x8d, 0x7f, 0x83, 0xb2, 0x95, 0x44, 0x5b,
  0x97, 0x7d, 0x96, 0xb2, 0x61, 0x3a, 0x82, 0x92, 0x84, 0xa5, 0x8a, 0x44,
  0x5e, 0xa7, 0x8d, 0x95, 0x98, 0x5f, 0x42, 0x83, 0xaa, 0x82, 0x8b, 0x83,
  0x4e, 0x63, 0xa8, 0xa5, 0x88, 0x79, 0x64, 0x5f, 0x8c, 0xa4, 0x8c, 0x8e,
  0x72, 0x50, 0x93, 0x9f, 0x7f, 0x84, 0x7d, 0x51, 0x74, 0x99, 0x92, 0x81,
  0x6a, 0x7c, 0x75, 0x8e, 0x9e, 0x84, 0x77, 0x60, 0x70, 0x8d, 0x9d, 0x98,
  0x69, 0x63, 0x70, 0x66, 0x96, 0xb1, 0x83, 0x63, 0x65, 0x76, 0x7a, 0xa1,
  0xad, 0x64, 0x66, 0x77, 0x73, 0x9b, 0xaa, 0x89, 0x62, 0x55, 0x65, 0x87,
  0x95, 0x9d, 0x88, 0x6a, 0x5d, 0x76, 0x8d, 0x8a, 0x97, 0x7b, 0x67, 0x7b,
  0x7b, 0x85, 0x9a, 0x87, 0x6c, 0x74, 0x7f, 0x74, 0x87, 0x9a, 0x75, 0x6a,
  0x82, 0x72, 0x7e, 0xa0, 0x94, 0x74, 0x6d, 0x7a, 0x79, 0x87, 0x99, 0x8d,
  0x66, 0x6a, 0x8c, 0x7c, 0x87, 0x9a, 0x70, 0x60, 0x83, 0x8e, 0x88, 0x9a,
  0x99, 0x5e, 0x66, 0x98, 0x71, 0x89, 0xa6, 0x6b, 0x71, 0x83, 0x85, 0x86,
  0x93, 0x83, 0x60, 0x81, 0x8e, 0x75, 0x9e, 0x97, 0x61, 0x81, 0x88, 0x7d,
  0x8c, 0x9b, 0x7b, 0x5e, 0x85, 0x85, 0x7b, 0x93, 0x8e, 0x72, 0x6c, 0x94,
  0x8a, 0x7b, 0x98, 0x76, 0x60, 0x88, 0xa3, 0x85, 0x8a, 0x90, 0x69, 0x53,
  0x8c, 0x9a, 0x77, 0x95, 0x8f, 0x65, 0x73, 0x9b, 0x7b, 0x7f, 0x91, 0x77,
  0x73, 0x96, 0x8e, 0x68, 0x89, 0x8c, 0x6c, 0x87, 0x98, 0x70, 0x6d, 0x88,
  0x80, 0x81, 0x97, 0x7c, 0x6f, 0x88, 0x7b, 0x85, 0xa0, 0x7f, 0x70, 0x80,
  0x74, 0x80, 0x90, 0x86, 0x76, 0x7c, 0x74, 0x78, 0x91, 0x8a, 0x7a, 0x87,
  0x84, 0x6f, 0x8f, 0x81, 0x75, 0x89, 0x7e, 0x78, 0x89, 0x90, 0x77, 0x70,
  0x85, 0x75, 0x6c, 0x93, 0x8a, 0x73, 0x81, 0x8a, 0x76, 0x85, 0x9b, 0x77,
  0x6f, 0x8a, 0x75, 0x71, 0xa0, 0x8e, 0x6a, 0x81, 0x7d, 0x67, 0x82, 0x99,
  0x80, 0x6b, 0x8a, 0x7c, 0x76, 0x9e, 0x8e, 0x77, 0x6b, 0x71, 0x7d, 0x86,
  0x97, 0x8f, 0x70, 0x6f, 0x74, 0x84, 0x8d, 0x86, 0x7e, 0x6a, 0x70, 0x8d,
  0x92, 0x95, 0x88, 0x65, 0x65, 0x7b, 0x8c, 0x9a, 0x94, 0x74, 0x5d, 0x6c,
  0x85, 0x92, 0x98, 0x83, 0x62, 0x69, 0x83, 0x8e, 0x99, 0x97, 0x6c, 0x59,
  0x76, 0x89, 0x94, 0x9c, 0x86, 0x61, 0x69, 0x83, 0x84, 0x8b, 0x84, 0x6f,
  0x69, 0x82, 0x93, 0x8f, 0x89, 0x7e, 0x75, 0x77, 0x87, 0x96, 0x87, 0x70,
  0x78, 0x7c, 0x75, 0x87, 0x95, 0x76, 0x67, 0x85, 0x84, 0x81, 0x99, 0x87,
  0x6d, 0x72, 0x80, 0x88, 0x91, 0x91, 0x7d, 0x6c, 0x7b, 0x7a, 0x7f, 0x9a,
  0x82, 0x6d, 0x6c, 0x7d, 0xa4, 0x82, 0x89, 0x73, 0x62, 0x75, 0x66, 0x9f,
  0xd2, 0xc5, 0x80, 0x33, 0x1a, 0x51, 0xb9, 0xea, 0xb0, 0x5d, 0x42, 0x25,
  0x5f, 0xd6, 0xea, 0x9e, 0x5d, 0x5d, 0x3f, 0x73, 0xdd, 0xc7, 0x5c, 0x43,
  0x8a, 0x51, 0x67, 0xd8, 0x9d, 0x50, 0x59, 0x8a, 0x5f, 0x9e, 0xd8, 0x63,
  0x6b, 0xa8, 0x74, 0x4a, 0xb3, 0x9d, 0x3a, 0x94, 0xc5, 0x60, 0x7c, 0xba,
  0x4b, 0x42, 0xbc, 0x9d, 0x51, 0xaa, 0x8a, 0x25, 0x72, 0xcc, 0x7f, 0x61,
  0xbe, 0x70, 0x27, 0x91, 0xc2, 0x5c, 0x73, 0xc0, 0x51, 0x38, 0xb8, 0xb3,
  0x3f, 0x84, 0xbe, 0x47, 0x58, 0xd2, 0x8f, 0x38, 0xad, 0x9a, 0x31, 0x9a,
  0xca, 0x57, 0x66, 0xcc, 0x68, 0x44, 0xa0, 0x96, 0x57, 0x93, 0xc6, 0x48,
  0x4d, 0x95, 0x95, 0x56, 0x90, 0xd5, 0x68, 0x5a, 0x8f, 0xac, 0x60, 0x72,
  0xd5, 0x6f, 0x44, 0x76, 0xb8, 0xa4, 0x6c, 0xa6, 0x51, 0x2a, 0x74, 0xb8,
  0xdd, 0x6d, 0x38, 0x7a, 0xaf, 0x88, 0x40, 0x9c, 0xb5, 0x3f, 0x42, 0xae,
  0xb3, 0x99, 0xa5, 0x7e, 0x43, 0x11, 0x33, 0xa2, 0xda, 0xe1, 0x6f, 0x39,
  0x9e, 0x5b, 0x40, 0xbc, 0xe1, 0x8f, 0x21, 0x54, 0xc2, 0x79, 0x90, 0xcc,
  0x5b, 0x15, 0x59, 0xbe, 0xad, 0xbe, 0xa9, 0x23, 0x44, 0xa4, 0x4f, 0x7f,
  0xd8, 0x64, 0x54, 0xa9, 0x7f, 0x3f, 0x6e, 0xc7, 0x73, 0x61, 0xb3, 0xa9,
  0x8c, 0x65, 0x3b, 0x3e, 0x44, 0xa8, 0xe4, 0xc6, 0xdb, 0x9d, 0x41, 0x3a,
  0x31, 0x37, 0x47, 0xa9, 0xe7, 0x82, 0x96, 0xbc, 0x92, 0x93, 0x6b, 0x5c,
  0x68, 0x4f, 0x5b, 0xc4, 0xc6, 0xc2, 0xc1, 0x73, 0x46, 0x1b, 0x18, 0x77,
  0xb9, 0x80, 0x6c, 0xa6, 0xa0, 0x77, 0x9e, 0xab, 0x57, 0x23, 0x6d, 0x80,
  0x4f, 0xb3, 0xb7, 0x58, 0x96, 0xb8, 0x78, 0x7d, 0xae, 0x76, 0x1b, 0x4a,
  0x7c, 0x52, 0xa1, 0xe4, 0xa8, 0x56, 0x69, 0x9c, 0x87, 0xa5, 0x99, 0x58,
  0x2c, 0x43, 0x74, 0xbe, 0xc8, 0x99, 0x67, 0x49, 0x98, 0xaa, 0x9c, 0xb4,
  0x77, 0x1b, 0x5a, 0xa4, 0x71, 0x93, 0xc2, 0x72, 0x44, 0xa8, 0xb1, 0x70,
  0x75, 0x71, 0x4a, 0x6d, 0xc4, 0xa1, 0x5b, 0x8d, 0x9c, 0x54, 0x9b, 0xc5,
  0x67, 0x3c, 0x87, 0x95, 0x62, 0xb2, 0xb2, 0x63, 0x5c, 0x95, 0x7a, 0x6c,
  0xb6, 0x92, 0x69, 0x76, 0x8f, 0x6e, 0x7f, 0x9c, 0x7d, 0x7a, 0x7f, 0x84,
  0x5c, 0x81, 0x9d, 0x8b, 0x81, 0x8a, 0x8e, 0x56, 0x79, 0x97, 0x80, 0x5e,
  0x81, 0x88, 0x61, 0x80, 0xaf, 0x9c, 0x5b, 0x75, 0x8a, 0x6a, 0x67, 0xa7,
  0x80, 0x5f, 0x91, 0x76, 0x78, 0x9b, 0x99, 0x5a, 0x7a, 0x95, 0x5e, 0x8a,
  0xb0, 0x74, 0x50, 0x79, 0x7c, 0x6f, 0x94, 0xbe, 0x71, 0x5b, 0x92, 0x67,
  0x72, 0xaf, 0x92, 0x45, 0x7b, 0x93, 0x5f, 0x8c, 0xca, 0x95, 0x3f, 0x72,
  0x84, 0x4f, 0x8e, 0xc9, 0x7f, 0x5d, 0x84, 0x67, 0x7a, 0xb9, 0x8d, 0x68,
  0x88, 0x6b, 0x54, 0x93, 0xad, 0x70, 0x77, 0x9e, 0x6a, 0x65, 0x9c, 0x8b,
  0x5d, 0x80, 0x90, 0x67, 0x8a, 0xb2, 0x6f, 0x62, 0xa0, 0x7b, 0x63, 0x93,
  0x8e, 0x60, 0x7d, 0x9b, 0x7b, 0x7d, 0x91, 0x76, 0x63, 0x95, 0x7a, 0x73,
  0xa9, 0x84, 0x67, 0x86, 0x86, 0x75, 0x89, 0x94, 0x77, 0x70, 0x8f, 0x76,
  0x79, 0x9e, 0x80, 0x64, 0x85, 0x92, 0x6a, 0x85, 0x9f, 0x72, 0x6a, 0x98,
  0x90, 0x6e, 0x95, 0x8a, 0x58, 0x77, 0x9b, 0x73, 0x7f, 0xa0, 0x71, 0x5e,
  0x91, 0x93, 0x67, 0x93, 0x8d, 0x55, 0x85, 0xaa, 0x7b, 0x7d, 0xa3, 0x6a,
  0x4d, 0x86, 0x96, 0x7b, 0x8e, 0x98, 0x6c, 0x5f, 0x8a, 0x87, 0x7e, 0x9e,
  0x7d, 0x5f, 0x85, 0x84, 0x72, 0x8e, 0xa4, 0x6b, 0x66, 0x98, 0x79, 0x72,
  0x91, 0x93, 0x68, 0x7a, 0x8f, 0x6f, 0x7c, 0x97, 0x78, 0x79, 0xa0, 0x79,
  0x6e, 0x97, 0x8d, 0x62, 0x7d, 0x90, 0x6c, 0x72, 0x98, 0x8b, 0x70, 0x89,
  0x89, 0x7d, 0x7d, 0x84, 0x79, 0x68, 0x88, 0x82, 0x7d, 0xa5, 0x94, 0x5e,
  0x77, 0x97, 0x6b, 0x73, 0xa0, 0x80, 0x5b, 0x88, 0x8e, 0x78, 0x96, 0x8e,
  0x65, 0x75, 0x8a, 0x77, 0x86, 0xa4, 0x83, 0x61, 0x87, 0x80, 0x65, 0x90,
  0x96, 0x79, 0x7a, 0x8a, 0x76, 0x7c, 0x97, 0x80, 0x76, 0x7b, 0x75, 0x75,
  0x89, 0x9c, 0x90, 0x73, 0x75, 0x7c, 0x76, 0x87, 0x8d, 0x85, 0x7b, 0x76,
  0x84, 0x85, 0x89, 0x85, 0x75, 0x74, 0x81, 0x7e, 0x90, 0x92, 0x73, 0x76,
  0x77, 0x79, 0x85, 0x94, 0x83, 0x78, 0x84, 0x7c, 0x76, 0x92, 0x8a, 0x66,
  0x7f, 0x8d, 0x77, 0x7c, 0x97, 0x7e, 0x6c, 0x8b, 0x7d, 0x76, 0x88, 0x84,
  0x7b, 0x89, 0x89, 0x78, 0x78, 0x81, 0x81, 0x7d, 0x8e, 0x8f, 0x6e, 0x68,
  0x8c, 0x86, 0x77, 0x94, 0x8c, 0x64, 0x69, 0x96, 0x8f, 0x81, 0x92, 0x7c,
  0x59, 0x73, 0x8f, 0x86, 0x97, 0x8d, 0x6b, 0x6d, 0x80, 0x88, 0x88, 0x91,
  0x7e, 0x64, 0x75, 0x8c, 0x8e, 0x8d, 0x88, 0x7a, 0x6d, 0x71, 0x86, 0x92,
  0x8a, 0x78, 0x75, 0x71, 0x76, 0x8d, 0x8c, 0x8a, 0x88, 0x70, 0x71, 0x8e,
  0x7e, 0x81, 0x92, 0x77, 0x68, 0x81, 0x86, 0x7e, 0x8a, 0x8a, 0x79, 0x71,
  0x82, 0x84, 0x84, 0x89, 0x7d, 0x76, 0x7b, 0x86, 0x89, 0x86, 0x7f, 0x75,
  0x79, 0x7a, 0x80, 0x91, 0x87, 0x79, 0x80, 0x7b, 0x78, 0x85, 0x8b, 0x84,
  0x7b, 0x7a, 0x7b, 0x7d, 0x84, 0x8a, 0x81, 0x80, 0x7a, 0x75, 0x7d, 0x86,
  0x84, 0x79, 0x89, 0x88, 0x83, 0x7e, 0x98, 0x9a, 0x7d, 0x7f, 0x4d, 0x37,
  0x49, 0x94, 0xd8, 0xd9, 0xb9, 0x8b, 0x4a, 0x1f, 0x5e, 0xb0, 0xc6, 0x83,
  0x51, 0x5c, 0x39, 0x77, 0xd6, 0xd1, 0x81, 0x48, 0x8d, 0x6e, 0x47, 0xb1,
  0xb6, 0x61, 0x41, 0x90, 0x8a, 0x51, 0xbb, 0xb7, 0x6e, 0x6b, 0x8a, 0x82,
  0x40, 0xaa, 0xba, 0x6a, 0x70, 0x8a, 0x83, 0x3d, 0xa5, 0xb3, 0x6a, 0x82,
  0x8d, 0x6e, 0x44, 0xb9, 0x9c, 0x62, 0x98, 0x94, 0x69, 0x51, 0xb8, 0x79,
  0x61, 0x9c, 0x9d, 0x6e, 0x51, 0xc2, 0xa6, 0x70, 0x7d, 0x94, 0x60, 0x41,
  0xba, 0xa3, 0x72, 0x7d, 0x9b, 0x7d, 0x43, 0xab, 0x99, 0x5b, 0x66, 0x90,
  0x7e, 0x3b, 0xa4, 0xa7, 0x64, 0x69, 0x96, 0x92, 0x34, 0x86, 0xb5, 0x76,
  0x6d, 0x93, 0x95, 0x2f, 0x5b, 0xac, 0xca, 0xa4, 0x5e, 0x8e, 0x47, 0x2a,
  0x8e, 0xcb, 0xc7, 0x59, 0x79, 0x87, 0x2b, 0x6b, 0xc9, 0xe1, 0xa6, 0x39,
  0x6c, 0xa0, 0x3d, 0x74, 0xd4, 0xbb, 0x54, 0x28, 0x99, 0xa1, 0x53, 0xb7,
  0xc1, 0x66, 0x3b, 0x42, 0xaa, 0xcf, 0x8a, 0x88, 0x79, 0x52, 0x3d, 0x56,
  0xc4, 0xda, 0x7c, 0x73, 0x6a, 0x84, 0xa7, 0x80, 0x9f, 0xba, 0x7c, 0x17,
  0x41, 0x4a, 0x6b, 0xce, 0x80, 0x90, 0xd4, 0x6d, 0x7a, 0x95, 0x2e, 0x67,
  0x87, 0x55, 0xa2, 0xbf, 0xbc, 0x66, 0x2b, 0x7f, 0x4a, 0x4c, 0x9f, 0xae,
  0xd7, 0x83, 0x50, 0xa6, 0x98, 0x55, 0x3c, 0x40, 0x82, 0x8d, 0x7a, 0xcf,
  0xc6, 0x58, 0x6f, 0xa6, 0x50, 0x47, 0x8b, 0x74, 0x98, 0xb3, 0x82, 0x9e,
  0xb7, 0x6c, 0x43, 0x72, 0x6d, 0x55, 0x9d, 0xc6, 0x7b, 0x6b, 0x8e, 0x9e,
  0x8a, 0x7d, 0xa4, 0x5e, 0x39, 0x53, 0x50, 0x77, 0xb9, 0xde, 0x97, 0x89,
  0x99, 0x3f, 0x39, 0x9c, 0x8b, 0x3e, 0x73, 0xb7, 0x93, 0x61, 0xae, 0xc5,
  0x67, 0x84, 0xa6, 0x6d, 0x44, 0x8d, 0x87, 0x48, 0x74, 0x77, 0x79, 0x96,
  0xcf, 0xb8, 0x84, 0x9b, 0x61, 0x3c, 0x5a, 0x8c, 0x78, 0x5a, 0x9e, 0x98,
  0x5f, 0x8d, 0xc4, 0x8b, 0x73, 0x95, 0x76, 0x52, 0x7a, 0x8b, 0x7e, 0xa5,
  0x94, 0x6b, 0x81, 0x7e, 0x74, 0x84, 0x96, 0x80, 0x6b, 0x88, 0x85, 0x7c,
  0x78, 0x76, 0x84, 0x70, 0x81, 0x8f, 0x8d, 0x7d, 0x77, 0x8a, 0x67, 0x78,
  0x89, 0x90, 0x80, 0x5c, 0x7e, 0x72, 0x71, 0x8d, 0xab, 0xa4, 0x73, 0x71,
  0x80, 0x77, 0x69, 0x94, 0xb2, 0x6b, 0x46, 0x80, 0x96, 0x74, 0x93, 0xbb,
  0x6f, 0x3e, 0x77, 0x80, 0x87, 0x9f, 0xb0, 0x89, 0x3f, 0x5f, 0x8d, 0x87,
  0x95, 0xa5, 0x8c, 0x57, 0x57, 0x7b, 0x82, 0x97, 0x8b, 0x70, 0x6a, 0x5b,
  0x91, 0xb0, 0x8b, 0x99, 0x99, 0x53, 0x37, 0x7f, 0x9f, 0x79, 0x97, 0xae,
  0x71, 0x47, 0x7e, 0x9f, 0x79, 0x7c, 0x8f, 0x7e, 0x65, 0x75, 0x91, 0x93,
  0x88, 0x86, 0x89, 0x70, 0x78, 0x86, 0x6f, 0x87, 0x83, 0x6a, 0x85, 0x97,
  0x90, 0x72, 0x7b, 0x88, 0x72, 0x7b, 0x87, 0x8c, 0x85, 0x7e, 0x80, 0x7c,
  0x7e, 0x85, 0x7d, 0x7b, 0x8a, 0x75, 0x72, 0x93, 0x91, 0x79, 0x6d, 0x7d,
  0x86, 0x72, 0x85, 0xa8, 0x7d, 0x77, 0x8a, 0x70, 0x7d, 0x77, 0x8d, 0x8f,
  0x74, 0x8b, 0x67, 0x72, 0xa1, 0x8e, 0x75, 0x8b, 0x91, 0x5f, 0x71, 0x98,
  0x98, 0x77, 0x7d, 0x90, 0x5d, 0x70, 0xa2, 0x8e, 0x7c, 0x7f, 0x71, 0x62,
  0x7b, 0xa2, 0xa7, 0x83, 0x7a, 0x7c, 0x5d, 0x69, 0x8d, 0xa4, 0x97, 0x78,
  0x82, 0x76, 0x70, 0x7b, 0x8e, 0x9c, 0x7d, 0x74, 0x76, 0x7c, 0x80, 0x8c,
  0x8c, 0x87, 0x8c, 0x6b, 0x7a, 0x91, 0x84, 0x78, 0x83, 0x8c, 0x66, 0x73,
  0x8c, 0x87, 0x7d, 0x7b, 0x91, 0x82, 0x7e, 0x8c, 0x87, 0x7b, 0x6f, 0x77,
  0x87, 0x91, 0x7b, 0x85, 0x91, 0x72, 0x6e, 0x7c, 0x96, 0x81, 0x6e, 0x8b,
  0x7b, 0x72, 0x80, 0x94, 0x94, 0x83, 0x87, 0x6b, 0x6e, 0x7e, 0x74, 0x7f,
  0x99, 0x94, 0x6a, 0x72, 0x8c, 0x7b, 0x70, 0x8a, 0x9f, 0x78, 0x63, 0x86,
  0x89, 0x79, 0x8f, 0x9e, 0x77, 0x65, 0x7e, 0x73, 0x7b, 0x9b, 0x97, 0x79,
  0x69, 0x7a, 0x6c, 0x69, 0x9e, 0x99, 0x76, 0x7a, 0x82, 0x7a, 0x75, 0x99,
  0x97, 0x6e, 0x75, 0x6f, 0x6e, 0x88, 0x9a, 0x9f, 0x77, 0x6d, 0x79, 0x60,
  0x77, 0xa9, 0x9a, 0x78, 0x80, 0x6f, 0x59, 0x78, 0xab, 0x9a, 0x6f, 0x82,
  0x79, 0x5a, 0x7b, 0xa9, 0x96, 0x76, 0x77, 0x6d, 0x61, 0x82, 0xa9, 0x93,
  0x88, 0x82, 0x63, 0x60, 0x7d, 0xa3, 0x97, 0x82, 0x7d, 0x69, 0x60, 0x73,
  0xa3, 0x9a, 0x81, 0x7c, 0x6d, 0x6c, 0x7b, 0x9c, 0x9c, 0x8a, 0x70, 0x6a,
  0x7d, 0x79, 0x93, 0x9e, 0x7f, 0x6c, 0x66, 0x72, 0x87, 0x90, 0x94, 0x8f,
  0x70, 0x6b, 0x7e, 0x83, 0x88, 0x89, 0x8a, 0x79, 0x6d, 0x87, 0x89, 0x85,
  0x8c, 0x7a, 0x71, 0x81, 0x79, 0x7d, 0x90, 0x86, 0x7a, 0x75, 0x89, 0x84,
  0x7b, 0x8e, 0x8e, 0x81, 0x73, 0x85, 0x7d, 0x72, 0x81, 0x82, 0x88, 0x78,
  0x86, 0x91, 0x77, 0x76, 0x8c, 0x82, 0x75, 0x8c, 0x81, 0x79, 0x81, 0x83,
  0x89, 0x82, 0x84, 0x89, 0x76, 0x6a, 0x7e, 0x87, 0x85, 0x83, 0x8b, 0x8a,
  0x6b, 0x7a, 0x92, 0x84, 0x78, 0x86, 0x86, 0x6a, 0x7c, 0x95, 0x8c, 0x76,
  0x78, 0x83, 0x71, 0x7c, 0x97, 0x8a, 0x75, 0x7e, 0x76, 0x6f, 0x8f, 0x95,
  0x82, 0x7e, 0x85, 0x72, 0x74, 0x8c, 0xa0, 0x94, 0x90, 0x78, 0x42, 0x2b,
  0x37, 0x90, 0xf1, 0xf8, 0xb8, 0x8b, 0x70, 0x16, 0x23, 0x95, 0xd5, 0x8c,
  0x3b, 0x90, 0x85, 0x47, 0xaf, 0xde, 0x81, 0x29, 0x7d, 0xb4, 0x4e, 0x75,
  0xca, 0x81, 0x26, 0x61, 0xc2, 0x75, 0x6f, 0xcf, 0x99, 0x30, 0x52, 0xc1,
  0x84, 0x56, 0xc0, 0xb3, 0x40, 0x39, 0xb5, 0x9c, 0x3d, 0x9d, 0xd7, 0x7c,
  0x2e, 0x8c, 0xb7, 0x3e, 0x70, 0xda, 0x9d, 0x27, 0x5b, 0xbf, 0x5b, 0x59,
  0xd3, 0xc3, 0x44, 0x30, 0xb3, 0x90, 0x40, 0xb0, 0xe0, 0x80, 0x25, 0x82,
  0xb8, 0x43, 0x78, 0xd6, 0x9f, 0x3a, 0x58, 0xb5, 0x5c, 0x4c, 0xc3, 0xbf,
  0x45, 0x3b, 0xb5, 0x7c, 0x40, 0xb7, 0xd3, 0x67, 0x22, 0x8c, 0xb5, 0x4b,
  0x88, 0xdd, 0x97, 0x25, 0x47, 0xc1, 0x7d, 0x4f, 0xc4, 0xc4, 0x54, 0x1b,
  0x81, 0xca, 0x5c, 0x72, 0xd0, 0xa3, 0x5d, 0x22, 0x7e, 0xc8, 0x57, 0x66,
  0x99, 0x55, 0xa4, 0x8d, 0x58, 0xb3, 0xd5, 0x8b, 0x3e, 0x33, 0x66, 0xb9,
  0x64, 0x70, 0xdd, 0xb3, 0x3b, 0x3f, 0x6a, 0x93, 0x92, 0x8a, 0xc8, 0xb9,
  0x5b, 0x16, 0x48, 0x84, 0x6c, 0x9d, 0xc1, 0x96, 0xcd, 0x98, 0x25, 0x59,
  0x59, 0x7b, 0xbd, 0x7a, 0xa9, 0xc5, 0x45, 0x35, 0x8b, 0x5b, 0x7d, 0xc0,
  0xb1, 0xcf, 0x80, 0x19, 0x5d, 0x4b, 0x46, 0xc3, 0xed, 0x97, 0x5b, 0xa4,
  0x60, 0x28, 0x90, 0x72, 0x66, 0x8d, 0x89, 0xc1, 0xcf, 0xae, 0xab, 0x7f,
  0x10, 0x18, 0x60, 0x51, 0xa6, 0xf1, 0xbf, 0xb6, 0x8c, 0x3a, 0x33, 0x3b,
  0x51, 0x7e, 0x77, 0x6f, 0xcc, 0xce, 0x7f, 0xad, 0xa6, 0x43, 0x45, 0x5b,
  0x49, 0x68, 0x90, 0xba, 0xda, 0xc1, 0x7f, 0x9d, 0xb4, 0x77, 0x89, 0x84,
  0x27, 0x1a, 0x2b, 0x49, 0x92, 0xd4, 0xf7, 0xdb, 0x88, 0x4a, 0x5e, 0x44,
  0x3e, 0xa1, 0x9b, 0x58, 0x63, 0x71, 0x70, 0x95, 0xe0, 0xe2, 0xb2, 0x9b,
  0x6b, 0x2c, 0x11, 0x4e, 0x93, 0x67, 0x77, 0xbd, 0x91, 0x5b, 0x9d, 0xd7,
  0x90, 0x76, 0x95, 0x56, 0x1e, 0x40, 0xa6, 0xbb, 0x79, 0x92, 0xaf, 0x5b,
  0x3a, 0xa2, 0xbf, 0x6e, 0x83, 0x9a, 0x57, 0x3b, 0x77, 0xc2, 0x98, 0x6b,
  0x96, 0x83, 0x3e, 0x53, 0xb7, 0xb7, 0x81, 0x96, 0x83, 0x47, 0x41, 0x84,
  0xbe, 0xa7, 0x9a, 0x9b, 0x5f, 0x33, 0x66, 0xb6, 0xa7, 0x91, 0x97, 0x61,
  0x38, 0x4e, 0x92, 0xc0, 0xa5, 0x8c, 0x80, 0x53, 0x4a, 0x89, 0xb2, 0x9a,
  0x8e, 0x7a, 0x44, 0x50, 0x83, 0xac, 0xb2, 0x97, 0x8f, 0x6d, 0x3c, 0x53,
  0x97, 0xb5, 0xa4, 0x8d, 0x73, 0x55, 0x4e, 0x6a, 0xa8, 0xb9, 0xa6, 0x98,
  0x69, 0x47, 0x54, 0x7b, 0x9f, 0x91, 0x8e, 0x96, 0x71, 0x65, 0x86, 0x95,
  0x90, 0x82, 0x67, 0x64, 0x77, 0x72, 0x8c, 0xa9, 0x90, 0x7d, 0x67, 0x68,
  0x8a, 0x7b, 0x7f, 0xab, 0x97, 0x67, 0x58, 0x77, 0x8d, 0x80, 0x99, 0xa6,
  0x7d, 0x5d, 0x63, 0x69, 0x73, 0x98, 0xa4, 0x9b, 0x81, 0x60, 0x75, 0x74,
  0x73, 0xa8, 0x94, 0x82, 0x91, 0x6a, 0x66, 0x67, 0x84, 0x9e, 0x81, 0x7f,
  0x7b, 0x77, 0x7f, 0x82, 0x92, 0x9c, 0x84, 0x66, 0x74, 0x7d, 0x73, 0x8f,
  0x9b, 0x93, 0x7d, 0x5b, 0x78, 0x89, 0x72, 0x96, 0xa8, 0x78, 0x67, 0x79,
  0x72, 0x75, 0x93, 0xa2, 0x91, 0x7a, 0x6f, 0x7d, 0x70, 0x6a, 0x9e, 0xa7,
  0x7d, 0x73, 0x87, 0x76, 0x58, 0x77, 0x95, 0x96, 0x8a, 0x7e, 0x98, 0x7c,
  0x66, 0x8d, 0x84, 0x78, 0x75, 0x86, 0x8a, 0x72, 0x8e, 0x8c, 0x81, 0x7f,
  0x6a, 0x88, 0x88, 0x78, 0x90, 0x8a, 0x86, 0x74, 0x71, 0x82, 0x77, 0x90,
  0x8d, 0x84, 0x94, 0x75, 0x71, 0x76, 0x7b, 0x89, 0x72, 0x81, 0x92, 0x79,
  0x79, 0x89, 0x99, 0x7f, 0x71, 0x87, 0x7a, 0x78, 0x7a, 0x8d, 0x93, 0x72,
  0x7e, 0x85, 0x7f, 0x79, 0x7a, 0x88, 0x77, 0x76, 0x7d, 0x7c, 0x89, 0x87,
  0x87, 0x8d, 0x89, 0x7d, 0x6f, 0x74, 0x72, 0x7f, 0x89, 0x7d, 0x86, 0x80,
  0x78, 0x7f, 0x7b, 0x92, 0x8e, 0x72, 0x79, 0x7a, 0x78, 0x7b, 0x91, 0x99,
  0x74, 0x6d, 0x73, 0x70, 0x81, 0x93, 0xa3, 0x8b, 0x69, 0x75, 0x6f, 0x6c,
  0x87, 0x9c, 0x92, 0x72, 0x6d, 0x79, 0x7d, 0x8a, 0x9a, 0x8d, 0x79, 0x6c,
  0x5f, 0x70, 0x87, 0x98, 0xa1, 0x83, 0x6b, 0x70, 0x6e, 0x76, 0x95, 0x9e,
  0x90, 0x7f, 0x69, 0x64, 0x73, 0x82, 0x91, 0x9a, 0x86, 0x75, 0x74, 0x78,
  0x7f, 0x88, 0x8b, 0x81, 0x7e, 0x6d, 0x6e, 0x90, 0x92, 0x8b, 0x86, 0x81,
  0x74, 0x66, 0x80, 0x8f, 0x8a, 0x86, 0x80, 0x84, 0x71, 0x6e, 0x90, 0x8f,
  0x7b, 0x80, 0x8b, 0x7c, 0x68, 0x7e, 0x94, 0x87, 0x74, 0x89, 0x9a, 0x70,
  0x6c, 0x94, 0x89, 0x76, 0x78, 0x84, 0x7f, 0x6d, 0x88, 0x9f, 0x8b, 0x79,
  0x81, 0x81, 0x63, 0x6e, 0x94, 0x91, 0x7e, 0x79, 0x8b, 0x7d, 0x6a, 0x8d,
  0x9a, 0x82, 0x79, 0x86, 0x81, 0x6d, 0x7a, 0x92, 0x89, 0x74, 0x83, 0x91,
  0x76, 0x6f, 0x87, 0x8c, 0x7b, 0x73, 0x90, 0x91, 0x6d, 0x7c, 0x92, 0x81,
  0x7b, 0x83, 0x8f, 0x7f, 0x6f, 0x83, 0x87, 0x75, 0x79, 0x8f, 0x90, 0x79,
  0x7c, 0x86, 0x7b, 0x72, 0x7b, 0x90, 0x8a, 0x76, 0x84, 0x88, 0x75, 0x7e,
  0x90, 0x88, 0x79, 0x76, 0x80, 0x7c, 0x78, 0x8e, 0x90, 0x79, 0x75, 0x80,
  0x7e, 0x80, 0x8f, 0x92, 0x7e, 0x6b, 0x77, 0x7d, 0x72, 0x82, 0x98, 0x8f,
  0x78, 0x76, 0x8c, 0x7e, 0x67, 0x8f, 0x89, 0x77, 0x82, 0x77, 0x7d, 0x85,
  0x95, 0x89, 0xa5, 0x80, 0x62, 0x65, 0x35, 0x62, 0xd0, 0xe9, 0xce, 0x6b,
  0x3f, 0x54, 0x24, 0x1f, 0x70, 0xda, 0xff, 0xb7, 0x6c, 0xb0, 0x77, 0x0e,
  0x4d, 0xa4, 0xd0, 0x9a, 0x4c, 0xa5, 0x94, 0x1f, 0x5a, 0xba, 0xc5, 0x8a,
  0x5c, 0xb0, 0x86, 0x16, 0x55, 0xb6, 0xb5, 0x71, 0x56, 0xb4, 0x84, 0x1a,
  0x60, 0xba, 0xb8, 0x71, 0x5a, 0xb7, 0x89, 0x29, 0x69, 0x92, 0x9f, 0x7a,
  0x7b, 0xcc, 0x88, 0x36, 0x7a, 0x8a, 0xa3, 0x5b, 0x59, 0xd6, 0x96, 0x55,
  0x96, 0x80, 0xa9, 0x66, 0x4d, 0xcd, 0x96, 0x4a, 0x83, 0x80, 0xb5, 0x69,
  0x4c, 0xcc, 0x9d, 0x3c, 0x6c, 0x79, 0xb7, 0x76, 0x47, 0xc2, 0xb3, 0x3e,
  0x4c, 0x78, 0xb7, 0x83, 0x56, 0xbd, 0xbb, 0x43, 0x46, 0x6b, 0x99, 0x91,
  0x56, 0x9f, 0xc8, 0x6b, 0x2f, 0x54, 0x76, 0x93, 0x73, 0x8b, 0xd6, 0x93,
  0x39, 0x5a, 0x62, 0x9a, 0xa5, 0x5b, 0xa6, 0xc7, 0x4a, 0x4f, 0x57, 0x79,
  0xda, 0x91, 0x93, 0xce, 0x84, 0x42, 0x25, 0x33, 0x9f, 0xac, 0xc3, 0xd2,
  0xb4, 0xa4, 0x3b, 0x00, 0x2b, 0x4b, 0xa6, 0xe7, 0xcc, 0xc9, 0x9e, 0x23,
  0x11, 0x49, 0x4d, 0x9a, 0xd8, 0xd4, 0xc6, 0x52, 0x19, 0x6a, 0x5b, 0x63,
  0x83, 0xa4, 0xec, 0xc0, 0x74, 0x4d, 0x52, 0xa6, 0x8a, 0x60, 0x8f, 0x56,
  0x84, 0xac, 0x76, 0x95, 0xb3, 0x92, 0x82, 0x6b, 0x2c, 0x46, 0x5e, 0x6d,
  0xaa, 0xc7, 0xcc, 0xab, 0xaa, 0x77, 0x2e, 0x4a, 0x73, 0x78, 0x64, 0x47,
  0x63, 0x87, 0x8a, 0xa8, 0xd8, 0xd7, 0xbb, 0x98, 0x63, 0x29, 0x13, 0x26,
  0x63, 0x96, 0xb3, 0xe0, 0xda, 0x9d, 0x73, 0x87, 0x8d, 0x7e, 0x73, 0x5f,
  0x49, 0x37, 0x30, 0x61, 0x94, 0xaf, 0xd1, 0xd5, 0xbe, 0x8e, 0x6b, 0x67,
  0x46, 0x40, 0x4a, 0x54, 0x89, 0x96, 0x9f, 0xbb, 0xa3, 0x9a, 0x9b, 0x8c,
  0x83, 0x72, 0x6a, 0x5f, 0x66, 0x71, 0x60, 0x88, 0xa1, 0x8b, 0x9e, 0x84,
  0x78, 0x84, 0x61, 0x81, 0x99, 0x7a, 0x84, 0x7d, 0x68, 0x6d, 0x77, 0x97,
  0xa7, 0x9e, 0x91, 0x74, 0x60, 0x63, 0x6b, 0x7f, 0x8f, 0x97, 0x93, 0x76,
  0x6b, 0x7e, 0x81, 0x81, 0x91, 0x9b, 0x86, 0x71, 0x69, 0x76, 0x7e, 0x70,
  0x88, 0x9e, 0x80, 0x78, 0x7e, 0x8d, 0x8d, 0x6d, 0x7a, 0x8d, 0x77, 0x6c,
  0x73, 0x90, 0x9f, 0x76, 0x7a, 0x90, 0x83, 0x73, 0x72, 0x86, 0x95, 0x79,
  0x77, 0x85, 0x75, 0x6a, 0x77, 0x82, 0x8c, 0x8d, 0x9a, 0xa1, 0x85, 0x5b,
  0x66, 0x6b, 0x63, 0x85, 0x9f, 0xac, 0xa2, 0x67, 0x6e, 0x6f, 0x59, 0x80,
  0x95, 0xa4, 0xa8, 0x66, 0x67, 0x7f, 0x58, 0x72, 0x92, 0xa0, 0xb8, 0x71,
  0x58, 0x82, 0x61, 0x6a, 0x8c, 0x8f, 0xb1, 0x89, 0x5d, 0x7d, 0x6e, 0x70,
  0x95, 0x8e, 0x9b, 0x88, 0x64, 0x7f, 0x78, 0x70, 0x94, 0x8d, 0x8a, 0x7f,
  0x63, 0x7d, 0x89, 0x85, 0x90, 0x7b, 0x79, 0x80, 0x61, 0x6e, 0x91, 0x9f,
  0xa1, 0x80, 0x74, 0x7b, 0x62, 0x68, 0x8c, 0x9e, 0x9a, 0x7d, 0x79, 0x77,
  0x62, 0x6c, 0x86, 0xa1, 0xa2, 0x79, 0x7e, 0x84, 0x66, 0x6a, 0x80, 0x9e,
  0x9c, 0x74, 0x79, 0x7f, 0x6e, 0x71, 0x8c, 0xa7, 0x97, 0x72, 0x7a, 0x79,
  0x6c, 0x68, 0x80, 0x9e, 0x93, 0x81, 0x84, 0x82, 0x74, 0x6e, 0x87, 0x91,
  0x7e, 0x7d, 0x84, 0x7d, 0x71, 0x70, 0x8d, 0x95, 0x7c, 0x85, 0x8f, 0x7c,
  0x6f, 0x7c, 0x8b, 0x81, 0x71, 0x76, 0x8c, 0x88, 0x78, 0x89, 0x96, 0x89,
  0x6f, 0x6b, 0x82, 0x7f, 0x78, 0x8c, 0x8f, 0x90, 0x74, 0x68, 0x89, 0x80,
  0x7c, 0x8a, 0x8b, 0x8d, 0x6c, 0x66, 0x85, 0x80, 0x88, 0x94, 0x91, 0x94,
  0x70, 0x65, 0x7b, 0x75, 0x7d, 0x81, 0x80, 0x80, 0x7f, 0x80, 0x81, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, 0x7f, 0x80, 0x7f,
  0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x80, 0x80,
  0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  
};

unsigned int sample_wav_len = sizeof(sample);
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


