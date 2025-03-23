#include<iostream>
#include<fstream>
using namespace std;
/*P3			//ppm�ļ���һ�ָ�ʽ
  2 2			//����
  255			//��ɫ�ķ�Χ��һ����255
  255   0   0   //����[0]
  255 255   0	//����[1]
  0	  255   0	//����[2]
  0		0 255	//����[3]
*/
int main() {
	int image_width = 256;
	int image_height = 256;
	fstream ofs;
	ofs.open("./1.ppm", ios::out);
	ofs << "P3\n" << image_width << " " << image_height << "\n255\n";
	cout << "P3\n" << image_width << " " << image_height << "\n255\n";
	for (int j = 0; j < image_height; j++) {
		clog << "\rScanlines remaining:" << (image_height - j) << " " << flush;
		for (int i = 0; i < image_width;i++) {
			auto r = double(i) / (image_width - 1);
			auto g = double(j) / (image_height - 1);
			auto b = 0;
			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);
			ofs << ir << " " << ig << " " << ib << endl;
			cout << ir << " " << ig << " " << ib << endl;
		}
	}
	ofs.close();
	clog << "\nDone.   \n";
}