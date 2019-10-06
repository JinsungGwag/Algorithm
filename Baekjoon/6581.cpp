#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	int length = 0;

	string document = "";

	cin >> word;
	document += word;
	length += word.length();

	while(cin >> word)
	{
		if(word.compare("<br>") == 0)
		{
			document += "\n";
			length = 0;
			continue;
		}
		else if(word.compare("<hr>") == 0)
		{
			if(length == 0)
				document += "--------------------------------------------------------------------------------\n";
			else
			{
				document += "\n--------------------------------------------------------------------------------\n";
				length = 0;
			}

			continue;
		}

		if(length == 0)
		{
			document += word;
			length += word.length();
			continue;
		}

		length += (word.length() + 1);
		if(length > 80)
		{
			document += ("\n" + word);
			length = word.length();
		}
		else
			document += (" " + word);
	}

	cout << document;

	return 0;
}
