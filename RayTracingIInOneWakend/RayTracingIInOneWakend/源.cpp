#include<iostream>
#include<fstream>
using namespace std;
/*P3			//ppm文件的一种格式
  2 2			//列行
  255			//颜色的范围，一般是255
  255   0   0   //数组[0]
  255 255   0	//数组[1]
  0	  255   0	//数组[2]
  0		0 255	//数组[3]
*/
int main() {
	int width = 256;
	int height = 256;
	fstream ofs;
	ofs.open("./1.ppm", ios::out);
	ofs << "P3\n" << width << " " << height << "\n255\n";
	cout << "P3\n" << width << " " << height << "\n255\n";
	for (int j = 0; j < height; ++j) {
		cerr << "\rScanlines remaining: " << j << ' ' << flush;
		for (int i = 0; i < width; ++i) {
			auto r = double(i) / (width - 1);
			auto g = double(j) / (height - 1);
			auto b = 0;
			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);
			ofs << ir << " " << ig << " " << ib << endl;
			cout << ir << " " << ig << " " << ib << endl;
		}
	}
	ofs.close();
	cerr << "\nDone.\n";
}