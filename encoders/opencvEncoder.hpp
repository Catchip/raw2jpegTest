#include "jpeg_encoder.hpp"
class opencvEncoder:public jpeg_encoder{
	public:
		double encode(char *strImageName, std::uint8_t *image_buffer, int image_height, int image_width, int quality) override;

};
