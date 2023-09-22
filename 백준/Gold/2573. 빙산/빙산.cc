#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, Input;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

typedef struct FIce
{
	int PosY, PosX;
	int OldZeroCount;
	int NewZeroCount;
	int Amount;

	FIce(int NewPosY, int NewPosX, int NewAmount) : PosY(NewPosY), PosX(NewPosX), OldZeroCount(0), NewZeroCount(0), Amount(NewAmount) {}
} FIce;

class AIceberg
{
public:
	AIceberg(int NewY, int NewX) : Visited(), MeltYear(0), Y(NewY), X(NewX)
	{
		IceBoard = new FIce**[Y];
		for (int i = 0; i < Y; ++i)
		{
			IceBoard[i] = new FIce*[X];
			for (int j = 0; j < X; ++j)
			{
				cin >> Input;
				IceBoard[i][j] = new FIce(i, j, Input);
			}
		}
	}

	~AIceberg()
	{
		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				delete IceBoard[i][j];
			}
			delete[] IceBoard[i];
		}
		delete[] IceBoard;
	}

	void Init()
	{
		int ZeroCount;
		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				if (IceBoard[i][j]->Amount == 0) continue;
				RemainIceVector.push_back(IceBoard[i][j]);
				ZeroCount = 0;
				// 4방향에 0이 얼마나 있는지 체크
				for (int k = 0; k < 4; ++k)
				{
					int NextY = i + dy[k];
					int NextX = j + dx[k];
					if (NextY < 0 || NextY >= Y || NextX < 0 || NextX >= X) continue;

					if (IceBoard[NextY][NextX]->Amount == 0) IceBoard[i][j]->OldZeroCount++;
				}
				IceBoard[i][j]->NewZeroCount = IceBoard[i][j]->OldZeroCount;
			}
		}
	}

	void Melt()
	{
		//Print();

		while (DetectIsDevided() == false)
		{
			if (RemainIceVector.size() == 0)
			{
				cout << 0 << '\n';
				return;
			}
			MeltYear++;
			for (int i = 0; i < RemainIceVector.size();)
			{
				RemainIceVector[i]->Amount -= RemainIceVector[i]->OldZeroCount;
				if (RemainIceVector[i]->Amount <= 0)
				{
					RemainIceVector[i]->Amount = 0;
					RemainIceVector[i]->OldZeroCount = 0;

					for (int k = 0; k < 4; ++k)
					{
						int NextY = RemainIceVector[i]->PosY + dy[k];
						int NextX = RemainIceVector[i]->PosX + dx[k];
						if (NextY < 0 || NextY >= Y || NextX < 0 || NextX >= X) continue;

						if (IceBoard[NextY][NextX]->Amount > 0)
						{
							//cout << "NewZeroCount From {" << RemainIceVector[i]->PosX << ", " << RemainIceVector[i]->PosY << "} to {" << NextX << ", " << NextY << "}\n";
							IceBoard[NextY][NextX]->NewZeroCount++;
						}
					}

					RemainIceVector.erase(RemainIceVector.begin() + i);
				}
				else
				{
					i++;
				}
			}

			for (int i = 0; i < RemainIceVector.size(); ++i)
			{
				RemainIceVector[i]->OldZeroCount = RemainIceVector[i]->NewZeroCount;
			}

			//Print();
		}

		cout << MeltYear << '\n';
	}

	bool DetectIsDevided()
	{
		if (RemainIceVector.size() == 0) return false;
		for (int i = 0; i < Y; ++i)
		{
			fill(Visited[i], Visited[i] + X, false);
		}

		pair<int, int> Current;
		int VisitCount = 0;
		queue<pair<int, int>> Queue;
		Queue.push({ RemainIceVector[0]->PosX , RemainIceVector[0]->PosY });
		while (Queue.empty() == false)
		{
			Current = Queue.front(); Queue.pop();
			if (Visited[Current.second][Current.first] == true) continue;
			VisitCount++;
			Visited[Current.second][Current.first] = true;

			for (int k = 0; k < 4; ++k)
			{
				int NextY = Current.second + dy[k];
				int NextX = Current.first + dx[k];
				if (NextY < 0 || NextY >= Y || NextX < 0 || NextX >= X) continue;

				if (IceBoard[NextY][NextX]->Amount > 0)
				{
					Queue.push({ NextX, NextY });
				}
			}
		}

		//cout << VisitCount << " : " << RemainIceVector.size() << '\n';

		return VisitCount != RemainIceVector.size();
	}

	void Print()
	{
		cout << '\n';
		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				cout << IceBoard[i][j]->Amount << ' ';
			}
			cout << '\n';
		}
		cout << '\n';

		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				cout << IceBoard[i][j]->OldZeroCount << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
private:
	int MeltYear;
	bool Visited[300][300];
	int Y, X;
	FIce*** IceBoard;
	vector<FIce*> RemainIceVector;
};

int main()
{
	cin >> N >> M;

	AIceberg* Iceberg = new AIceberg(N, M);

	Iceberg->Init();
	Iceberg->Melt();

	delete Iceberg;

	return 0;
}