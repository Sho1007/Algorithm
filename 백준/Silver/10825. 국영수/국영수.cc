#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Student
{
	string Name;
	int KoreanScore;
	int EnglishScore;
	int MathScore;

	Student(string NewName, int NewKoreanScore, int NewEnglishScore, int NewMathScore)
		: Name(NewName), KoreanScore(NewKoreanScore), EnglishScore(NewEnglishScore), MathScore(NewMathScore) {}
} Student;

int N;
string Name;
int Korean, English, Math;
vector<Student> Vector;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	while (N-- > 0)
	{
		cin >> Name >> Korean >> English >> Math;
		Vector.push_back(Student(Name, Korean, English, Math));
	}

	sort(Vector.begin(), Vector.end(), [](Student& A, Student& B)->bool {
		if (A.KoreanScore == B.KoreanScore)
		{
			if (A.EnglishScore == B.EnglishScore)
			{
				if (A.MathScore == B.MathScore)
				{
					return A.Name < B.Name;
				}

				return A.MathScore > B.MathScore;
			}

			return A.EnglishScore < B.EnglishScore;
		}

		return A.KoreanScore > B.KoreanScore;
		});

	for (int i = 0; i < Vector.size(); ++i)
	{
		cout << Vector[i].Name << '\n';
	}

	return 0;
}