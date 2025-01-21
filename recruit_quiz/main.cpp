#include "question.h"
#include "exam_mathematics.h"
#include "exam_japanese.h"
#include "exam_english.h"
#include "exam_geography.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;



int main()
{
	// 教科データ配列
	static const struct
	{
		const char* name;        // 教科名
		QuestionList(*create)(); // 問題作成関数のアドレス

	}
	subjectData[] =
	{
{ "数学", CreateMathematicsExam },
{ "国語", CreateJapaneseExam },
{ "英語", CreateEnglishExam },
//{ "物理", CreatePhysicsExam },
//{ "地理", CreateGeographyExam },
//{ "政治", CreatePoliticsExam },
//{ "経済", CreateEconomicsExam },
	};


	vector<Question> questions(3);

	cout << "[リクルート試験対策クイズ]\n";

	cout << "教科を選んでください\n";
	for (int i = 0; i < size(subjectData); i++)
	{
		cout << i + 1 << '=' << subjectData[i].name << '\n';
	}

	int subject;
	cin >> subject;

	if (subject > 0 && subject <= size(subjectData))
	{
		questions = subjectData[subject - 1].create();
	}

	for (const auto& e : questions)
	{
		cout << e.q << "\n";

		string answer;
		cin >> answer;

		if (answer == e.a)
		{
			cout << "正解!\n";
		}
		else
		{
			cout << "間違い!正解は" << e.a << "\n";
		}
	}//for questions
}