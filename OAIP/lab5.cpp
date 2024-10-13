
	#include <iostream>
		int main()
		{
			using namespace std;
			int a[20][20], i, j, n, m;
			int max = 0, min = 32000, jmin, imax;
			cout << "vvedi n:=";
			cin >> n;
			cout << "vvedi m:=";
			cin >> m;
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
				{
					cout << "i : " << i << " j : "<< j<<endl
						;
					cin >> a[i][j];
				}

			//workload
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
				{
					if (a[i][j] < min)
					{
						min = a[i][j];
						jmin = j;//поиск меньшего в строках и запоминание его номер столбца в jmin
					}
					if (j == m-1 )//когда строка равна конечной
					{
						for (int k = 0; k < m; k++)//создаем цикл для минимальных 
							if (a[k][jmin] > max)
							{
								max = a[k][jmin];
								imax = k;//и сравниваем их с остальными в столбце
							}
						if (max == min)
							cout << a[imax][jmin] << endl;//вывод
					}
				}
			return 0;
		}