#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string str1, str2;
	string push_string = "";
	bool alpha_flag = true;

	vector<string> str1_split;
	vector<string> str2_split;
	vector<string> gyo;

	getline(cin, str1);
	getline(cin, str2);

	for (int i = 0; i < str1.length() - 1; i++)
	{
		push_string = str1.substr(i,2);

		for (int j = 0; j < push_string.length(); j++)
		{
			if ((push_string[j] >= 65 && push_string[j] <= 90) || (push_string[j] >= 97 && push_string[j] <= 122))
				continue;
			else
				alpha_flag = false;
		}

		if (alpha_flag)
		{
			transform(push_string.begin(), push_string.end(), push_string.begin(), tolower);
			str1_split.push_back(push_string);
		}

		alpha_flag = true;
	}

	alpha_flag = true;

	for (int i = 0; i < str2.length() - 1; i++)
	{
		push_string = str2.substr(i, 2);

		for (int j = 0; j < push_string.length(); j++)
		{
			if ((push_string[j] >= 65 && push_string[j] <= 90) || (push_string[j] >= 97 && push_string[j] <= 122))
				continue;
			else
				alpha_flag = false;
		}
		
		if(alpha_flag)
		{
			transform(push_string.begin(), push_string.end(), push_string.begin(), tolower);
			str2_split.push_back(push_string);
		}

		alpha_flag = true;
	}

	for (int i = 0; i < str1_split.size(); i++)
	{
		for (int j = 0; j < str2_split.size(); j++)
		{
			if (str1_split[i] == str2_split[j])
			{
				gyo.push_back(str1_split[i]);
				break;
			}
		}
	}

	int hap_size = gyo.size() + (str1_split.size() - gyo.size()) + (str2_split.size() - gyo.size());

	//for (int i = 0; i < gyo.size(); i++)
	//	cout << gyo[i] << endl;

	if (gyo.size() == 0 && hap_size == 0)
		cout << 65536 * 1 << endl;
	else
		cout << 65536 * gyo.size() / hap_size << endl;

	return 0;
}