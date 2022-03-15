#include<opencv2/opencv.hpp>
#include<easyx.h>
using namespace cv;
void color2Gray(IMAGE* src);
int main() {
	//定义图片对象
	initgraph(650,433,EW_SHOWCONSOLE);
	IMAGE image;
	loadimage(&image, "C:/Users/Wang/Desktop/ROSE/123/1.jpg",140,80);
	color2Gray(&image);
	putimage(0, 0, &image);

	const char* str = "@#$%^&*. ,-  ";
	int len = strlen(str);
	DWORD* pbuf = GetImageBuffer(&image);
	for (size_t i = 0; i < image.getwidth() * image.getheight(); i++) {
		float grayVal = (uchar)pbuf[i];
		int index = grayVal / 255.0 * len;
		if (i % 140== 0) {
			printf("\n");
		}
		printf("%c", str[index]);
		
	}


	/*//Mat img = imread("C:\\Users\\Wang\\Desktop\\ROSE\\123\\ROSE.jpg",ImreadModes::IMREAD_ANYCOLOR);
	//颜色空间
	//显示图片
	//namedWindow("rose", WindowFlags::WINDOW_NORMAL);
	//imshow("rose", img);*/
	getchar();
	return 0;

}
void color2Gray(IMAGE* src) {
	DWORD* pbuf = GetImageBuffer(src);
	int srcw = src->getwidth();
	int srch = src->getheight();
	for (size_t i = 0; i < srch*srch; i++) {
			DWORD color = pbuf[i];
			uchar r = (uchar)color;
			uchar g = (uchar)(color >> 8);
			uchar b = (uchar)(color >> 16);
			uchar a = (uchar)(color >> 24);
			//像素平均值
			int avg = (r + g + b + a) / 4;
			pbuf[i] = RGB(avg, avg, avg);
	}
}