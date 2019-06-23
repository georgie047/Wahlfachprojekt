/*
 * keys.c
 *
 * Created: 7/14/2018 5:58:28 AM
 *  Author: pvallone
 */ 
 #include <asf.h>
 #include "keys.h"
/* ATCK88590_565*/
	 // keys ATCK88590_768

 #if defined(AT88CK590_768)
	uint8_t key00[16] = {0x63, 0x08, 0x60, 0x91, 0xe2, 0x64, 0x8f, 0x49, 0x0c, 0xe9, 0x80, 0x45, 0x38, 0xb5, 0x85, 0x3f};
	uint8_t key01[16] = {0x2a, 0x23, 0x1b, 0xbf, 0x11, 0x35, 0x73, 0x3d, 0xd2, 0x99, 0x9f, 0xc8, 0x36, 0x71, 0x38, 0xb2};
	uint8_t key02[16] = {0x2a, 0x23, 0x1b, 0xbf, 0x11, 0x35, 0x73, 0x3d, 0xd2, 0x99, 0x9f, 0xc8, 0x36, 0x71, 0x38, 0xb2};
	uint8_t key03[16] = {0x4D, 0x79, 0x53, 0x65, 0x63, 0x72, 0x65, 0x74, 0x6B, 0x65, 0x79, 0x32, 0x30, 0x31, 0x38, 0x40};
	uint8_t key04[16] = {0x08, 0xe6, 0xe6 ,0x93, 0x69, 0x4a, 0x4c, 0xd7 ,0x84, 0xf2, 0x09, 0xb6, 0x74, 0x6d, 0xea, 0x1e};
	uint8_t key05[16] = {0x08, 0xe6, 0xe6 ,0x93, 0x69, 0x4a, 0x4c, 0xd7 ,0x84, 0xf2, 0x09, 0xb6, 0x74, 0x6d, 0xea, 0x1e};
	uint8_t key06[16] = {0x66, 0x66, 0xD0, 0x45, 0x3A, 0xC2, 0x25, 0x57, 0xF6, 0xD4, 0x6B, 0x7D, 0xDF, 0x96, 0x89, 0xDA};
	uint8_t key07[16] = {0x77, 0x77, 0x2F, 0x4A, 0x9C, 0xC0, 0x5E, 0x45, 0x99, 0xBD, 0x26, 0x96, 0xDD, 0x49, 0xF8, 0xA5};
	uint8_t key08[16] = {0x88, 0x88, 0xC6, 0x2A, 0xFE, 0x1F, 0x82, 0xD4, 0xE0, 0x85, 0x85, 0x34, 0x4D, 0x77, 0xB8, 0x9D};
	uint8_t key09[16] = {0x99, 0x99, 0x4E, 0x6D, 0x4A, 0xF5, 0x92, 0x30, 0x6B, 0xD2, 0xD5, 0x27, 0x7D, 0x77, 0xB3, 0x95};
	uint8_t key10[16] = {0xAA, 0xAA, 0x15, 0xA2, 0x55, 0x0B, 0xD2, 0xEA, 0x9A, 0xF2, 0x96, 0x46, 0x15, 0x69, 0x11, 0x12};
	uint8_t key11[16] = {0xBB, 0xBB, 0x24, 0xDB, 0x78, 0xA8, 0x70, 0x64, 0xA1, 0xF0, 0x8D, 0xC9, 0x17, 0x96, 0x60, 0x0A};
	uint8_t key12[16] = {0xCC, 0xCC, 0xC6, 0x17, 0x1A, 0x52, 0x45, 0xAC, 0xD2, 0x92, 0x46, 0x28, 0x90, 0x62, 0x4C, 0xA5};
	uint8_t key13[16] = {0xDD, 0xDD, 0xBF, 0xAC, 0x11, 0x70, 0x55, 0x9C, 0xC9, 0xB6, 0x28, 0x0F, 0x92, 0x95, 0xDF, 0x30};
	uint8_t key14[16] = {0xEE, 0xEE, 0x08, 0x55, 0x77, 0xBD, 0xA7, 0xB8, 0xA7, 0xAF, 0x58, 0xD1, 0x8B, 0x92, 0xF0, 0xDF};
	uint8_t key15[16] = {0xEE, 0xEE, 0x08, 0x55, 0x77, 0xBD, 0xA7, 0xB8, 0xA7, 0xAF, 0x58, 0xD1, 0x8B, 0x92, 0xF0, 0xDF};
#elif defined(AT88CK590_732)	
	//uint8_t key00[16] = {0x63, 0x08, 0x60, 0x91, 0xe2, 0x64, 0x8f, 0x49, 0x0c, 0xe9, 0x80, 0x45, 0x38, 0xb5, 0x85, 0x3f};
	uint8_t key00[16] = {0xEE, 0xEE, 0x08, 0x55, 0x77, 0xBD, 0xA7, 0xB8, 0xA7, 0xAF, 0x58, 0xD1, 0x8B, 0x92, 0xF0, 0xDF};
	uint8_t key01[16] = {0x2a, 0x23, 0x1b, 0xbf, 0x11, 0x35, 0x73, 0x3d, 0xd2, 0x99, 0x9f, 0xc8, 0x36, 0x71, 0x38, 0xb2};
	uint8_t key02[16] = {0x2a, 0x23, 0x1b, 0xbf, 0x11, 0x35, 0x73, 0x3d, 0xd2, 0x99, 0x9f, 0xc8, 0x36, 0x71, 0x38, 0xb2};
	uint8_t key03[16] = {0x4D, 0x79, 0x53, 0x65, 0x63, 0x72, 0x65, 0x74, 0x6B, 0x65, 0x79, 0x32, 0x30, 0x31, 0x38, 0x40};
	uint8_t key04[16] = {0x08, 0xe6, 0xe6 ,0x93, 0x69, 0x4a, 0x4c, 0xd7 ,0x84, 0xf2, 0x09, 0xb6, 0x74, 0x6d, 0xea, 0x1e};
	uint8_t key05[16] = {0x08, 0xe6, 0xe6 ,0x93, 0x69, 0x4a, 0x4c, 0xd7 ,0x84, 0xf2, 0x09, 0xb6, 0x74, 0x6d, 0xea, 0x1e};
	uint8_t key06[16] = {0x66, 0x66, 0xD0, 0x45, 0x3A, 0xC2, 0x25, 0x57, 0xF6, 0xD4, 0x6B, 0x7D, 0xDF, 0x96, 0x89, 0xDA};
	uint8_t key07[16] = {0x77, 0x77, 0x2F, 0x4A, 0x9C, 0xC0, 0x5E, 0x45, 0x99, 0xBD, 0x26, 0x96, 0xDD, 0x49, 0xF8, 0xA5};
	uint8_t key08[16] = {0x88, 0x88, 0xC6, 0x2A, 0xFE, 0x1F, 0x82, 0xD4, 0xE0, 0x85, 0x85, 0x34, 0x4D, 0x77, 0xB8, 0x9D};
	uint8_t key09[16] = {0x99, 0x99, 0x4E, 0x6D, 0x4A, 0xF5, 0x92, 0x30, 0x6B, 0xD2, 0xD5, 0x27, 0x7D, 0x77, 0xB3, 0x95};
	uint8_t key10[16] = {0xAA, 0xAA, 0x15, 0xA2, 0x55, 0x0B, 0xD2, 0xEA, 0x9A, 0xF2, 0x96, 0x46, 0x15, 0x69, 0x11, 0x12};
	uint8_t key11[16] = {0xBB, 0xBB, 0x24, 0xDB, 0x78, 0xA8, 0x70, 0x64, 0xA1, 0xF0, 0x8D, 0xC9, 0x17, 0x96, 0x60, 0x0A};
	uint8_t key12[16] = {0xCC, 0xCC, 0xC6, 0x17, 0x1A, 0x52, 0x45, 0xAC, 0xD2, 0x92, 0x46, 0x28, 0x90, 0x62, 0x4C, 0xA5};
	uint8_t key13[16] = {0xDD, 0xDD, 0xBF, 0xAC, 0x11, 0x70, 0x55, 0x9C, 0xC9, 0xB6, 0x28, 0x0F, 0x92, 0x95, 0xDF, 0x30};
	uint8_t key14[16] = {0xEE, 0xEE, 0x08, 0x55, 0x77, 0xBD, 0xA7, 0xB8, 0xA7, 0xAF, 0x58, 0xD1, 0x8B, 0x92, 0xF0, 0xDF};
	uint8_t key15[16] = {0xEE, 0xEE, 0x08, 0x55, 0x77, 0xBD, 0xA7, 0xB8, 0xA7, 0xAF, 0x58, 0xD1, 0x8B, 0x92, 0xF0, 0xDF};

#elif defined(AT88CK590_565)
	uint8_t key00[16] = {0x63, 0x08, 0x60, 0x91, 0xe2, 0x64, 0x8f, 0x49, 0x0c, 0xe9, 0x80, 0x45, 0x38, 0xb5, 0x85, 0x3f};
	uint8_t key01[16] = {0x2a, 0x23, 0x1b, 0xbf, 0x11, 0x35, 0x73, 0x3d, 0xd2, 0x99, 0x9f, 0xc8, 0x36, 0x71, 0x38, 0xb2};
	uint8_t key02[16] = {0x4D, 0x79, 0x53, 0x65, 0x63, 0x72, 0x65, 0x74, 0x6B, 0x65, 0x79, 0x32, 0x30, 0x31, 0x38, 0x40};
	uint8_t key03[16] = {0x4D, 0x79, 0x53, 0x65, 0x63, 0x72, 0x65, 0x74, 0x6B, 0x65, 0x79, 0x32, 0x30, 0x31, 0x38, 0x40};
	uint8_t key04[16] = {0x08, 0xe6, 0xe6 ,0x93, 0x69, 0x4a, 0x4c, 0xd7 ,0x84, 0xf2, 0x09, 0xb6, 0x74, 0x6d, 0xea, 0x1e};
	uint8_t key05[16] = {0x08, 0xe6, 0xe6 ,0x93, 0x69, 0x4a, 0x4c, 0xd7 ,0x84, 0xf2, 0x09, 0xb6, 0x74, 0x6d, 0xea, 0x1e};
	uint8_t key06[16] = {0x66, 0x66, 0xD0, 0x45, 0x3A, 0xC2, 0x25, 0x57, 0xF6, 0xD4, 0x6B, 0x7D, 0xDF, 0x96, 0x89, 0xDA};
	uint8_t key07[16] = {0x77, 0x77, 0x2F, 0x4A, 0x9C, 0xC0, 0x5E, 0x45, 0x99, 0xBD, 0x26, 0x96, 0xDD, 0x49, 0xF8, 0xA5};
	uint8_t key08[16] = {0x88, 0x88, 0xC6, 0x2A, 0xFE, 0x1F, 0x82, 0xD4, 0xE0, 0x85, 0x85, 0x34, 0x4D, 0x77, 0xB8, 0x9D};
	uint8_t key09[16] = {0x99, 0x99, 0x4E, 0x6D, 0x4A, 0xF5, 0x92, 0x30, 0x6B, 0xD2, 0xD5, 0x27, 0x7D, 0x77, 0xB3, 0x95};
	uint8_t key10[16] = {0xAA, 0xAA, 0x15, 0xA2, 0x55, 0x0B, 0xD2, 0xEA, 0x9A, 0xF2, 0x96, 0x46, 0x15, 0x69, 0x11, 0x12};
	uint8_t key11[16] = {0xBB, 0xBB, 0x24, 0xDB, 0x78, 0xA8, 0x70, 0x64, 0xA1, 0xF0, 0x8D, 0xC9, 0x17, 0x96, 0x60, 0x0A};
	uint8_t key12[16] = {0xCC, 0xCC, 0xC6, 0x17, 0x1A, 0x52, 0x45, 0xAC, 0xD2, 0x92, 0x46, 0x28, 0x90, 0x62, 0x4C, 0xA5};
	uint8_t key13[16] = {0xDD, 0xDD, 0xBF, 0xAC, 0x11, 0x70, 0x55, 0x9C, 0xC9, 0xB6, 0x28, 0x0F, 0x92, 0x95, 0xDF, 0x30};
	uint8_t key14[16] = {0xEE, 0xEE, 0x08, 0x55, 0x77, 0xBD, 0xA7, 0xB8, 0xA7, 0xAF, 0x58, 0xD1, 0x8B, 0x92, 0xF0, 0xDF};
	uint8_t key15[16] = {0xEE, 0xEE, 0x08, 0x55, 0x77, 0xBD, 0xA7, 0xB8, 0xA7, 0xAF, 0x58, 0xD1, 0x8B, 0x92, 0xF0, 0xDF};

#else
# warning ("No Keys Defined")
#endif

  
uint8_t keyconfiguration[16][4] = {

	{0x04,0x00,0x00,0x00}, //key config 00
	{0x05,0x00,0x00,0x00}, //key config 01
	{0x01,0x00,0x00,0x00}, //key config 02
	{0xE9,0xD0,0x00,0x01}, //key config 03
	{0xE5,0xD0,0x00,0x01}, //key config 04
	{0xE1,0xD0,0x00,0x01}, //key config 05
	{0xE5,0xD0,0x00,0x01}, //key config 06
	{0xE1,0xD0,0x00,0x01}, //key config 07
	{0xE1,0xD0,0x00,0x01}, //key config 08
	{0xE1,0xD0,0x00,0x01}, //key config 09
	{0xE1,0xD0,0x00,0x01}, //key config 10
	{0xE1,0xD0,0x00,0x01}, //key config 11
	{0xE1,0xD0,0x00,0x01}, //key config 12
	{0xE1,0xD0,0x00,0x01}, //key config 13
	{0xED,0xD0,0x00,0x01}, //key config 14
	{0xE9,0xD0,0x00,0x00}  //key config 15
};
//User Zone Configurations 
uint8_t user_zone_configuration[16][4] = {

	{0x7C,0x00,0x00,0x55}, // User Zone 00
	{0x7C,0x00,0x00,0x55}, // User Zone 01
	{0x7C,0x00,0x00,0x55}, // User Zone 02
	{0x7C,0x00,0x00,0x55}, // User Zone 03
	{0x7C,0x00,0x00,0x55}, // User Zone 04
	{0x7C,0x00,0x00,0x55}, // User Zone 05
	{0x7C,0x00,0x00,0x55}, // User Zone 06
	{0x7C,0x00,0x00,0x55}, // User Zone 07
	{0x7C,0x00,0x00,0x55}, // User Zone 08
	{0x7C,0x00,0x00,0x55}, // User Zone 09
	{0x7C,0x00,0x00,0x55}, // User Zone 10
	{0x7C,0x00,0x00,0x55}, // User Zone 11
	{0x7C,0x00,0x00,0x55}, // User Zone 12
	{0x7C,0x00,0x00,0x55}, // User Zone 13
	{0x7C,0x00,0x00,0x55}, // User Zone 14
	{0x7C,0x00,0x00,0x55}  // User Zone 15
};

   
uint8_t counter_configuration[16][2] = {

	{0x01,0x00}, // Counter 00
	{0x01,0x00}, // Counter 01
	{0x01,0x00}, // Counter 02
	{0x01,0x00}, // Counter 03
	{0x01,0x00}, // Counter 04
	{0x01,0x00}, // Counter 05
	{0x01,0x00}, // Counter 06
	{0x01,0x00}, // Counter 07
	{0x01,0x00}, // Counter 08
	{0x01,0x00}, // Counter 09
	{0x01,0x00}, // Counter 10
	{0x01,0x00}, // Counter 11
	{0x01,0x00}, // Counter 12
	{0x01,0x00}, // Counter 13
	{0x01,0x00}, // Counter 14
	{0x01,0x00}, // Counter 15
	   
};
