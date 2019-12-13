#include <iostream>
#include <string>

bool preveri(int num)
{
	//checks if it's ascending or same
	int tmp = num;
	int prevNum=num%10;

	while (tmp != 0)
	{
		if (tmp % 10 <= prevNum)
		{
			prevNum = tmp % 10;
			tmp /= 10;
		}
		else
			return false;
	}
	//check if adj
	tmp = num;
	bool checkAdj = false;
	//122223
	while (tmp != 0)
	{	
		prevNum = tmp % 10;
		tmp /= 10;
		if (tmp!=0&&prevNum == tmp % 10 && !checkAdj)
		{
			tmp /= 10;
			if (tmp == 0)
			{	
				checkAdj = true;
				break;
			}
			if (prevNum != tmp % 10)
			{
				checkAdj = true;
			}
			else
			{
				while (tmp % 10 == prevNum&&tmp!=0)
					tmp /= 10;
			}

		}
	}
	if(checkAdj)
		std::cout << num << std::endl;
		return (checkAdj);

}

int main() {
	//std::string vnos = "347312-805915";
	int spodnjaMeja = 347312;
	int zgornjaMeja = 805915;
	int steviloMogocih = 0;
	for (int i = spodnjaMeja; i < zgornjaMeja; i++)
	{
		if(preveri(i))
			steviloMogocih++;
	}
	std::cout << steviloMogocih<<std::endl;
}
