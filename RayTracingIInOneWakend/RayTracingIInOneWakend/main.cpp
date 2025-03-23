#include"color.h"
#include"vec3.h"
#include<iostream>
#include<fstream>
/*P3			//ppm文件的一种格式
  2 2			//列行
  255			//颜色的范围，一般是255
  255   0   0   //数组[0]
  255 255   0	//数组[1]
  0	  255   0	//数组[2]
  0		0 255	//数组[3]
*/
int main() {
	int image_width = 256;
	int image_height = 256;
	std::fstream ofs;
	ofs.open("./1.ppm", std::ios::out);
	ofs << "P3\n" << image_width << " " << image_height << "\n255\n";
	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
	for (int j = 0; j < image_height; j++) {
		std::clog << "\rScanlines remaining:" << (image_height - j) << " " << std::flush;
		for (int i = 0; i < image_width;i++) {
			auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0);
			write_color(std::cout, pixel_color); // out fof console
			write_color(ofs, pixel_color);        // out fof file
		}
	}
	ofs.close();
	std::clog << "\nDone.   \n";
}