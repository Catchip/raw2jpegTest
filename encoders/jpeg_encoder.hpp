#ifndef _JPEG_ENCODER_H
#define _JPEG_ENCODER_H

#include <iostream>

class jpeg_encoder{
	public:
		virtual double encode(char *strImageName, std::uint8_t *image_buffer, int image_height, int image_width, int quality) = 0;
};

#endif
