#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
vector<string> words;
vector<string> selectedWords;
vector<int> selectedIndex;
fstream file;

int RandomNumber(int minDeger, int maxDeger)
{
	int RandomNumber = rand() % (maxDeger - minDeger + 1) + minDeger;

	return RandomNumber;
}
template <typename T>
int IndexOf(vector<T> arananyer, T aranandeger)
{
	for (int i = 0; i < arananyer.size(); i++)
	{
		if (arananyer[i] == aranandeger)
		{
			return i;
		}
	}
	return -1;
}
template <typename T>
bool IcindeVarMi(vector<T> arananyer, T aranandeger)
{
	return IndexOf(arananyer, aranandeger) != -1;
}

int main()
{
	srand(time(0));
	file.open("TextFile.txt", ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			words.push_back(line);
		}
		file.close();
	}
	while (true)
	{
		int i = 0;
		while (i < 5)
		{
			int randomIndex = RandomNumber(1, words.size()) - 1;
			if (IcindeVarMi(selectedIndex, randomIndex))
			{
				continue;
			}
			selectedIndex.push_back(randomIndex);
			selectedWords.push_back(words[randomIndex]);
			i++;
		}
		string birlesikKelime;
		for (auto selected : selectedWords)
		{
			birlesikKelime += selected;
		}

		string karistirilmisKelime;
		int kelimeuzunlugu = birlesikKelime.size();
		for (int i = 0; i < kelimeuzunlugu; i++)
		{
			char harf;
			int rastgelesayi = RandomNumber(0, birlesikKelime.size() - 1);
			harf = birlesikKelime[rastgelesayi];
			karistirilmisKelime += harf;
			birlesikKelime.erase(rastgelesayi, 1);
		}
		while (true)
		{
			cout << "" << endl;
			cout << "-----------------------------------" << endl;
			cout << "        GUESS THE WORDS            " << endl;
			cout << "-----------------------------------" << endl;
			cout << "" << endl;
			cout << "h for hint" << endl;
			cout << "r for restart" << endl;
			cout << "q for quit" << endl;
			cout << "" << endl;
			cout << karistirilmisKelime << endl;
			cout << "" << endl;
			cout << "Your Answer:";
			string cevap;
			cin >> cevap;
			if (cevap == "q")
			{
				return 0;
			}
			if (cevap == "r")
			{
				selectedWords.clear();
				selectedIndex.clear();
				break;
			}
			if (cevap == "h")
			{
				int sayininyeri = RandomNumber(0, selectedWords.size() - 1);
				string secilenkelime = selectedWords[sayininyeri];
				cout << sayininyeri << ". Sayinin ilk harfi:" << secilenkelime[0] << endl;
				continue;
			}
			int karistirilmisKelimeuzunlugu = karistirilmisKelime.size();
			int bulunanIndex = IndexOf(selectedWords, cevap);
			if (bulunanIndex != -1)
			{
				selectedWords.erase(selectedWords.begin() + bulunanIndex);
				for (int j = 0, k = 0; j < cevap.size(); k++)
				{
					if (karistirilmisKelime[k] == cevap[j])
					{
						karistirilmisKelime.erase(k, 1);
						k = -1;
						j++;
					}
				}
				if (karistirilmisKelime.size() != 0)
				{
					cout << "Bildin !" << endl;
					continue;
				}
				if (karistirilmisKelime.size() == 0)
				{
					cout << "Hepsini Bildin!" << endl;
					cout << "Yeni bir oyun icin herhangi bir tusa, cikmak icin 'q'ya basiniz." << endl;
					string karar;
					cin >> karar;
					if (karar == "q")
					{
						return 0;
					}
					break;
				}
				continue;
			}
			cout << "Yanlis Cevap!" << endl;
		} //while(true)
	} //while(true)
} // int main
