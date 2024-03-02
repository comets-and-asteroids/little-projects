// ПарадоксMontyholla.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Условие оригинальной задачи: Есть три двери за одной из них клад, ты выбираешь одну, потом организатор открывает другую ПУСТУЮ дверь и предлогает тебе поменять свое решение. 
// Имеет ли смысл это делать? Какие шансы на выйгрыш при смене двери, какие без смены ?
// Условие измененнной задачи: Есть N дверей, за одной из них клад, тебе предлагают выбрать одну из них, после выбора организатор открывает K пустых дверей, и предлогает тебе поменять решение на любую из других. Каковы у тебя шансы на выйгрышь при смене двери, без смены?
// 3 <= N <= 10000, K <= n - 2
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

int main()
{
	// случайный рандом
	srand(time(0));
	//просто цикл чтоб не перезапускать программу
	while (true) {
		int N, K; // N - Количество дверей, K - количество ОТКРЫТЫХ дверей 
		cout << "Print count of doors and how many doors organisator open" << endl;
		cin >> N >> K;
		if (N == -1 || K == -1) { // для выхода из бесконечного цикла
			exit(0);
		}

		if (N < K + 2) continue; // Если условия некорректно  (N не может  быть больше M меньше чем на 2)
		int winByChange = 0; // счетчик побед со сменой двери
		int winByRand = 0; // счетчик побед без смены двери
		
		for (int i = 0; i < 10000; i++) // Случайные операции
		{
			vector<string>doors(N, "");
			doors[rand() % N] = "GOLD"; // дверь с золотом
			doors[rand() % N] += "CHOICE"; // дверь без золота
			if (find(doors.begin(), doors.end(), "GOLDCHOICE") != doors.end())winByRand++; // если совпали добавить во второй счетчик побед
			int tempK = K; // временая k
			int j = 0; 
			while (tempK > 0) {
				
				if (j == doors.size()) { // если не все двери открыты но уже закончились 
					cout << "IMPOSSIBLE SITUATION!!!";
					exit(-1);
				}

				if (doors[j] == "") { // если дверь не открыта открыть
					doors[j] = "OPEND";
					tempK--;
				}
				j++;
			}
			vector<string> unopend;
			for (int k = 0; k < N; k++) {
				if (doors[k] != "OPEND" && doors[k] != "CHOICE" && doors[k] != "GOLDCHOICE") { // если не открыта и не выбрана
					unopend.push_back(doors[k]);
				}
			}
			if (unopend.size() == 0) { // если нет неоткрытых дверей (противоречет логике)
				cout << "WARNING!!!\n";
			}
			if (unopend[rand() % unopend.size()] == "GOLD") { // выбираем случайную неоткрытую дверь
				winByChange++;
			}
		}
		cout << double(winByChange) / 10000 << "- change\n";
		cout << double(winByRand) / 10000 << "- no change\n";
	}
}
