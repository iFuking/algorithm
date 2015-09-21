#include <iostream>
#include <fstream>
using namespace std;

const int start_index = 100001;
const int end_index = 250000;

//int main(int argc, char *argv[])
//{
//	ofstream dout(argv[1]);
//	for (int i = start_index; i <= end_index; i++)
//	{
//		dout << "E:\\zju\\bigdata-contest\\fv_sclothes\\sift.exe ";
//		dout << "E:\\zju\\contest_data\\clothes\\clothes_image\\clothes_" << i << ".jpg ";
//		dout << "E:\\zju\\bigdata-contest\\fv_iclothes\\clothes_"  << i << ".txt" << endl;
//	}
//	dout.close();
//	return 0;
//}


int main(int argc, char *argv[])
{
	ofstream foo(argv[1]);
	for (int i = start_index; i <= end_index; i++)
	{
		foo << "E:\\zju\\bigdata-contest\\fv_sclothes\\fv_match.exe ";
		foo << "E:\\zju\\bigdata-contest\\fv_sclothes\\d1.txt ";
		foo << "E:\\zju\\bigdata-contest\\fv_iclothes\\clothes_" << i << ".txt ";
		foo << "0.5 ";
		foo << "E:\\zju\\bigdata-contest\\fv_sclothes\\res_d2.txt" << endl;
	}
	return 0;
}