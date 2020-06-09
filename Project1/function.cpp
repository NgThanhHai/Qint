#include "function.h"

//Cộng 2 mảng nhị phân
void Add(char bits1[], char bits2[], char result[])
{

	int mark = 0;
	for (int i = 0; i < 128; i++)
	{
		int sumBit = bits1[i] + bits2[i] + mark;

		result[i] = sumBit % 2;
		mark = sumBit / 2;
	}
}

//Trừ 2 mảng nhị phân
void Sub(char bits1[], char bits2[], char result[])
{
	char temp[128] = { 0 };
	ConvertTwoComplement(bits2, temp);
	Add(bits1, temp, result);
}

//Chuyển số bù 2
void ConvertTwoComplement(char bitsSource[], char bitsDes[])
{
	for (int i = 0; i < 128; i++)
	{
		if (bitsSource[i] == 0)
			bitsDes[i] = 1;
		else if (bitsSource[i] == 1)
			bitsDes[i] = 0;
	}
	char temp[128] = { 0 }; temp[0] = { 1 };
	Add(bitsDes, temp, bitsDes);
}

//Dịch các phần tử trên mảng sang phải k vị trí
void DichPhaiTrenMang(char arrSource[], char arrDes[], int k)
{

	int pos = 0;
	while (pos + k < 128)
	{
		arrDes[pos + k] = arrSource[pos];
		pos++;
	}

}

//Dịch trái các phần tử trên mảng sang trái k vị trí
void DichTraiTrenMang(char arrSource[], char arrDes[], int k)// đối với bit dấu 127 là 0
{
	int pos = 127;
	while (pos - k >= 0)
	{
		arrDes[pos - k] = arrSource[pos];
		pos--;
	}
}

//Cắt chuỗi 
vector<string> Parse(string line, string seperator)
{
	vector<string> tokens;

	int startPos = 0;
	
	size_t foundPos = line.find(seperator, startPos);

	while (foundPos != string::npos)
	{
		int count = foundPos - startPos;
		string token = line.substr(startPos, count);

		tokens.push_back(token);
		startPos = foundPos + seperator.length();
		foundPos = line.find(seperator, startPos);
	}

	int count = line.length() - startPos;
	string token = line.substr(startPos, count);
	tokens.push_back(token);

	return tokens;
}

//Chia chuỗi số hệ 10 cho 2
string Div2(string s)
{
	string result;

	int digits = 0;

	if (s.length() == 0 || s.length() == 1)
	{
		digits = s[0] - 48;
		result += (digits / 2) + 48;
	}
	else
	{
		
		digits = s[0] - 48; // Lấy ra chữ số đầu tiên

		for (int i = 0; i < s.length() - 1; i++)
		{
			if (digits < 2) //Số chia tạm thời chưa >2 thì lấy thêm chữ số kế tiếp
			{
				i++;
				digits = (digits * 10) + (s[i] - 48);

			}
			char c = (digits / 2) + 48; //Chữ số thương
			result += c;
			digits = digits % 2; //Phần dư tiếp tục tham gia phép chia
			i--;
		}
	}
	s = result;

	return s;

}

//Tính chuỗi số mũ của 2
string MyPow(int n) //n là số mũ
{
	string result = "2";

	if (n == 0) //2^0
		return "1";
	if (n == 1) //2^1
		return "2";

	for (int i = 0; i < n - 1; i++)
		result = Mulp2(result);

	return result;
}

//Nhân chuỗi số hệ 10 với 2
string Mulp2(string s)
{
	int digit = 0, mark = 0;
	int sLength = s.length();
	int aSize = sLength + 1;
	int* a = new int[sLength + 1];

	string result;

	for (int i = 0; i < aSize; i++)
		a[i] = 0;

	for (int i = sLength - 1; i >= 0; i--)
	{
		digit = (s[i] - '0') * 2;
		if (mark == 1)
			digit++;
		if (digit > 9)
			mark = 1;
		else
			mark = 0;
		a[i + 1] += digit % 10;

	}

	int startPos = 1;

	if (mark == 1)
	{
		a[0] = 1;
		startPos = 0;
	}
	
	for (int i = startPos; i < aSize; i++)
	{
		result += (a[i] + '0');
	}
	delete[] a;

	return result;
}

//Cộng hai chuỗi số hệ 10
string AddStr(string a, string b)
{
	string result;

	int i = a.length() - 1;
	int j = b.length() - 1;
	int mark = 0;

	while (i >= 0 && j >= 0) //Cộng các chữ số a,b với nhau
	{
		int temp = (a[i] - 48) + (b[j] - 48) + mark;

		char c = (temp % 10) + 48;
		result += c;

		if (temp > 9)
			mark = 1;
		else
			mark = 0;
		
		i--;
		j--;
	}

	// a nhiều chữ số hơn b
	while (i >= 0)
	{
		int temp = (a[i] - 48) + mark;
		char c = (temp % 10) + 48;
		result += c;

		if (temp > 9)
			mark = 1;
		else
			mark = 0;
		
		i--;
	}

	// b nhiều chữ số hơn a
	while (j >= 0)
	{
		int temp = (b[j] - 48) + mark;
		char c = (temp % 10) + 48;
		result += c;

		if (temp > 9)
			mark = 1;
		else
			mark = 0;
		
		j--;
	}

	// Nếu sau khi cộng xong mà vẫn còn nhớ 1 thì ghi thêm 1 vào kết quả
	if (mark == 1)
		result += "1";

	reverse(result.begin(), result.end()); //Vì kết quả lưu ngược nên phải đảo chuỗi cho đúng 

	return result;
}